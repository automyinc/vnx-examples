
#ifndef INCLUDE_VNX_EXAMPLES_LIDARSENSOR_H
#define INCLUDE_VNX_EXAMPLES_LIDARSENSOR_H

#include <example/LidarSensorBase.hxx>


namespace example {

class LidarSensor : public LidarSensorBase {
public:
	LidarSensor(const std::string& _vnx_name)
		:	LidarSensorBase(_vnx_name)
	{
	}
	
protected:
	void main() override {
		
	}
	
	
	
	
};


} // example

#endif // INCLUDE_VNX_EXAMPLES_LIDARSENSOR_H
