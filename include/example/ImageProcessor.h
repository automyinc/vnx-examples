
#ifndef INCLUDE_EXAMPLE_IMAGEPROCESSOR_H
#define INCLUDE_EXAMPLE_IMAGEPROCESSOR_H

#include <example/ImageProcessorBase.hxx>
#include <automy/basic/ImageFrameF32.hxx>

using namespace automy;


namespace example {

/*
 * The ImageProcessor example receives 8-bit image data and converts them to 32-bit float.
 */
class ImageProcessor : public ImageProcessorBase {
public:
	/**
	 * Typically we don't want to hard-code a module name so we pass a name through
	 * and let the user pick one when creating an instance.
	 */
	ImageProcessor(const std::string& _vnx_name)
		:	ImageProcessorBase(_vnx_name)
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
		
		/*
		 * We subscribe to our input with a max queue length of 10 ms,
		 * which means given a frame rate of 50 Hz at most one frame is going to be
		 * buffered in the input queue, first in first out.
		 */
		subscribe(input, 10);
		
		// Enter main processing loop
		Super::main();
	}
	
	/**
	 * The handle() function will be called from within Super::main() every time a
	 * basic::ImageFrame8 sample is received.
	 */
	void handle(std::shared_ptr<const basic::ImageFrame8> value) override {
		
		const basic::Image8& src = value->image;
		const uint32_t width = src.width();
		const uint32_t height = src.height();
		
		/*
		 * We create a new sample value (basic::ImageFrame8) to be published directly
		 * instead of creating it on the stack and then having it copied when publishing.
		 */
		std::shared_ptr<basic::ImageFrameF32> out = basic::ImageFrameF32::create();
		out->time = value->time;
		out->frame = value->frame;
		out->format = value->format;
		out->properties = value->properties;
		
		/* 
		 * In this example we convert 8 bit integer to 32 bit float.
		 */
		basic::ImageF32& dst = out->image;
		dst.resize(width, height);
		for(int y = 0; y < height; ++y) {
			for(int x = 0; x < width; ++x) {
				dst(x, y) = float(src(x, y)) * scale_factor;
			}
		}
		
		/*
		 * We publish our sample value directly on topic 'output'. Directly means other modules
		 * in this process will receive a const pointer to our data (ie. zero copy), so we cannot modify
		 * the data anymore after the publish() call as doing so can cause memory corruption.
		 */
		publish(out, output);
		
		/*
		 * After publish() we can keep the sample value "out" but we may not modify it anymore since other threads
		 * could have and keep a pointer to the data forever.
		 * 
		 * For example: out->image.clear();		// can cause a segfault if another module is accessing the image
		 */
		
		log(INFO).out << "Processed frame " << out->get_property("sequence");
	}
	
};


} // example

#endif /* INCLUDE_EXAMPLE_IMAGEPROCESSOR_H */
