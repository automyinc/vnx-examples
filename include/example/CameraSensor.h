
#ifndef VNX_EXAMPLES_INCLUDE_EXAMPLE_CAMERASENSOR_H_
#define VNX_EXAMPLES_INCLUDE_EXAMPLE_CAMERASENSOR_H_

#include <example/CameraSensorBase.hxx>

#include <basic/ImageFrame8.hxx>

#include <cstdlib>


namespace example {

/*
 * In this example we generate image data instead of actually
 * grabbing frames from a camera.
 */
class CameraSensor : public CameraSensorBase {
public:
	CameraSensor(const std::string& _vnx_name)
			: CameraSensorBase(_vnx_name)
	{
	}
	
protected:
	/*
	 * The main() function will be called when the module is started.
	 */
	void main() override {
		
		// register a periodic callback to our update() function
		set_timer_millis(interval_ms, std::bind(&CameraSensor::update, this));
		
		// enter main processing loop
		Super::main();
		
	}
	
	/*
	 * This function will be called every interval_ms from within Super::main(),
	 * since we setup a timer with set_timer_millis().
	 */
	void update() {
		
		/*
		 * We create a sample value (basic::ImageFrame8) dynamically to be published directly,
		 * instead of creating it on the stack and then having it copied when publishing.
		 */
		std::shared_ptr<basic::ImageFrame8> out = basic::ImageFrame8::create();
		out->time = vnx::get_time_micros();		// just use the current time
		out->frame = vnx_name;					// use our module name as the coordinate frame
		out->format = "MONO";					// just an example
		out->properties["exposure"] = 123;		// just an example
		
		/*
		 * In this example we fill the image with random lines of data.
		 */
		basic::Image8& dst = out->image;
		dst.resize(width, height);
		for(int y = 0; y < height; ++y) {
			const int pixel = ::rand() % 256;
			for(int x = 0; x < width; ++x) {
				out->image(x, y) = pixel;
			}
		}
		
		/*
		 * We publish our sample value directly on topic 'output'. Directly means other modules
		 * in this process will receive a const pointer to our data (ie. zero copy), hence we cannot modify
		 * the data anymore after the publish() call, as doing so would cause memory corruption.
		 */
		publish(out, output);
		
		/*
		 * After the publish() we can keep the sample value but we may not modify it anymore.
		 */
	}
	
};


} // example

#endif /* VNX_EXAMPLES_INCLUDE_EXAMPLE_CAMERASENSOR_H_ */
