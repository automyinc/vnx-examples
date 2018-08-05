
// AUTO GENERATED by vnxcppcodegen

#include <example/package.hxx>
#include <example/lidar_point_t.hxx>
#include <vnx/Input.h>
#include <vnx/Output.h>
#include <vnx/Visitor.h>


namespace example {


const vnx::Hash64 lidar_point_t::VNX_TYPE_HASH(0x23a1b484366dcb3dull);
const vnx::Hash64 lidar_point_t::VNX_CODE_HASH(0x57b6f866820481f6ull);

vnx::Hash64 lidar_point_t::get_type_hash() const {
	return VNX_TYPE_HASH;
}

const char* lidar_point_t::get_type_name() const {
	return "example.lidar_point_t";
}

void lidar_point_t::accept(vnx::Visitor& _visitor) const {
	const vnx::TypeCode* _type_code = get_type_code();
	_visitor.type_begin(*_type_code);
	_visitor.type_field(_type_code->fields[0], 0); vnx::accept(_visitor, time);
	_visitor.type_field(_type_code->fields[1], 1); vnx::accept(_visitor, position);
	_visitor.type_field(_type_code->fields[2], 2); vnx::accept(_visitor, distance);
	_visitor.type_field(_type_code->fields[3], 3); vnx::accept(_visitor, intensity);
	_visitor.type_end(*_type_code);
}

void lidar_point_t::write(std::ostream& _out) const {
	_out << "{";
	_out << "\"time\": "; vnx::write(_out, time);
	_out << ", \"position\": "; vnx::write(_out, position);
	_out << ", \"distance\": "; vnx::write(_out, distance);
	_out << ", \"intensity\": "; vnx::write(_out, intensity);
	_out << "}";
}

void lidar_point_t::read(std::istream& _in) {
	std::map<std::string, std::string> _object;
	vnx::read_object(_in, _object);
	for(const auto& _entry : _object) {
		if(_entry.first == "time") {
			vnx::from_string(_entry.second, time);
		} else if(_entry.first == "position") {
			vnx::from_string(_entry.second, position);
		} else if(_entry.first == "distance") {
			vnx::from_string(_entry.second, distance);
		} else if(_entry.first == "intensity") {
			vnx::from_string(_entry.second, intensity);
		}
	}
}

std::ostream& operator<<(std::ostream& _out, const lidar_point_t& _value) {
	_value.write(_out);
	return _out;
}

std::istream& operator>>(std::istream& _in, lidar_point_t& _value) {
	_value.read(_in);
	return _in;
}

const vnx::TypeCode* lidar_point_t::get_type_code() {
	const vnx::TypeCode* type_code = vnx::get_type_code(vnx::Hash64(0x23a1b484366dcb3dull));
	if(!type_code) {
		type_code = vnx::register_type_code(create_type_code());
	}
	return type_code;
}

std::shared_ptr<vnx::TypeCode> lidar_point_t::create_type_code() {
	std::shared_ptr<vnx::TypeCode> type_code = std::make_shared<vnx::TypeCode>(true);
	type_code->name = "example.lidar_point_t";
	type_code->type_hash = vnx::Hash64(0x23a1b484366dcb3dull);
	type_code->code_hash = vnx::Hash64(0x57b6f866820481f6ull);
	type_code->fields.resize(4);
	{
		vnx::TypeField& field = type_code->fields[0];
		field.name = "time";
		field.code = {8};
	}
	{
		vnx::TypeField& field = type_code->fields[1];
		field.is_extended = true;
		field.name = "position";
		field.code = {11, 3, 10};
	}
	{
		vnx::TypeField& field = type_code->fields[2];
		field.name = "distance";
		field.code = {9};
	}
	{
		vnx::TypeField& field = type_code->fields[3];
		field.name = "intensity";
		field.code = {9};
	}
	type_code->build();
	return type_code;
}


} // namespace example


namespace vnx {

void read(TypeInput& in, ::example::lidar_point_t& value, const TypeCode* type_code, const uint16_t* code) {
	if(code) {
		type_code = type_code->depends[code[1]];
	}
	const char* const _buf = in.read(type_code->total_field_size);
	{
		const vnx::TypeField* const _field = type_code->field_map[0];
		if(_field) {
			vnx::read_value(_buf + _field->offset, value.time, _field->code.data());
		}
	}
	{
		const vnx::TypeField* const _field = type_code->field_map[2];
		if(_field) {
			vnx::read_value(_buf + _field->offset, value.distance, _field->code.data());
		}
	}
	{
		const vnx::TypeField* const _field = type_code->field_map[3];
		if(_field) {
			vnx::read_value(_buf + _field->offset, value.intensity, _field->code.data());
		}
	}
	for(const vnx::TypeField* _field : type_code->ext_fields) {
		switch(_field->native_index) {
			case 1: vnx::read(in, value.position, type_code, _field->code.data()); break;
			default: vnx::skip(in, type_code, _field->code.data());
		}
	}
}

void write(TypeOutput& out, const ::example::lidar_point_t& value, const TypeCode* type_code, const uint16_t* code) {
	if(code) {
		type_code = type_code->depends[code[1]];
	}
	char* const _buf = out.write(16);
	vnx::write_value(_buf + 0, value.time);
	vnx::write_value(_buf + 8, value.distance);
	vnx::write_value(_buf + 12, value.intensity);
	vnx::write(out, value.position, type_code, type_code->fields[1].code.data());
}

void read(std::istream& in, ::example::lidar_point_t& value) {
	value.read(in);
}

void write(std::ostream& out, const ::example::lidar_point_t& value) {
	value.write(out);
}

void accept(Visitor& visitor, const ::example::lidar_point_t& value) {
	value.accept(visitor);
}

} // vnx
