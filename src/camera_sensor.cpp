
#include <example/CameraSensor.h>

#include <vnx/Config.h>
#include <vnx/Process.h>
#include <vnx/Terminal.h>
#include <vnx/Server.h>


int main(int argc, char** argv) {
	
	std::map<std::string, std::string> options;
	options["n"] = "node";
	options["node"] = "server url";
	
	vnx::init("camera_sensor", argc, argv, options);
	
	/*
	 * By default we create a local UNIX node for this example.
	 */
	std::string node = "camera_sensor.sock";
	vnx::read_config("node", node);
	
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
		 * Finally we create and start our sensor module.
		 */
		vnx::Handle<example::CameraSensor> module = new example::CameraSensor("Camera_A");
		module->output = "sensors.raw_data.Camera_A";
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

