/*
 * record_file_api.cpp
 *
 *  Created on: Sep 11, 2019
 *      Author: mad
 */

#include <vnx/Config.h>
#include <vnx/Process.h>
#include <vnx/RecordReader.h>

#include <automy/vehicle/VehicleInfo.hxx>
#include <automy/vehicle/Odometry.hxx>
#include <automy/vehicle/GPS_Info.hxx>

#include <automy/vision/CameraInfo.hxx>
#include <automy/vision/ImageFrame8.hxx>
#include <automy/vision/PointCloud.hxx>

#include <automy/lidar/LidarInfo.hxx>
#include <automy/lidar/PointCloud.hxx>

using namespace automy;



int main(int argc, char** argv) {
	
	std::map<std::string, std::string> options;
	options["f"] = "file";
	options["file"] = "record file path";
	
	vnx::init("record_file_api", argc, argv, options);
	
	std::string file_path;
	vnx::read_config("file", file_path);
	
	vnx::RecordReader reader(file_path);
	
	// dump header
	std::cout << *reader.get_header() << std::endl << std::endl;
	
	// test seek performance
	try {
		const int64_t time_begin = vnx::get_time_micros();
		reader.seek_to_position(0.5);
		std::cout << "Seek took " << (vnx::get_time_micros() - time_begin) << " usec" << std::endl;
	} catch(std::exception& ex) {
		std::cout << "Seek failed with: " << ex.what() << std::endl;
	}
	reader.reset();
	
	// read whole recording
	while(vnx::do_run()) {
		
		std::shared_ptr<const vnx::Sample> sample = reader.get_sample();
		
		if(sample->value) {
			std::cout << "Sample: topic='" << sample->topic->get_name() << "', class='" << sample->value->get_type_name() << "'" << std::endl;
		}
		
		{
			auto value = std::dynamic_pointer_cast<const vehicle::VehicleInfo>(sample->value);
			if(value) {
				std::cout << "Speed: " << value->speed << " [m/s]" << std::endl;
			}
		}
		{
			auto value = std::dynamic_pointer_cast<const vehicle::Odometry>(sample->value);
			if(value) {
				std::cout << "Odometry: " << value->position << " [m]" << std::endl;
			}
		}
		{
			auto value = std::dynamic_pointer_cast<const vehicle::GPS_Info>(sample->value);
			if(value) {
				std::cout << "GPS: " << value->latitude << ", " << value->longitude << " [deg]" << std::endl;
			}
		}
		{
			auto value = std::dynamic_pointer_cast<const vision::CameraInfo>(sample->value);
			if(value) {
				std::cout << "CameraInfo '" << sample->topic->get_name() << "': " << value->matrix << std::endl;
			}
		}
		{
			auto value = std::dynamic_pointer_cast<const vision::ImageFrame8>(sample->value);
			if(value) {
				std::cout << "ImageFrame8 '" << sample->topic->get_name() << "': " << value->image.get_size() << " bytes" << std::endl;
			}
		}
		{
			auto value = std::dynamic_pointer_cast<const vision::PointCloud>(sample->value);
			if(value) {
				std::cout << "vision::PointCloud '" << sample->topic->get_name() << "': " << value->points.size() << " points" << std::endl;
			}
		}
		{
			auto value = std::dynamic_pointer_cast<const lidar::LidarInfo>(sample->value);
			if(value) {
				std::cout << "LidarInfo '" << sample->topic->get_name() << "': " << value->matrix << std::endl;
			}
		}
		{
			auto value = std::dynamic_pointer_cast<const lidar::PointCloud>(sample->value);
			if(value) {
				std::cout << "lidar::PointCloud '" << sample->topic->get_name() << "': " << value->points.size() << " points" << std::endl;
			}
		}
		
		if(reader.end_of_file()) {
			break;
		}
		
		reader.read_next();
	}
	
	vnx::close();	// forced clean shutdown
}



