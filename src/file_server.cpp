/*
 * file_server.cpp
 *
 *  Created on: Mar 16, 2020
 *      Author: mad
 */

#include <example/FileServer.h>

#include <vnx/Config.h>
#include <vnx/Process.h>
#include <vnx/Terminal.h>
#include <vnx/Server.h>


int main(int argc, char** argv) {
	
	std::map<std::string, std::string> options;
	options["n"] = "node";				// we declare -n is the same as --node
	options["node"] = "server url";		// we declare --node means "server url"
	
	vnx::init("file_server", argc, argv, options);
	
	/*
	 * By default we create a local UNIX node for this example.
	 */
	std::string node = "file_server.sock";
	vnx::read_config("node", node);
	
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
		 * Create a new instance of our FileServer module.
		 */
		vnx::Handle<example::FileServer> module = new example::FileServer("FileServer");
		
		// Start module in the background
		module.start_detached();
		
		/*
		 * After the module has been started any attempt to access it will cause an exception.
		 * 
		 * For example: module->input = "something.else"; 	// throws exception
		 */
	}
	
	/*
	 * Wait until shutdown.
	 */
	vnx::wait();
	
}
