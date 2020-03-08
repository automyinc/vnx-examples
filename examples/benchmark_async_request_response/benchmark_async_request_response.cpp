
#include <example/User.hxx>
#include <example/DatabaseAsyncClient.hxx>

#include <vnx/Config.h>
#include <vnx/Process.h>
#include <vnx/Proxy.h>

using namespace std::placeholders;


class TestModule : public vnx::Module {
public:
	int max_num_pending = 100;
	
	TestModule(const std::string& service_name)
		:	Module("TestModule")
	{
		client = std::make_shared<example::DatabaseAsyncClient>(service_name);
	}
	
protected:
	void main() override {
		
		set_timer_millis(500, std::bind(&TestModule::execute_requests, this));
		
		set_timer_millis(1000, std::bind(&TestModule::print_stats, this));
		
		add_async_client(client);
		
		client->vnx_set_error_callback(std::bind(&TestModule::error_callback, this, _1, _2));
		
		client->add_user(user_name, std::bind(&TestModule::add_user_callback, this, user_name));
		
		Module::main();
		
		rem_async_client(client);	// optional
	}
	
	void execute_requests() {
		if(!user_added) {
			return;
		}
		while(client->vnx_get_num_pending() < size_t(max_num_pending)) {
			client->get_user_balance(user_name, std::bind(&TestModule::get_user_balance_callback, this, _1, user_name));
		}
	}
	
	void add_user_callback(const std::string& user_name) {
		log(INFO).out << "User " << user_name << " successfully added.";
		user_added = true;
		execute_requests();
	}
	
	void get_user_balance_callback(vnx::float64_t balance, const std::string& user_name) {
		if(success_counter == 0) {
			log(INFO).out << "User balance: " << balance;
		}
		execute_requests();
		success_counter++;
	}
	
	void error_callback(uint64_t request_id, const std::exception& ex) {
		log(WARN).out << "Request " << request_id << " failed with: " << ex.what();
		if(!user_added) {
			log(ERROR).out << "Failed to add user!";
		}
		error_counter++;
	}
	
	void print_stats() {
		log(INFO).out << success_counter << " req/s, " << error_counter << " errors";
		success_counter = 0;
	}
	
private:
	vnx::Hash64 get_type_hash() const override { return vnx::Hash64(get_type_name()); }
	const char* get_type_name() const override { return "TestModule"; }
	
	void read(std::istream& _in) override {}
	void write(std::ostream& _out) const override {}
	
	void accept(vnx::Visitor& _visitor) const override {}
	
	void handle_switch(std::shared_ptr<const vnx::Sample> sample) override {}
	
	bool call_switch(vnx::TypeInput& in, vnx::TypeOutput& out, const vnx::TypeCode* call_type, const vnx::TypeCode* return_type) override {
		return false;
	}
	
private:
	std::shared_ptr<example::DatabaseAsyncClient> client;
	
	bool user_added = false;
	std::string user_name = "test_user";
	
	uint64_t success_counter = 0;
	uint64_t error_counter = 0;
	
};


int main(int argc, char** argv) {
	
	std::map<std::string, std::string> options;
	options["n"] = "node";
	options["node"] = "server url";
	
	vnx::init("benchmark_request_response", argc, argv, options);
	
	/*
	 * By default we try to connect over a local UNIX socket.
	 */
	std::string node = "database_server.sock";
	vnx::read_config("node", node);
	
	{
		// Create a Proxy to connect to the database process
		vnx::Handle<vnx::Proxy> proxy = new vnx::Proxy("Proxy", vnx::Endpoint::from_url(node));
		
		// Tell the Proxy to forward requests to service "Database"
		proxy->forward_list.push_back("Database");
		
		// Proxy needs to be started before trying to access the forwarded service
		proxy.start_detached();
	}
	
	/*
	 * Create and start our module.
	 */
	vnx::Handle<TestModule> module = new TestModule("Database");
	
	module.start_detached();
	
	vnx::wait();
	
}


