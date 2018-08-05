
// AUTO GENERATED by vnxcppcodegen

#ifndef INCLUDE_example_LidarInfo_HXX_
#define INCLUDE_example_LidarInfo_HXX_

#include <example/package.hxx>
#include <basic/Transform3D.hxx>
#include <math/Vector3d.h>


namespace example {

class LidarInfo : public ::basic::Transform3D {
public:
	
	::math::Vector3d position;
	::math::Vector3d rotation;
	
	typedef ::basic::Transform3D Super;
	
	static const vnx::Hash64 VNX_TYPE_HASH;
	static const vnx::Hash64 VNX_CODE_HASH;
	
	vnx::Hash64 get_type_hash() const;
	const char* get_type_name() const;
	
	virtual void update();
	
	static std::shared_ptr<LidarInfo> create();
	std::shared_ptr<vnx::Value> clone() const;
	
	void read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code);
	void write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const;
	
	void read(std::istream& _in);
	void write(std::ostream& _out) const;
	
	void accept(vnx::Visitor& _visitor) const;
	
	friend std::ostream& operator<<(std::ostream& _out, const LidarInfo& _value);
	friend std::istream& operator>>(std::istream& _in, LidarInfo& _value);
	
	static const vnx::TypeCode* get_type_code();
	static std::shared_ptr<vnx::TypeCode> create_type_code();
	
};


} // namespace example

#endif // INCLUDE_example_LidarInfo_HXX_
