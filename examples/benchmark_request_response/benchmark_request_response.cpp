
#include <example/User.hxx>
#include <example/DatabaseClient.hxx>

#include <vnx/Config.h>
#include <vnx/Process.h>
#include <vnx/Proxy.h>


int main(int argc, char** argv) {
	
	std::map<std::string, std::string> options;
	options["n"] = "node";
	options["node"] = "server url";
	
	vnx::init("benchmark_request_response", argc, argv, options);
	
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
	
	// Create a client to our database
	example::DatabaseClient client("Database");
	
	try {
		// Add a user to play with
		client.add_user("test_user");
		
		int64_t start_time = vnx::get_wall_time_micros();
		int64_t counter = 0;
		
		/*
		 * Keep running until shutdown is triggered.
		 */
		while(vnx::do_run()) {
			
			// Request our test user from the database
			std::shared_ptr<const example::User> user = client.get_user("test_user");
			
			/*
			 * Sanity checks to make sure it's working.
			 */
			if(user == 0) {
				throw std::logic_error("User 'test_user' does not exist");
			}
			if(user->name != "test_user") {
				throw std::logic_error("User 'test_user' has wrong name: '" + user->name + "'");
			}
			
			/*
			 * Compute statistics.
			 */
			if(++counter >= 10000) {
				const int64_t now = vnx::get_wall_time_micros();
				vnx::log_info().out << double(counter) / (double(now - start_time) * 1e-6) << " requests/s";
				start_time = now;
				counter = 0;
			}
		}
	} catch(const std::exception& ex) {
		/*
		 * In this case a request failed and we stop with the benchmark.
		 */
		vnx::log_error().out << ex.what();
	}
	
	// Trigger shutdown and wait for clean exit
	vnx::close();
	
}


