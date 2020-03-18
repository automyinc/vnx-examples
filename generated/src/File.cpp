
// AUTO GENERATED by vnxcppcodegen

#include <example/package.hxx>
#include <example/File.hxx>
#include <vnx/Input.h>
#include <vnx/Output.h>
#include <vnx/Visitor.h>
#include <vnx/Object.h>
#include <vnx/Struct.h>


namespace example {


const vnx::Hash64 File::VNX_TYPE_HASH(0x8742ecc1bab8119eull);
const vnx::Hash64 File::VNX_CODE_HASH(0x86868f35b71c4dcull);

vnx::Hash64 File::get_type_hash() const {
	return VNX_TYPE_HASH;
}

const char* File::get_type_name() const {
	return "example.File";
}

std::shared_ptr<File> File::create() {
	return std::make_shared<File>();
}

std::shared_ptr<vnx::Value> File::clone() const {
	return std::make_shared<File>(*this);
}

void File::read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code) {
	vnx::read(_in, *this, _type_code, _code);
}

void File::write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const {
	vnx::write(_out, *this, _type_code, _code);
}

void File::accept(vnx::Visitor& _visitor) const {
	const vnx::TypeCode* _type_code = example::vnx_native_type_code_File;
	_visitor.type_begin(*_type_code);
	_visitor.type_field(_type_code->fields[0], 0); vnx::accept(_visitor, file_name);
	_visitor.type_field(_type_code->fields[1], 1); vnx::accept(_visitor, contents);
	_visitor.type_end(*_type_code);
}

void File::write(std::ostream& _out) const {
	_out << "{";
	_out << "\"file_name\": "; vnx::write(_out, file_name);
	_out << ", \"contents\": "; vnx::write(_out, contents);
	_out << "}";
}

void File::read(std::istream& _in) {
	std::map<std::string, std::string> _object;
	vnx::read_object(_in, _object);
	for(const auto& _entry : _object) {
		if(_entry.first == "contents") {
			vnx::from_string(_entry.second, contents);
		} else if(_entry.first == "file_name") {
			vnx::from_string(_entry.second, file_name);
		}
	}
}

vnx::Object File::to_object() const {
	vnx::Object _object;
	_object["file_name"] = file_name;
	_object["contents"] = contents;
	return _object;
}

void File::from_object(const vnx::Object& _object) {
	for(const auto& _entry : _object.field) {
		if(_entry.first == "contents") {
			_entry.second.to(contents);
		} else if(_entry.first == "file_name") {
			_entry.second.to(file_name);
		}
	}
}

/// \private
std::ostream& operator<<(std::ostream& _out, const File& _value) {
	_value.write(_out);
	return _out;
}

/// \private
std::istream& operator>>(std::istream& _in, File& _value) {
	_value.read(_in);
	return _in;
}

const vnx::TypeCode* File::get_type_code() {
	const vnx::TypeCode* type_code = vnx::get_type_code(vnx::Hash64(0x8742ecc1bab8119eull));
	if(!type_code) {
		type_code = vnx::register_type_code(create_type_code());
	}
	return type_code;
}

std::shared_ptr<vnx::TypeCode> File::create_type_code() {
	std::shared_ptr<vnx::TypeCode> type_code = std::make_shared<vnx::TypeCode>(true);
	type_code->name = "example.File";
	type_code->type_hash = vnx::Hash64(0x8742ecc1bab8119eull);
	type_code->code_hash = vnx::Hash64(0x86868f35b71c4dcull);
	type_code->is_class = true;
	type_code->create_value = []() -> std::shared_ptr<vnx::Value> { return std::make_shared<File>(); };
	type_code->methods.resize(0);
	type_code->fields.resize(2);
	{
		vnx::TypeField& field = type_code->fields[0];
		field.is_extended = true;
		field.name = "file_name";
		field.code = {12, 5};
	}
	{
		vnx::TypeField& field = type_code->fields[1];
		field.is_extended = true;
		field.name = "contents";
		field.code = {12, 1};
	}
	type_code->build();
	return type_code;
}


} // namespace example


namespace vnx {

void read(TypeInput& in, ::example::File& value, const TypeCode* type_code, const uint16_t* code) {
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
			case 0: vnx::read(in, value.file_name, type_code, _field->code.data()); break;
			case 1: vnx::read(in, value.contents, type_code, _field->code.data()); break;
			default: vnx::skip(in, type_code, _field->code.data());
		}
	}
}

void write(TypeOutput& out, const ::example::File& value, const TypeCode* type_code, const uint16_t* code) {
	if(!type_code || (code && code[0] == CODE_ANY)) {
		type_code = example::vnx_native_type_code_File;
		out.write_type_code(type_code);
		vnx::write_class_header<::example::File>(out);
	}
	if(code && code[0] == CODE_STRUCT) {
		type_code = type_code->depends[code[1]];
	}
	vnx::write(out, value.file_name, type_code, type_code->fields[0].code.data());
	vnx::write(out, value.contents, type_code, type_code->fields[1].code.data());
}

void read(std::istream& in, ::example::File& value) {
	value.read(in);
}

void write(std::ostream& out, const ::example::File& value) {
	value.write(out);
}

void accept(Visitor& visitor, const ::example::File& value) {
	value.accept(visitor);
}

} // vnx
