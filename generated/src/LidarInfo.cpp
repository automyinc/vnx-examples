
// AUTO GENERATED by vnxcppcodegen

#include <example/package.hxx>
#include <example/LidarInfo.hxx>
#include <vnx/Input.h>
#include <vnx/Output.h>
#include <vnx/Visitor.h>
#include <vnx/Object.h>
#include <vnx/Struct.h>


namespace example {


const vnx::Hash64 LidarInfo::VNX_TYPE_HASH(0x8d11d39b0f5a7b5cull);
const vnx::Hash64 LidarInfo::VNX_CODE_HASH(0x30fbab18bef21c86ull);

vnx::Hash64 LidarInfo::get_type_hash() const {
	return VNX_TYPE_HASH;
}

const char* LidarInfo::get_type_name() const {
	return "example.LidarInfo";
}

std::shared_ptr<LidarInfo> LidarInfo::create() {
	return std::make_shared<LidarInfo>();
}

std::shared_ptr<vnx::Value> LidarInfo::clone() const {
	return std::make_shared<LidarInfo>(*this);
}

void LidarInfo::read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code) {
	vnx::read(_in, *this, _type_code, _code);
}

void LidarInfo::write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const {
	vnx::write(_out, *this, _type_code, _code);
}

void LidarInfo::accept(vnx::Visitor& _visitor) const {
	const vnx::TypeCode* _type_code = example::vnx_native_type_code_LidarInfo;
	_visitor.type_begin(*_type_code);
	_visitor.type_field(_type_code->fields[0], 0); vnx::accept(_visitor, time);
	_visitor.type_field(_type_code->fields[1], 1); vnx::accept(_visitor, matrix);
	_visitor.type_field(_type_code->fields[2], 2); vnx::accept(_visitor, position);
	_visitor.type_field(_type_code->fields[3], 3); vnx::accept(_visitor, rotation);
	_visitor.type_end(*_type_code);
}

void LidarInfo::write(std::ostream& _out) const {
	_out << "{";
	_out << "\"time\": "; vnx::write(_out, time);
	_out << ", \"matrix\": "; vnx::write(_out, matrix);
	_out << ", \"position\": "; vnx::write(_out, position);
	_out << ", \"rotation\": "; vnx::write(_out, rotation);
	_out << "}";
}

void LidarInfo::read(std::istream& _in) {
	std::map<std::string, std::string> _object;
	vnx::read_object(_in, _object);
	for(const auto& _entry : _object) {
		if(_entry.first == "matrix") {
			vnx::from_string(_entry.second, matrix);
		} else if(_entry.first == "position") {
			vnx::from_string(_entry.second, position);
		} else if(_entry.first == "rotation") {
			vnx::from_string(_entry.second, rotation);
		} else if(_entry.first == "time") {
			vnx::from_string(_entry.second, time);
		}
	}
}

vnx::Object LidarInfo::to_object() const {
	vnx::Object _object;
	_object["time"] = time;
	_object["matrix"] = matrix;
	_object["position"] = position;
	_object["rotation"] = rotation;
	return _object;
}

void LidarInfo::from_object(const vnx::Object& _object) {
	for(const auto& _entry : _object.field) {
		if(_entry.first == "matrix") {
			_entry.second.to(matrix);
		} else if(_entry.first == "position") {
			_entry.second.to(position);
		} else if(_entry.first == "rotation") {
			_entry.second.to(rotation);
		} else if(_entry.first == "time") {
			_entry.second.to(time);
		}
	}
}

/// \private
std::ostream& operator<<(std::ostream& _out, const LidarInfo& _value) {
	_value.write(_out);
	return _out;
}

/// \private
std::istream& operator>>(std::istream& _in, LidarInfo& _value) {
	_value.read(_in);
	return _in;
}

const vnx::TypeCode* LidarInfo::get_type_code() {
	const vnx::TypeCode* type_code = vnx::get_type_code(vnx::Hash64(0x8d11d39b0f5a7b5cull));
	if(!type_code) {
		type_code = vnx::register_type_code(create_type_code());
	}
	return type_code;
}

std::shared_ptr<vnx::TypeCode> LidarInfo::create_type_code() {
	std::shared_ptr<vnx::TypeCode> type_code = std::make_shared<vnx::TypeCode>(true);
	type_code->name = "example.LidarInfo";
	type_code->type_hash = vnx::Hash64(0x8d11d39b0f5a7b5cull);
	type_code->code_hash = vnx::Hash64(0x30fbab18bef21c86ull);
	type_code->is_class = true;
	type_code->parents.resize(1);
	type_code->parents[0] = ::automy::basic::Transform3D::get_type_code();
	type_code->create_value = []() -> std::shared_ptr<vnx::Value> { return std::make_shared<LidarInfo>(); };
	type_code->methods.resize(1);
	{
		std::shared_ptr<vnx::TypeCode> call_type = std::make_shared<vnx::TypeCode>(true);
		call_type->name = "example.LidarInfo.update";
		call_type->type_hash = vnx::Hash64(0x7ad4a298e3407547ull);
		call_type->code_hash = vnx::Hash64(0x7469faa11d46660cull);
		call_type->is_method = true;
		{
			std::shared_ptr<vnx::TypeCode> return_type = std::make_shared<vnx::TypeCode>(true);
			return_type->name = "example.LidarInfo.update.return";
			return_type->type_hash = vnx::Hash64(0x4130d15b3995d431ull);
			return_type->code_hash = vnx::Hash64(0x71dc0bc0a39c4760ull);
			return_type->is_return = true;
			return_type->build();
			call_type->return_type = vnx::register_type_code(return_type);
		}
		call_type->build();
		type_code->methods[0] = vnx::register_type_code(call_type);
	}
	type_code->fields.resize(4);
	{
		vnx::TypeField& field = type_code->fields[0];
		field.name = "time";
		field.code = {8};
	}
	{
		vnx::TypeField& field = type_code->fields[1];
		field.is_extended = true;
		field.name = "matrix";
		field.code = {21, 2, 4, 4, 10};
	}
	{
		vnx::TypeField& field = type_code->fields[2];
		field.is_extended = true;
		field.name = "position";
		field.code = {21, 2, 3, 1, 10};
	}
	{
		vnx::TypeField& field = type_code->fields[3];
		field.is_extended = true;
		field.name = "rotation";
		field.code = {21, 2, 3, 1, 10};
	}
	type_code->build();
	return type_code;
}


} // namespace example


namespace vnx {

void read(TypeInput& in, ::example::LidarInfo& value, const TypeCode* type_code, const uint16_t* code) {
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
			case 1: vnx::read(in, value.matrix, type_code, _field->code.data()); break;
			case 2: vnx::read(in, value.position, type_code, _field->code.data()); break;
			case 3: vnx::read(in, value.rotation, type_code, _field->code.data()); break;
			default: vnx::skip(in, type_code, _field->code.data());
		}
	}
}

void write(TypeOutput& out, const ::example::LidarInfo& value, const TypeCode* type_code, const uint16_t* code) {
	if(!type_code || (code && code[0] == CODE_ANY)) {
		type_code = example::vnx_native_type_code_LidarInfo;
		out.write_type_code(type_code);
		vnx::write_class_header<::example::LidarInfo>(out);
	}
	if(code && code[0] == CODE_STRUCT) {
		type_code = type_code->depends[code[1]];
	}
	char* const _buf = out.write(8);
	vnx::write_value(_buf + 0, value.time);
	vnx::write(out, value.matrix, type_code, type_code->fields[1].code.data());
	vnx::write(out, value.position, type_code, type_code->fields[2].code.data());
	vnx::write(out, value.rotation, type_code, type_code->fields[3].code.data());
}

void read(std::istream& in, ::example::LidarInfo& value) {
	value.read(in);
}

void write(std::ostream& out, const ::example::LidarInfo& value) {
	value.write(out);
}

void accept(Visitor& visitor, const ::example::LidarInfo& value) {
	value.accept(visitor);
}

} // vnx
