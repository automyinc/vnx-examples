
#include <example/Database.h>

#include <vnx/Config.h>
#include <vnx/Process.h>
#include <vnx/Terminal.h>
#include <vnx/Proxy.h>
#include <vnx/Server.h>


int main(int argc, char** argv) {
	
	std::map<std::string, std::string> options;
	options["s"] = "source";
	options["source"] = "source url";
	options["n"] = "node";
	options["node"] = "server url";
	
	vnx::init("database_server", argc, argv, options);
	
	/*
	 * A typical setup would be a router running on the local machine to which all processes connect.
	 * By default we do not connect to any other process in this case.
	 */
	std::string source = "";
	vnx::read_config("source", source);
	
	/*
	 * By default we create a local UNIX node for this example.
	 */
	std::string node = "database_server.sock";
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
		 * The server will listen on and accept client connections to this process,
		 * depending on the type of endpoint either on a TCP port or on a UNIX domain socket.
		 */
		vnx::Handle<vnx::Server> server = new vnx::Server("Server", vnx::Endpoint::from_url(node));
		server.start_detached();
	}
	
	if(!source.empty()) {
		/*
		 * Optionally we connect to another process for receiving data.
		 */
		vnx::Handle<vnx::Proxy> proxy = new vnx::Proxy("Proxy", vnx::Endpoint::from_url(source));
		proxy->import_list.push_back("example.transactions");
		proxy.start_detached();
	}
	
	{
		/*
		 * Finally we create and start our database module.
		 */
		vnx::Handle<example::Database> module = new example::Database("Database");
		/*
		 * Here we could override configuration variables if we wanted to.
		 * For example: module->auto_save_interval_ms = 100;
		 */
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


