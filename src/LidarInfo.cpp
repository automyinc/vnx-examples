
#include <example/LidarInfo.hxx>

#include <math/Math3D.h>


namespace example {

void LidarInfo::update() {
	matrix = math::translate3(position) * math::rotate3_xyz_intrinsic(rotation);
}


} // example
