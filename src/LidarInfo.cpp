
#include <example/LidarInfo.hxx>

#include <automy/math/Math3D.h>

using namespace automy;


namespace example {

void LidarInfo::update() {
	matrix = math::translate3(position) * math::rotate3_xyz_intrinsic(rotation);
}


} // example
