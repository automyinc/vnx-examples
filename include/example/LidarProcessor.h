
#ifndef VNX_EXAMPLES_INCLUDE_EXAMPLE_LIDARPROCESSOR_H_
#define VNX_EXAMPLES_INCLUDE_EXAMPLE_LIDARPROCESSOR_H_

#include <example/LidarProcessorBase.hxx>

using namespace automy;

namespace example {

/*
 * The LidarProcessor example transforms lidar points from their original sensor
 * coordinate system into the vehicle's coordinate frame using the published calibration.
 */
class LidarProcessor : public LidarProcessorBase {
public:
	/**
	 * Typically we don't want to hard-code a module name so we pass a name through
	 * and let the user pick one when creating an instance.
	 */
	LidarProcessor(const std::string& _vnx_name)
		:	LidarProcessorBase(_vnx_name)
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
		 * Subscribe to the configured input topic. In this example both LidarPointCloud
		 * and LidarInfo are published on the same topic.
		 */
		subscribe(input);
		
		// Register a periodic callback to our print_stats() function
		set_timer_millis(1000, std::bind(&LidarProcessor::print_stats, this));
		
		// Enter main processing loop
		Super::main();
	}
	
	/**
	 * The handle() function will be called from within Super::main() every time a
	 * example::LidarPointCloud sample is received.
	 */
	void handle(std::shared_ptr<const example::LidarPointCloud> value) override {
		if(info) {
			std::shared_ptr<example::LidarPointCloud> out = example::LidarPointCloud::create();
			out->time = value->time;
			out->frame = "vehicle";
			
			for(const auto& src : value->points) {
				lidar_point_t point = src;
				point.position = (info->matrix * src.position.extend()).project();
				out->points.push_back(point);
			}
			num_points += out->points.size();
			
			/*
			 * We publish our sample value directly on topic 'output'. Directly means other modules
			 * in this process will receive a const pointer to our data (ie. zero copy), so we cannot modify
			 * the data anymore after the publish() call as doing so can cause memory corruption.
			 */
			publish(out, output);
			
		} else {
			// Just ignore the data until we get a LidarInfo sample
		}
	}
	
	/**
	 * The handle() function will be called from within Super::main() every time a
	 * example::LidarInfo sample is received.
	 */
	void handle(std::shared_ptr<const example::LidarInfo> value) override {
		info = value;	// we simply store the value
	}
	
	/**
	 * This function will be called once a second from within Super::main(). 
	 */
	void print_stats() {
		log(INFO).out << "Processing " << num_points << " points/s";
		num_points = 0;
	}
	
private:
	std::shared_ptr<const example::LidarInfo> info;
	
	int64_t num_points = 0;		// for statistics
	
};


} // example

#endif /* VNX_EXAMPLES_INCLUDE_EXAMPLE_LIDARPROCESSOR_H_ */
