
#ifndef VNX_EXAMPLES_INCLUDE_EXAMPLE_IMAGEPROCESSOR_H
#define VNX_EXAMPLES_INCLUDE_EXAMPLE_IMAGEPROCESSOR_H

#include <example/ImageProcessorBase.hxx>

#include <basic/ImageFrameF32.hxx>


namespace example {

class ImageProcessor : public ImageProcessorBase {
public:
	ImageProcessor(const std::string& _vnx_name)
		:	ImageProcessorBase(_vnx_name)
	{
	}
	
protected:
	void main() override {
		
		/*
		 * We subscribe to our input with a max queue length of 10 ms,
		 * which means given a frame rate of 50 Hz at most one frame is going to be
		 * buffered in the input queue, first in first out.
		 */
		subscribe(input, 10);
		
		// enter main processing loop
		Super::main();
		
	}
	
	void handle(std::shared_ptr<const basic::ImageFrame8> value) override {
		
		const basic::Image8& src = value->image;
		const uint32_t width = src.width;
		const uint32_t height = src.height;
		
		/*
		 * We create a new sample value (basic::ImageFrame8) dynamically to be published directly,
		 * instead of creating it on the stack and then having it copied when publishing.
		 */
		std::shared_ptr<basic::ImageFrameF32> out = basic::ImageFrameF32::create();
		out->time = value->time;
		out->frame = value->frame;
		out->format = value->format;
		out->properties = value->properties;
		
		/* 
		 * In this example we convert 8 bit to 32 bit float.
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

#endif /* VNX_EXAMPLES_INCLUDE_EXAMPLE_IMAGEPROCESSOR_H */
