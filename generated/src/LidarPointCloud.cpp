
// AUTO GENERATED by vnxcppcodegen

#include <example/package.hxx>
#include <example/LidarPointCloud.hxx>
#include <vnx/Input.h>
#include <vnx/Output.h>
#include <vnx/Visitor.h>
#include <vnx/Object.h>
#include <vnx/Struct.h>


namespace example {


const vnx::Hash64 LidarPointCloud::VNX_TYPE_HASH(0x245fc412fc39f4acull);
const vnx::Hash64 LidarPointCloud::VNX_CODE_HASH(0x6c8672cb76a0da7eull);

vnx::Hash64 LidarPointCloud::get_type_hash() const {
	return VNX_TYPE_HASH;
}

const char* LidarPointCloud::get_type_name() const {
	return "example.LidarPointCloud";
}

std::shared_ptr<LidarPointCloud> LidarPointCloud::create() {
	return std::make_shared<LidarPointCloud>();
}

std::shared_ptr<vnx::Value> LidarPointCloud::clone() const {
	return std::make_shared<LidarPointCloud>(*this);
}

void LidarPointCloud::read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code) {
	vnx::read(_in, *this, _type_code, _code);
}

void LidarPointCloud::write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const {
	vnx::write(_out, *this, _type_code, _code);
}

void LidarPointCloud::accept(vnx::Visitor& _visitor) const {
	const vnx::TypeCode* _type_code = example::vnx_native_type_code_LidarPointCloud;
	_visitor.type_begin(*_type_code);
	_visitor.type_field(_type_code->fields[0], 0); vnx::accept(_visitor, time);
	_visitor.type_field(_type_code->fields[1], 1); vnx::accept(_visitor, frame);
	_visitor.type_field(_type_code->fields[2], 2); vnx::accept(_visitor, points);
	_visitor.type_end(*_type_code);
}

void LidarPointCloud::write(std::ostream& _out) const {
	_out << "{";
	_out << "\"time\": "; vnx::write(_out, time);
	_out << ", \"frame\": "; vnx::write(_out, frame);
	_out << ", \"points\": "; vnx::write(_out, points);
	_out << "}";
}

void LidarPointCloud::read(std::istream& _in) {
	std::map<std::string, std::string> _object;
	vnx::read_object(_in, _object);
	for(const auto& _entry : _object) {
		if(_entry.first == "frame") {
			vnx::from_string(_entry.second, frame);
		} else if(_entry.first == "points") {
			vnx::from_string(_entry.second, points);
		} else if(_entry.first == "time") {
			vnx::from_string(_entry.second, time);
		}
	}
}

vnx::Object LidarPointCloud::to_object() const {
	vnx::Object _object;
	_object["time"] = time;
	_object["frame"] = frame;
	_object["points"] = points;
	return _object;
}

void LidarPointCloud::from_object(const vnx::Object& _object) {
	for(const auto& _entry : _object.field) {
		if(_entry.first == "frame") {
			_entry.second.to(frame);
		} else if(_entry.first == "points") {
			_entry.second.to(points);
		} else if(_entry.first == "time") {
			_entry.second.to(time);
		}
	}
}

/// \private
std::ostream& operator<<(std::ostream& _out, const LidarPointCloud& _value) {
	_value.write(_out);
	return _out;
}

/// \private
std::istream& operator>>(std::istream& _in, LidarPointCloud& _value) {
	_value.read(_in);
	return _in;
}

const vnx::TypeCode* LidarPointCloud::get_type_code() {
	const vnx::TypeCode* type_code = vnx::get_type_code(vnx::Hash64(0x245fc412fc39f4acull));
	if(!type_code) {
		type_code = vnx::register_type_code(create_type_code());
	}
	return type_code;
}

std::shared_ptr<vnx::TypeCode> LidarPointCloud::create_type_code() {
	std::shared_ptr<vnx::TypeCode> type_code = std::make_shared<vnx::TypeCode>(true);
	type_code->name = "example.LidarPointCloud";
	type_code->type_hash = vnx::Hash64(0x245fc412fc39f4acull);
	type_code->code_hash = vnx::Hash64(0x6c8672cb76a0da7eull);
	type_code->is_class = true;
	type_code->create_value = []() -> std::shared_ptr<vnx::Value> { return std::make_shared<LidarPointCloud>(); };
	type_code->depends.resize(1);
	type_code->depends[0] = ::example::lidar_point_t::get_type_code();
	type_code->methods.resize(0);
	type_code->fields.resize(3);
	{
		vnx::TypeField& field = type_code->fields[0];
		field.name = "time";
		field.code = {8};
	}
	{
		vnx::TypeField& field = type_code->fields[1];
		field.is_extended = true;
		field.name = "frame";
		field.code = {12, 5};
	}
	{
		vnx::TypeField& field = type_code->fields[2];
		field.is_extended = true;
		field.name = "points";
		field.code = {12, 19, 0};
	}
	type_code->build();
	return type_code;
}


} // namespace example


namespace vnx {

void read(TypeInput& in, ::example::LidarPointCloud& value, const TypeCode* type_code, const uint16_t* code) {
	if(!type_code) {
		throw std::logic_error("read(): type_code == 0");
	}
	if(code) {
		switch(code[0]) {
			case CODE_STRUCT: type_code = type_code->depends[code[1]]; break;
			case CODE_ALT_STRUCT: type_code = type_code->depends[vnx::flip_bytes(code[1])]; break;
			default: vnx::skip(in, type_code, code); return;
		}
	}
	const char* const _buf = in.read(type_code->total_field_size);
	if(type_code->is_matched) {
		{
			const vnx::TypeField* const _field = type_code->field_map[0];
			if(_field) {
				vnx::read_value(_buf + _field->offset, value.time, _field->code.data());
			}
		}
	}
	for(const vnx::TypeField* _field : type_code->ext_fields) {
		switch(_field->native_index) {
			case 1: vnx::read(in, value.frame, type_code, _field->code.data()); break;
			case 2: vnx::read(in, value.points, type_code, _field->code.data()); break;
			default: vnx::skip(in, type_code, _field->code.data());
		}
	}
}

void write(TypeOutput& out, const ::example::LidarPointCloud& value, const TypeCode* type_code, const uint16_t* code) {
	if(!type_code || (code && code[0] == CODE_ANY)) {
		type_code = example::vnx_native_type_code_LidarPointCloud;
		out.write_type_code(type_code);
		vnx::write_class_header<::example::LidarPointCloud>(out);
	}
	if(code && code[0] == CODE_STRUCT) {
		type_code = type_code->depends[code[1]];
	}
	char* const _buf = out.write(8);
	vnx::write_value(_buf + 0, value.time);
	vnx::write(out, value.frame, type_code, type_code->fields[1].code.data());
	vnx::write(out, value.points, type_code, type_code->fields[2].code.data());
}

void read(std::istream& in, ::example::LidarPointCloud& value) {
	value.read(in);
}

void write(std::ostream& out, const ::example::LidarPointCloud& value) {
	value.write(out);
}

void accept(Visitor& visitor, const ::example::LidarPointCloud& value) {
	value.accept(visitor);
}

} // vnx
