
// AUTO GENERATED by vnxcppcodegen

#include <example/package.hxx>
#include <example/User.hxx>
#include <vnx/Input.h>
#include <vnx/Output.h>
#include <vnx/Visitor.h>
#include <vnx/Object.h>
#include <vnx/Struct.h>


namespace example {


const vnx::Hash64 User::VNX_TYPE_HASH(0x29f409d7512427eaull);
const vnx::Hash64 User::VNX_CODE_HASH(0xee1c9fbd329bbc95ull);

vnx::Hash64 User::get_type_hash() const {
	return VNX_TYPE_HASH;
}

const char* User::get_type_name() const {
	return "example.User";
}
const vnx::TypeCode* User::get_type_code() const {
	return example::vnx_native_type_code_User;
}

std::shared_ptr<User> User::create() {
	return std::make_shared<User>();
}

std::shared_ptr<vnx::Value> User::clone() const {
	return std::make_shared<User>(*this);
}

void User::read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code) {
	vnx::read(_in, *this, _type_code, _code);
}

void User::write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const {
	vnx::write(_out, *this, _type_code, _code);
}

void User::accept(vnx::Visitor& _visitor) const {
	const vnx::TypeCode* _type_code = example::vnx_native_type_code_User;
	_visitor.type_begin(*_type_code);
	_visitor.type_field(_type_code->fields[0], 0); vnx::accept(_visitor, name);
	_visitor.type_field(_type_code->fields[1], 1); vnx::accept(_visitor, balance);
	_visitor.type_end(*_type_code);
}

void User::write(std::ostream& _out) const {
	_out << "{";
	_out << "\"name\": "; vnx::write(_out, name);
	_out << ", \"balance\": "; vnx::write(_out, balance);
	_out << "}";
}

void User::read(std::istream& _in) {
	std::map<std::string, std::string> _object;
	vnx::read_object(_in, _object);
	for(const auto& _entry : _object) {
		if(_entry.first == "balance") {
			vnx::from_string(_entry.second, balance);
		} else if(_entry.first == "name") {
			vnx::from_string(_entry.second, name);
		}
	}
}

vnx::Object User::to_object() const {
	vnx::Object _object;
	_object["name"] = name;
	_object["balance"] = balance;
	return _object;
}

void User::from_object(const vnx::Object& _object) {
	for(const auto& _entry : _object.field) {
		if(_entry.first == "balance") {
			_entry.second.to(balance);
		} else if(_entry.first == "name") {
			_entry.second.to(name);
		}
	}
}

/// \private
std::ostream& operator<<(std::ostream& _out, const User& _value) {
	_value.write(_out);
	return _out;
}

/// \private
std::istream& operator>>(std::istream& _in, User& _value) {
	_value.read(_in);
	return _in;
}

const vnx::TypeCode* User::static_get_type_code() {
	const vnx::TypeCode* type_code = vnx::get_type_code(vnx::Hash64(0x29f409d7512427eaull));
	if(!type_code) {
		type_code = vnx::register_type_code(static_create_type_code());
	}
	return type_code;
}

std::shared_ptr<vnx::TypeCode> User::static_create_type_code() {
	std::shared_ptr<vnx::TypeCode> type_code = std::make_shared<vnx::TypeCode>(true);
	type_code->name = "example.User";
	type_code->type_hash = vnx::Hash64(0x29f409d7512427eaull);
	type_code->code_hash = vnx::Hash64(0xee1c9fbd329bbc95ull);
	type_code->is_class = true;
	type_code->create_value = []() -> std::shared_ptr<vnx::Value> { return std::make_shared<User>(); };
	type_code->methods.resize(0);
	type_code->fields.resize(2);
	{
		vnx::TypeField& field = type_code->fields[0];
		field.is_extended = true;
		field.name = "name";
		field.code = {12, 5};
	}
	{
		vnx::TypeField& field = type_code->fields[1];
		field.name = "balance";
		field.code = {10};
	}
	type_code->build();
	return type_code;
}


} // namespace example


namespace vnx {

void read(TypeInput& in, ::example::User& value, const TypeCode* type_code, const uint16_t* code) {
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
				vnx::read_value(_buf + _field->offset, value.balance, _field->code.data());
			}
		}
	}
	for(const vnx::TypeField* _field : type_code->ext_fields) {
		switch(_field->native_index) {
			case 0: vnx::read(in, value.name, type_code, _field->code.data()); break;
			default: vnx::skip(in, type_code, _field->code.data());
		}
	}
}

void write(TypeOutput& out, const ::example::User& value, const TypeCode* type_code, const uint16_t* code) {
	if(!type_code || (code && code[0] == CODE_ANY)) {
		type_code = example::vnx_native_type_code_User;
		out.write_type_code(type_code);
		vnx::write_class_header<::example::User>(out);
	}
	if(code && code[0] == CODE_STRUCT) {
		type_code = type_code->depends[code[1]];
	}
	char* const _buf = out.write(8);
	vnx::write_value(_buf + 0, value.balance);
	vnx::write(out, value.name, type_code, type_code->fields[0].code.data());
}

void read(std::istream& in, ::example::User& value) {
	value.read(in);
}

void write(std::ostream& out, const ::example::User& value) {
	value.write(out);
}

void accept(Visitor& visitor, const ::example::User& value) {
	value.accept(visitor);
}

} // vnx
