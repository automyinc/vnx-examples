
// AUTO GENERATED by vnxcppcodegen

#ifndef INCLUDE_example_lidar_point_t_HXX_
#define INCLUDE_example_lidar_point_t_HXX_

#include <vnx/Type.h>
#include <example/package.hxx>
#include <math/Vector3d.h>


namespace example {

struct lidar_point_t {
	
	
	::int64_t time = 0;
	::math::Vector3d position;
	::vnx::float32_t distance = 0;
	::vnx::float32_t intensity = 0;
	
	static const vnx::Hash64 VNX_TYPE_HASH;
	static const vnx::Hash64 VNX_CODE_HASH;
	
	vnx::Hash64 get_type_hash() const;
	const char* get_type_name() const;
	
	static std::shared_ptr<lidar_point_t> create();
	std::shared_ptr<lidar_point_t> clone() const;
	
	void read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code);
	void write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const;
	
	void read(std::istream& _in);
	void write(std::ostream& _out) const;
	
	void accept(vnx::Visitor& _visitor) const;
	
	vnx::Object to_object() const;
	void from_object(const vnx::Object& object);
	
	friend std::ostream& operator<<(std::ostream& _out, const lidar_point_t& _value);
	friend std::istream& operator>>(std::istream& _in, lidar_point_t& _value);
	
	static const vnx::TypeCode* get_type_code();
	static std::shared_ptr<vnx::TypeCode> create_type_code();
	
};


} // namespace example

#endif // INCLUDE_example_lidar_point_t_HXX_
