
#include <example/LidarProcessor.h>

#include <vnx/Config.h>
#include <vnx/Process.h>
#include <vnx/Terminal.h>
#include <vnx/Server.h>
#include <vnx/Proxy.h>


int main(int argc, char** argv) {
	
	std::map<std::string, std::string> options;
	options["n"] = "node";				// we declare -n is the same as --node
	options["node"] = "server url";		// we declare --node means "server url"
	options["s"] = "source";
	options["source"] = "source url";
	
	vnx::init("lidar_processor", argc, argv, options);
	
	/*
	 * By default we create a local UNIX node in this example.
	 */
	std::string node = "lidar_processor.sock";
	vnx::read_config("node", node);
	
	/*
	 * By default we create a local UNIX proxy to camera_sensor in this example.
	 */
	std::string source = "lidar_sensor.sock";
	vnx::read_config("source", source);
	
	/*
	 * The Proxy will connect to a server, depending on the type of Endpoint
	 * either through TCP or a UNIX domain socket.
	 */
	vnx::Handle<vnx::Proxy> proxy = new vnx::Proxy("Proxy", vnx::Endpoint::from_url(source));
	
	{
		/*
		 * Start a Terminal to display log messages for us.
		 */
		vnx::Handle<vnx::Terminal> terminal = new vnx::Terminal("Terminal");
		terminal.start_detached();
	}
	
	{
		/*
		 * The Server will listen on and accept client connections to this process,
		 * depending on the type of Endpoint either on a TCP port or on a UNIX domain socket.
		 */
		vnx::Handle<vnx::Server> server = new vnx::Server("Server", vnx::Endpoint::from_url(node));
		server.start_detached();
	}
	
	{
		/*
		 * Create and start our processing module.
		 */
		vnx::Handle<example::LidarProcessor> module = new example::LidarProcessor("LidarProcessor");
		
		// Set configuration variables
		if(!module->input) {
			module->input = "sensors.raw_data.lidar";		// set default input topic
		}
		if(!module->output) {
			module->output = "sensors.vehicle_data.lidar";	// set default output topic
		}
		
		// Tell the Proxy to import our input topic
		proxy->import_list.push_back(module->input->get_name());
		
		// Start module in the background
		module.start_detached();
		
		/*
		 * After the module has been started any attempt to access it will cause an exception.
		 * 
		 * For example: module->input = "something.else"; 	// throws exception
		 */
	}
	
	/*
	 * Finally start the Proxy after all topics have been configured.
	 */
	proxy.start_detached();
	
	/*
	 * Wait until shutdown.
	 */
	vnx::wait();
	
}



