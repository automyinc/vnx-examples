
#include <example/ImageProcessor.h>

#include <vnx/Config.h>
#include <vnx/Process.h>
#include <vnx/Terminal.h>
#include <vnx/Server.h>
#include <vnx/Proxy.h>


int main(int argc, char** argv) {
	
	std::map<std::string, std::string> options;
	options["n"] = "node";
	options["node"] = "server url";
	options["s"] = "source";
	options["source"] = "source url";
	
	vnx::init("image_processor", argc, argv, options);
	
	/*
	 * By default we create a local UNIX node in this example.
	 */
	std::string node = "image_processor.sock";
	vnx::read_config("node", node);
	
	/*
	 * By default we create a local UNIX proxy to camera_sensor in this example.
	 */
	std::string source = "camera_sensor.sock";
	vnx::read_config("source", source);
	
	{
		/*
		 * First we start a terminal to display log messages for us.
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
		 * The Proxy will connect to a server, depending on the type of Endpoint
		 * either through TCP or a UNIX domain socket.
		 */
		vnx::Handle<vnx::Proxy> proxy = new vnx::Proxy("Proxy", vnx::Endpoint::from_url(source));
		proxy.start_detached();
	}
	
	{
		/*
		 * Finally we create and start our processing module.
		 */
		vnx::Handle<example::ImageProcessor> module = new example::ImageProcessor("ImageProcessor_A");
		module.start_detached();
		/*
		 * After the module has been started any attempt to access it will cause an exception.
		 */
	}
	
	/*
	 * Wait until shutdown.
	 */
	vnx::wait();
	
}



