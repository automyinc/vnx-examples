
#include <example/CameraSensor.h>
#include <example/ImageProcessor.h>

#include <vnx/Config.h>
#include <vnx/Process.h>
#include <vnx/Terminal.h>
#include <vnx/Server.h>


int main(int argc, char** argv) {
	
	vnx::init("zero_copy_publish_subscribe", argc, argv);
	
	{
		/*
		 * Start a Terminal to display log messages for us.
		 */
		vnx::Handle<vnx::Terminal> terminal = new vnx::Terminal("Terminal");
		terminal.start_detached();
	}
	
	{
		/*
		 * Create and start our sensor module.
		 */
		vnx::Handle<example::CameraSensor> module = new example::CameraSensor("Camera");
		
		module->output = "sensors.raw_data.camera";		// set output topic
		
		// Start module in the background
		module.start_detached();
		
		/*
		 * After the module has been started any attempt to access it will cause an exception.
		 * 
		 * For example: module->output = "something.else"; 	// throws exception
		 */
	}
	
	{
		/*
		 * Create and start our processing module.
		 */
		vnx::Handle<example::ImageProcessor> module = new example::ImageProcessor("ImageProcessor");
		
		module->input = "sensors.raw_data.camera";		// set input topic
		module->output = "vision.float_data.camera";	// set output topic
		
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

