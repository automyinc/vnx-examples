
#include <vnx/Process.h>        // Needed for vnx::init()
#include <vnx/Config.h>			// Needed for vnx::read_config()


int main(int argc, char** argv) {
	
	std::map<std::string, std::string> options;
	options["o"] = "some_option";					// we declare -o is the same as --some_option
	options["some_option"] = "just an option";		// we declare --some_option means "just an option"
	
	vnx::init("configuration_example", argc, argv, options);        // Initialize (ie. parse configs, etc.)
	
	{
		std::string value = "default";
		vnx::read_config("some_option", value);
		std::cout << "INFO: some_option = '" << value << "'" << std::endl;
	}
	{
		std::string value = "default";
		vnx::read_config("SomeModule.some_option", value);
		std::cout << "INFO: SomeModule.some_option = '" << value << "'" << std::endl;
	}
	{
		std::string value = "default";
		vnx::read_config("AnotherModule.some_option", value);
		std::cout << "INFO: AnotherModule.some_option = '" << value << "'" << std::endl;
	}
	
	vnx::close();     // Shutdown (ensures clean exit)
}

