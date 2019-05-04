
#ifndef INCLUDE_VNX_EXAMPLES_LIDARSENSOR_H
#define INCLUDE_VNX_EXAMPLES_LIDARSENSOR_H

#include <example/LidarSensorBase.hxx>
#include <example/LidarPointCloud.hxx>

using namespace automy;


namespace example {

class LidarSensor : public LidarSensorBase {
public:
	LidarSensor(const std::string& _vnx_name)
		:	LidarSensorBase(_vnx_name)
	{
	}
	
protected:
	/**
	 * The main() function will be called when the module is started in its own thread.
	 */
	void main() override {
		
		// Initialize calibration matrix
		info.update();
		
		// Register a periodic callback to our update() function
		set_timer_millis(interval_ms, std::bind(&LidarSensor::update, this));
		
		// Register a periodic callback to our print_stats() function
		set_timer_millis(1000, std::bind(&LidarSensor::print_stats, this));
		
		// Enter main processing loop
		Super::main();
	}
	
	/**
	 * This function will be called every interval_ms from within Super::main(),
	 * since we setup a timer with set_timer_millis().
	 */
	void update() {
		
		/*
		 * We create a sample value (example::LidarPointCloud) dynamically to be published directly,
		 * instead of creating it on the stack and then having it copied when publishing.
		 */
		std::shared_ptr<example::LidarPointCloud> out = example::LidarPointCloud::create();
		out->time = vnx::get_time_micros();
		out->frame = "lidar_front_center";
		
		/*
		 * In this example we generate random lidar points.
		 */
		for(int k = 0; k < num_angles; ++k) {
			const int64_t time = vnx::get_time_micros();
			for(int i = 0; i < num_beams; ++i) {
				lidar_point_t point;
				point.time = time;
				point.position = math::Vector3d(time % 7907, time % 7919, i * 10) * 0.01;
				point.distance = point.position.norm();
				point.intensity = 1;
				out->points.push_back(point);
			}
		}
		num_points += out->points.size();
		
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
		 * For example: out->points.clear();		// can cause a segfault if another module is reading the data at the time
		 */
		
		/*
		 * We also publish a copy of our calibration info so other modules can use it.
		 */
		publish(info, output);
	}
	
	/**
	 * This function will be called once a second from within Super::main(). 
	 */
	void print_stats() {
		log(INFO).out << "Receiving " << num_points << " points/s";
		num_points = 0;
	}
	
private:
	int64_t num_points = 0;		// for statistics
	
};


} // example

#endif // INCLUDE_VNX_EXAMPLES_LIDARSENSOR_H
