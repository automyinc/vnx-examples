
#ifndef INCLUDE_EXAMPLE_CAMERASENSOR_H_
#define INCLUDE_EXAMPLE_CAMERASENSOR_H_

#include <example/CameraSensorBase.hxx>
#include <automy/basic/ImageFrame8.hxx>

using namespace automy;


namespace example {

/**
 * The CameraSensor example generates random 8-bit image data.
 */
class CameraSensor : public CameraSensorBase {
public:
	/**
	 * Typically we don't want to hard-code a module name so we pass a name through
	 * and let the user pick one when creating an instance.
	 */
	CameraSensor(const std::string& _vnx_name)
			: CameraSensorBase(_vnx_name)
	{
	}
	
	/*
	 * Besides the constructor all functions should be at least protected.
	 */
	
protected:
	/**
	 * The main() function will be called when the module is started in its own thread.
	 */
	void main() override {
		
		// Register a periodic callback to our update() function
		set_timer_millis(interval_ms, std::bind(&CameraSensor::update, this));
		
		// Enter main processing loop
		Super::main();
	}
	
	/**
	 * This function will be called every interval_ms from within Super::main(),
	 * since we setup a timer with set_timer_millis().
	 */
	void update() {
		
		/*
		 * We create a sample value (basic::ImageFrame8) dynamically to be published directly,
		 * instead of creating it on the stack and then having it copied when publishing.
		 */
		std::shared_ptr<basic::ImageFrame8> out = basic::ImageFrame8::create();
		out->time = vnx::get_time_micros();
		out->frame = "camera_front_center";
		out->format = "MONO";
		out->properties["sequence"] = ++sequence;
		
		/*
		 * In this example we fill the image with random data, whatever happens to be in memory.
		 */
		out->image.resize(width, height);
		
		/*
		 * We publish our sample value directly on topic 'output'. Directly means other modules
		 * in this process will receive a const pointer to our data (ie. zero copy), so we cannot modify
		 * the data anymore after the publish() call as doing so can cause memory corruption.
		 */
		publish(out, output);
		
		/*
		 * After publish() we can keep the sample value but we may not modify it anymore since other threads
		 * could have and keep a pointer to the data forever.
		 * 
		 * For example: out->image.clear();		// can cause a segfault if another module is accessing the image
		 */
		
		log(INFO).out << "Grabbed frame " << out->get_property("sequence");
	}

private:
	int64_t sequence = 0;
	
};


} // example

#endif /* INCLUDE_EXAMPLE_CAMERASENSOR_H_ */
