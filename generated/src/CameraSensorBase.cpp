
// AUTO GENERATED by vnxcppcodegen

#include <example/package.hxx>
#include <example/CameraSensorBase.hxx>
#include <vnx/Input.h>
#include <vnx/Output.h>
#include <vnx/Visitor.h>
#include <vnx/Object.h>
#include <vnx/Struct.h>
#include <vnx/Config.h>


namespace example {


const vnx::Hash64 CameraSensorBase::VNX_TYPE_HASH(0x2201bbd3b25391ebull);
const vnx::Hash64 CameraSensorBase::VNX_CODE_HASH(0xb632f00cbbf2a585ull);

CameraSensorBase::CameraSensorBase(const std::string& _vnx_name)
	:	Module::Module(_vnx_name)
{
	vnx::read_config(vnx_name + ".height", height);
	vnx::read_config(vnx_name + ".interval_ms", interval_ms);
	vnx::read_config(vnx_name + ".output", output);
	vnx::read_config(vnx_name + ".width", width);
}

vnx::Hash64 CameraSensorBase::get_type_hash() const {
	return VNX_TYPE_HASH;
}

const char* CameraSensorBase::get_type_name() const {
	return "example.CameraSensor";
}

void CameraSensorBase::accept(vnx::Visitor& _visitor) const {
	const vnx::TypeCode* _type_code = get_type_code();
	_visitor.type_begin(*_type_code);
	_visitor.type_field(_type_code->fields[0], 0); vnx::accept(_visitor, output);
	_visitor.type_field(_type_code->fields[1], 1); vnx::accept(_visitor, width);
	_visitor.type_field(_type_code->fields[2], 2); vnx::accept(_visitor, height);
	_visitor.type_field(_type_code->fields[3], 3); vnx::accept(_visitor, interval_ms);
	_visitor.type_end(*_type_code);
}

void CameraSensorBase::write(std::ostream& _out) const {
	_out << "{";
	_out << "\"output\": "; vnx::write(_out, output);
	_out << ", \"width\": "; vnx::write(_out, width);
	_out << ", \"height\": "; vnx::write(_out, height);
	_out << ", \"interval_ms\": "; vnx::write(_out, interval_ms);
	_out << "}";
}

void CameraSensorBase::read(std::istream& _in) {
	std::map<std::string, std::string> _object;
	vnx::read_object(_in, _object);
	for(const auto& _entry : _object) {
		if(_entry.first == "height") {
			vnx::from_string(_entry.second, height);
		} else if(_entry.first == "interval_ms") {
			vnx::from_string(_entry.second, interval_ms);
		} else if(_entry.first == "output") {
			vnx::from_string(_entry.second, output);
		} else if(_entry.first == "width") {
			vnx::from_string(_entry.second, width);
		}
	}
}

vnx::Object CameraSensorBase::to_object() const {
	vnx::Object _object;
	_object["output"] = output;
	_object["width"] = width;
	_object["height"] = height;
	_object["interval_ms"] = interval_ms;
	return _object;
}

void CameraSensorBase::from_object(const vnx::Object& _object) {
	for(const auto& _entry : _object.field) {
		if(_entry.first == "height") {
			_entry.second.to(height);
		} else if(_entry.first == "interval_ms") {
			_entry.second.to(interval_ms);
		} else if(_entry.first == "output") {
			_entry.second.to(output);
		} else if(_entry.first == "width") {
			_entry.second.to(width);
		}
	}
}

/// \private
std::ostream& operator<<(std::ostream& _out, const CameraSensorBase& _value) {
	_value.write(_out);
	return _out;
}

/// \private
std::istream& operator>>(std::istream& _in, CameraSensorBase& _value) {
	_value.read(_in);
	return _in;
}

const vnx::TypeCode* CameraSensorBase::get_type_code() {
	const vnx::TypeCode* type_code = vnx::get_type_code(vnx::Hash64(0x2201bbd3b25391ebull));
	if(!type_code) {
		type_code = vnx::register_type_code(create_type_code());
	}
	return type_code;
}

std::shared_ptr<vnx::TypeCode> CameraSensorBase::create_type_code() {
	std::shared_ptr<vnx::TypeCode> type_code = std::make_shared<vnx::TypeCode>(true);
	type_code->name = "example.CameraSensor";
	type_code->type_hash = vnx::Hash64(0x2201bbd3b25391ebull);
	type_code->code_hash = vnx::Hash64(0xb632f00cbbf2a585ull);
	type_code->methods.resize(0);
	type_code->fields.resize(4);
	{
		vnx::TypeField& field = type_code->fields[0];
		field.is_extended = true;
		field.name = "output";
		field.code = {12, 5};
	}
	{
		vnx::TypeField& field = type_code->fields[1];
		field.name = "width";
		field.value = vnx::to_string(2048);
		field.code = {3};
	}
	{
		vnx::TypeField& field = type_code->fields[2];
		field.name = "height";
		field.value = vnx::to_string(1024);
		field.code = {3};
	}
	{
		vnx::TypeField& field = type_code->fields[3];
		field.name = "interval_ms";
		field.value = vnx::to_string(100);
		field.code = {3};
	}
	type_code->build();
	return type_code;
}

void CameraSensorBase::handle_switch(std::shared_ptr<const ::vnx::Sample> _sample) {
	const uint64_t _type_hash = _sample->value->get_type_hash();
}

bool CameraSensorBase::call_switch(vnx::TypeInput& _in, vnx::TypeOutput& _out, const vnx::TypeCode* _call_type, const vnx::TypeCode* _return_type) {
	return false;
}


} // namespace example


namespace vnx {

void read(TypeInput& in, ::example::CameraSensorBase& value, const TypeCode* type_code, const uint16_t* code) {
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
			const vnx::TypeField* const _field = type_code->field_map[1];
			if(_field) {
				vnx::read_value(_buf + _field->offset, value.width, _field->code.data());
			}
		}
		{
			const vnx::TypeField* const _field = type_code->field_map[2];
			if(_field) {
				vnx::read_value(_buf + _field->offset, value.height, _field->code.data());
			}
		}
		{
			const vnx::TypeField* const _field = type_code->field_map[3];
			if(_field) {
				vnx::read_value(_buf + _field->offset, value.interval_ms, _field->code.data());
			}
		}
	}
	for(const vnx::TypeField* _field : type_code->ext_fields) {
		switch(_field->native_index) {
			case 0: vnx::read(in, value.output, type_code, _field->code.data()); break;
			default: vnx::skip(in, type_code, _field->code.data());
		}
	}
}

void write(TypeOutput& out, const ::example::CameraSensorBase& value, const TypeCode* type_code, const uint16_t* code) {
	if(!type_code || (code && code[0] == CODE_ANY)) {
		type_code = vnx::write_type_code<::example::CameraSensorBase>(out);
		vnx::write_class_header<::example::CameraSensorBase>(out);
	}
	if(code && code[0] == CODE_STRUCT) {
		type_code = type_code->depends[code[1]];
	}
	char* const _buf = out.write(12);
	vnx::write_value(_buf + 0, value.width);
	vnx::write_value(_buf + 4, value.height);
	vnx::write_value(_buf + 8, value.interval_ms);
	vnx::write(out, value.output, type_code, type_code->fields[0].code.data());
}

void read(std::istream& in, ::example::CameraSensorBase& value) {
	value.read(in);
}

void write(std::ostream& out, const ::example::CameraSensorBase& value) {
	value.write(out);
}

void accept(Visitor& visitor, const ::example::CameraSensorBase& value) {
	value.accept(visitor);
}

} // vnx
