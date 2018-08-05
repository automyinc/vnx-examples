
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
	 * So by default we choose a local UNIX socket to the router as our source of data.
	 */
	std::string source = "/tmp/vnxrouter.sock";
	vnx::read_config("source", source);
	
	/*
	 * By default we create a local UNIX node for this example.
	 */
	std::string node = "/tmp/database_server.sock";
	vnx::read_config("node", node);
	
	{
		vnx::Handle<vnx::Terminal> terminal = new vnx::Terminal("Terminal");
		terminal.start_detached();
	}
	
	{
		vnx::Handle<vnx::Server> server = new vnx::Server("Server", vnx::Endpoint::from_url(node));
		server.start_detached();
	}
	
	{
		vnx::Handle<vnx::Proxy> proxy = new vnx::Proxy("Proxy", vnx::Endpoint::from_url(source));
		proxy->import_list.push_back("example.transactions");
		proxy.start_detached();
	}
	
	{
		vnx::Handle<example::Database> module = new example::Database("Database");
		module.start_detached();
	}
	
	/*
	 * Wait until shutdown.
	 */
	vnx::wait();
	
}


