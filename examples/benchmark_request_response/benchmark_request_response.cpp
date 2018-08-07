
#include <example/User.hxx>
#include <example/DatabaseClient.hxx>

#include <vnx/Config.h>
#include <vnx/Process.h>
#include <vnx/Proxy.h>
#include <vnx/Endpoint.hxx>


int main(int argc, char** argv) {
	
	std::map<std::string, std::string> options;
	options["n"] = "node";
	options["node"] = "server url";
	
	vnx::init("benchmark_request_response", argc, argv, options);
	
	std::string node = "database_server.sock";
	vnx::read_config("node", node);
	
	/*
	 * This program is a special case in that we first need to ensure that we are connected.
	 * For this reason we are manually connecting the socket first and then passing the
	 * already connected socket to vnx::Proxy.
	 */
	std::shared_ptr<const vnx::Endpoint> endpoint = vnx::Endpoint::from_url(node);
	const int socket = endpoint->open();
	try {
		endpoint->connect(socket);
	} catch(const std::exception& ex) {
		vnx::log_error().out << ex.what();
		::close(socket);
		vnx::close();
		return -1;
	}
	
	{
		// create a Proxy to connect to the database process using the already connected socket
		vnx::Handle<vnx::Proxy> proxy = new vnx::Proxy("Proxy", endpoint, socket);
		
		// here we tell the Proxy to forward requests to service "Database"
		proxy->forward_list.push_back("Database");
		
		// make sure to start the Proxy first before trying to access the forwarded service
		proxy.start_detached();
	}
	
	// create a client to our database
	example::DatabaseClient client("Database");
	
	try {
		// add a user to play with
		client.add_user("test_user");
		
		int64_t start_time = vnx::get_wall_time_micros();
		int64_t counter = 0;
		
		/*
		 * Keep running until shutdown is triggered.
		 */
		while(vnx::do_run()) {
			// request our test user from the database
			std::shared_ptr<const example::Object> object = client.get_object("user", "test_user");
			
			// we know it should be a user so try to cast the pointer
			std::shared_ptr<const example::User> user = std::dynamic_pointer_cast<const example::User>(object);
			
			/*
			 * Some sanity checks to proof it's actually working.
			 */
			if(user == 0) {
				throw std::logic_error("user 'test_user' does not exist");
			}
			if(user->name != "test_user") {
				throw std::logic_error("user 'test_user' has wrong name: '" + user->name + "'");
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
		 * In this case a request failed and we just stop with the benchmark.
		 */
		vnx::log_error().out << ex.what();
	}
	
	vnx::close();		// trigger shutdown and wait for clean exit
	
}


