
// AUTO GENERATED by vnxcppcodegen

#include <example/package.hxx>
#include <example/InputOutputError.hxx>
#include <vnx/Input.h>
#include <vnx/Output.h>
#include <vnx/Visitor.h>
#include <vnx/Object.h>
#include <vnx/Struct.h>


namespace example {


const vnx::Hash64 InputOutputError::VNX_TYPE_HASH(0x1443a327225d003full);
const vnx::Hash64 InputOutputError::VNX_CODE_HASH(0xffa00a1cdfb78693ull);

vnx::Hash64 InputOutputError::get_type_hash() const {
	return VNX_TYPE_HASH;
}

const char* InputOutputError::get_type_name() const {
	return "example.InputOutputError";
}
const vnx::TypeCode* InputOutputError::get_type_code() const {
	return example::vnx_native_type_code_InputOutputError;
}

std::shared_ptr<InputOutputError> InputOutputError::create() {
	return std::make_shared<InputOutputError>();
}

std::shared_ptr<vnx::Value> InputOutputError::clone() const {
	return std::make_shared<InputOutputError>(*this);
}

void InputOutputError::read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code) {
	vnx::read(_in, *this, _type_code, _code);
}

void InputOutputError::write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const {
	vnx::write(_out, *this, _type_code, _code);
}

void InputOutputError::accept(vnx::Visitor& _visitor) const {
	const vnx::TypeCode* _type_code = example::vnx_native_type_code_InputOutputError;
	_visitor.type_begin(*_type_code);
	_visitor.type_field(_type_code->fields[0], 0); vnx::accept(_visitor, what);
	_visitor.type_end(*_type_code);
}

void InputOutputError::write(std::ostream& _out) const {
	_out << "{";
	_out << "\"what\": "; vnx::write(_out, what);
	_out << "}";
}

void InputOutputError::read(std::istream& _in) {
	std::map<std::string, std::string> _object;
	vnx::read_object(_in, _object);
	for(const auto& _entry : _object) {
		if(_entry.first == "what") {
			vnx::from_string(_entry.second, what);
		}
	}
}

vnx::Object InputOutputError::to_object() const {
	vnx::Object _object;
	_object["what"] = what;
	return _object;
}

void InputOutputError::from_object(const vnx::Object& _object) {
	for(const auto& _entry : _object.field) {
		if(_entry.first == "what") {
			_entry.second.to(what);
		}
	}
}

/// \private
std::ostream& operator<<(std::ostream& _out, const InputOutputError& _value) {
	_value.write(_out);
	return _out;
}

/// \private
std::istream& operator>>(std::istream& _in, InputOutputError& _value) {
	_value.read(_in);
	return _in;
}

const vnx::TypeCode* InputOutputError::static_get_type_code() {
	const vnx::TypeCode* type_code = vnx::get_type_code(vnx::Hash64(0x1443a327225d003full));
	if(!type_code) {
		type_code = vnx::register_type_code(static_create_type_code());
	}
	return type_code;
}

std::shared_ptr<vnx::TypeCode> InputOutputError::static_create_type_code() {
	std::shared_ptr<vnx::TypeCode> type_code = std::make_shared<vnx::TypeCode>(true);
	type_code->name = "example.InputOutputError";
	type_code->type_hash = vnx::Hash64(0x1443a327225d003full);
	type_code->code_hash = vnx::Hash64(0xffa00a1cdfb78693ull);
	type_code->is_class = true;
	type_code->parents.resize(1);
	type_code->parents[0] = ::vnx::Exception::static_get_type_code();
	type_code->create_value = []() -> std::shared_ptr<vnx::Value> { return std::make_shared<InputOutputError>(); };
	type_code->methods.resize(0);
	type_code->fields.resize(1);
	{
		vnx::TypeField& field = type_code->fields[0];
		field.is_extended = true;
		field.name = "what";
		field.code = {12, 5};
	}
	type_code->build();
	return type_code;
}


} // namespace example


namespace vnx {

void read(TypeInput& in, ::example::InputOutputError& value, const TypeCode* type_code, const uint16_t* code) {
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
	}
	for(const vnx::TypeField* _field : type_code->ext_fields) {
		switch(_field->native_index) {
			case 0: vnx::read(in, value.what, type_code, _field->code.data()); break;
			default: vnx::skip(in, type_code, _field->code.data());
		}
	}
}

void write(TypeOutput& out, const ::example::InputOutputError& value, const TypeCode* type_code, const uint16_t* code) {
	if(!type_code || (code && code[0] == CODE_ANY)) {
		type_code = example::vnx_native_type_code_InputOutputError;
		out.write_type_code(type_code);
		vnx::write_class_header<::example::InputOutputError>(out);
	}
	if(code && code[0] == CODE_STRUCT) {
		type_code = type_code->depends[code[1]];
	}
	vnx::write(out, value.what, type_code, type_code->fields[0].code.data());
}

void read(std::istream& in, ::example::InputOutputError& value) {
	value.read(in);
}

void write(std::ostream& out, const ::example::InputOutputError& value) {
	value.write(out);
}

void accept(Visitor& visitor, const ::example::InputOutputError& value) {
	value.accept(visitor);
}

} // vnx
