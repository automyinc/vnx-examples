
#include <example/FileServerAsyncClient.hxx>

#include <vnx/Config.h>
#include <vnx/Process.h>
#include <vnx/Proxy.h>
#include <vnx/Module.h>

using namespace std::placeholders;


class TestModule : public vnx::Module {
public:
	std::string service_name;
	int max_num_pending = 100;
	
	TestModule(const std::string& _vnx_name)
		:	Module(_vnx_name)
	{
	}
	
protected:
	void main() override
	{
		set_timer_millis(500, std::bind(&TestModule::execute_requests, this));
		set_timer_millis(1000, std::bind(&TestModule::print_stats, this));
		
		client = std::make_shared<example::FileServerAsyncClient>(service_name);
		client->vnx_set_error_callback(std::bind(&TestModule::error_callback, this, _1, _2));
		add_async_client(client);
		
		Module::main();
		
		rem_async_client(client);	// optional
	}
	
	void execute_requests() {
		try {
			while(client->vnx_get_num_pending() < size_t(max_num_pending))
			{
				const auto file_name = "data/file" + std::to_string(file_counter % 10000);
				client->get_file(file_name, std::bind(&TestModule::get_file_callback, this, _1, file_name));
				file_counter++;
			}
		} catch(const std::exception& ex) {
			log(WARN).out << ex.what();
		}
	}
	
	void get_file_callback(std::shared_ptr<const example::File> file, const std::string& file_name)
	{
		if(success_counter == 0) {
			log(DEBUG).out << "File: name='" << file->file_name << "', size=" << file->contents.size();
		}
		execute_requests();
		success_counter++;
	}
	
	void error_callback(uint64_t request_id, const std::exception& ex)
	{
		log(WARN).out << "Request " << request_id << " failed with: " << ex.what();
		error_counter++;
	}
	
	void print_stats() {
		log(INFO).out << success_counter << " req/s, " << error_counter << " errors, "
				<< client->vnx_get_num_pending() << " pending";
		success_counter = 0;
	}
	
private:
	vnx::Hash64 get_type_hash() const override { return vnx::Hash64(get_type_name()); }
	const char* get_type_name() const override { return "TestModule"; }
	
	void read(std::istream& _in) override {}
	void write(std::ostream& _out) const override {}
	
	void accept(vnx::Visitor& _visitor) const override {}
	
	void vnx_handle_switch(std::shared_ptr<const vnx::Sample> sample) override {}
	
	std::shared_ptr<vnx::Value> vnx_call_switch(vnx::TypeInput& in, const vnx::TypeCode* call_type, const vnx::request_id_t& request_id) override {
		return 0;
	}
	
private:
	std::shared_ptr<example::FileServerAsyncClient> client;
	
	uint64_t file_counter = 0;
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
	std::string node = "file_server.sock";
	vnx::read_config("node", node);
	
	{
		// Create a Proxy to connect to the database process
		vnx::Handle<vnx::Proxy> proxy = new vnx::Proxy("Proxy", vnx::Endpoint::from_url(node));
		
		// Tell the Proxy to forward requests to service "FileServer"
		proxy->forward_list.push_back("FileServer");
		
		// Proxy needs to be started before trying to access the forwarded service
		proxy.start_detached();
	}
	
	/*
	 * Create and start our module.
	 */
	vnx::Handle<TestModule> module = new TestModule("TestModule");
	module->service_name = "FileServer";
	
	module.start_detached();
	
	vnx::wait();
	
}


