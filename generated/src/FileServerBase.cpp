
// AUTO GENERATED by vnxcppcodegen

#include <example/package.hxx>
#include <example/FileServerBase.hxx>
#include <vnx/Input.h>
#include <vnx/Output.h>
#include <vnx/Visitor.h>
#include <vnx/Object.h>
#include <vnx/Struct.h>
#include <vnx/Config.h>
#include <vnx/Binary.h>
#include <vnx/NoSuchMethod.hxx>


namespace example {


const vnx::Hash64 FileServerBase::VNX_TYPE_HASH(0x7361123445d5e0eull);
const vnx::Hash64 FileServerBase::VNX_CODE_HASH(0xcca6dc19b31d56eaull);

FileServerBase::FileServerBase(const std::string& _vnx_name)
	:	Module::Module(_vnx_name)
{
	vnx::read_config(vnx_name + ".num_threads", num_threads);
	vnx::read_config(vnx_name + ".root_path", root_path);
}

vnx::Hash64 FileServerBase::get_type_hash() const {
	return VNX_TYPE_HASH;
}

const char* FileServerBase::get_type_name() const {
	return "example.FileServer";
}
const vnx::TypeCode* FileServerBase::get_type_code() const {
	return example::vnx_native_type_code_FileServer;
}

void FileServerBase::accept(vnx::Visitor& _visitor) const {
	const vnx::TypeCode* _type_code = example::vnx_native_type_code_FileServer;
	_visitor.type_begin(*_type_code);
	_visitor.type_field(_type_code->fields[0], 0); vnx::accept(_visitor, root_path);
	_visitor.type_field(_type_code->fields[1], 1); vnx::accept(_visitor, num_threads);
	_visitor.type_end(*_type_code);
}

void FileServerBase::write(std::ostream& _out) const {
	_out << "{";
	_out << "\"root_path\": "; vnx::write(_out, root_path);
	_out << ", \"num_threads\": "; vnx::write(_out, num_threads);
	_out << "}";
}

void FileServerBase::read(std::istream& _in) {
	std::map<std::string, std::string> _object;
	vnx::read_object(_in, _object);
	for(const auto& _entry : _object) {
		if(_entry.first == "num_threads") {
			vnx::from_string(_entry.second, num_threads);
		} else if(_entry.first == "root_path") {
			vnx::from_string(_entry.second, root_path);
		}
	}
}

vnx::Object FileServerBase::to_object() const {
	vnx::Object _object;
	_object["root_path"] = root_path;
	_object["num_threads"] = num_threads;
	return _object;
}

void FileServerBase::from_object(const vnx::Object& _object) {
	for(const auto& _entry : _object.field) {
		if(_entry.first == "num_threads") {
			_entry.second.to(num_threads);
		} else if(_entry.first == "root_path") {
			_entry.second.to(root_path);
		}
	}
}

/// \private
std::ostream& operator<<(std::ostream& _out, const FileServerBase& _value) {
	_value.write(_out);
	return _out;
}

/// \private
std::istream& operator>>(std::istream& _in, FileServerBase& _value) {
	_value.read(_in);
	return _in;
}

const vnx::TypeCode* FileServerBase::static_get_type_code() {
	const vnx::TypeCode* type_code = vnx::get_type_code(vnx::Hash64(0x7361123445d5e0eull));
	if(!type_code) {
		type_code = vnx::register_type_code(static_create_type_code());
	}
	return type_code;
}

std::shared_ptr<vnx::TypeCode> FileServerBase::static_create_type_code() {
	std::shared_ptr<vnx::TypeCode> type_code = std::make_shared<vnx::TypeCode>(true);
	type_code->name = "example.FileServer";
	type_code->type_hash = vnx::Hash64(0x7361123445d5e0eull);
	type_code->code_hash = vnx::Hash64(0xcca6dc19b31d56eaull);
	type_code->methods.resize(1);
	{
		std::shared_ptr<vnx::TypeCode> call_type = std::make_shared<vnx::TypeCode>(true);
		call_type->name = "example.FileServer.get_file";
		call_type->type_hash = vnx::Hash64(0x3d103650f660b364ull);
		call_type->code_hash = vnx::Hash64(0x1551859a51a7d3c1ull);
		call_type->is_method = true;
		{
			std::shared_ptr<vnx::TypeCode> return_type = std::make_shared<vnx::TypeCode>(true);
			return_type->name = "example.FileServer.get_file.return";
			return_type->type_hash = vnx::Hash64(0x13362942844b1d03ull);
			return_type->code_hash = vnx::Hash64(0x8cde71bc46ad87d3ull);
			return_type->is_return = true;
			return_type->fields.resize(1);
			{
				vnx::TypeField& field = return_type->fields[0];
				field.is_extended = true;
				field.name = "_ret_0";
				field.code = {16};
			}
			return_type->build();
			call_type->return_type = vnx::register_type_code(return_type);
		}
		call_type->fields.resize(1);
		{
			vnx::TypeField& field = call_type->fields[0];
			field.is_extended = true;
			field.name = "file_name";
			field.code = {12, 5};
		}
		call_type->build();
		type_code->methods[0] = vnx::register_type_code(call_type);
	}
	type_code->fields.resize(2);
	{
		vnx::TypeField& field = type_code->fields[0];
		field.is_extended = true;
		field.name = "root_path";
		field.code = {12, 5};
	}
	{
		vnx::TypeField& field = type_code->fields[1];
		field.name = "num_threads";
		field.value = vnx::to_string(10);
		field.code = {7};
	}
	type_code->build();
	return type_code;
}

void FileServerBase::vnx_handle_switch(std::shared_ptr<const ::vnx::Sample> _sample) {
	const uint64_t _type_hash = _sample->value->get_type_hash();
}

std::shared_ptr<vnx::Value> FileServerBase::vnx_call_switch(vnx::TypeInput& _in, const vnx::TypeCode* _call_type, const vnx::request_id_t& _request_id) {
	if(_call_type->type_hash == vnx::Hash64(0x3d103650f660b364ull)) {
		::std::string file_name;
		{
			const char* const _buf = _in.read(_call_type->total_field_size);
			if(_call_type->is_matched) {
			}
			for(const vnx::TypeField* _field : _call_type->ext_fields) {
				switch(_field->native_index) {
					case 0: vnx::read(_in, file_name, _call_type, _field->code.data()); break;
					default: vnx::skip(_in, _call_type, _field->code.data());
				}
			}
		}
		get_file_async(file_name, std::bind(&FileServerBase::get_file_async_return, this, _request_id, std::placeholders::_1), _request_id);
		return 0;
	}
	auto _ex = vnx::NoSuchMethod::create();
	_ex->method = _call_type->name;
	return _ex;
}

void FileServerBase::get_file_async_return(const vnx::request_id_t& _request_id, const ::std::shared_ptr<const ::example::File>& _ret_0) {
	std::shared_ptr<vnx::Binary> _return_value;
	const vnx::TypeCode* _return_type = example::vnx_native_type_code_FileServer_get_file_return;
	_return_value = vnx::Binary::create();
	_return_value->type_code = _return_type;
	vnx::BinaryOutputStream _stream_out(_return_value.get());
	vnx::TypeOutput _out(&_stream_out);
	vnx::write(_out, _ret_0, _return_type, _return_type->fields[0].code.data());
	_out.flush();
	vnx_async_return(_request_id, _return_value);
}


} // namespace example


namespace vnx {

void read(TypeInput& in, ::example::FileServerBase& value, const TypeCode* type_code, const uint16_t* code) {
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
				vnx::read_value(_buf + _field->offset, value.num_threads, _field->code.data());
			}
		}
	}
	for(const vnx::TypeField* _field : type_code->ext_fields) {
		switch(_field->native_index) {
			case 0: vnx::read(in, value.root_path, type_code, _field->code.data()); break;
			default: vnx::skip(in, type_code, _field->code.data());
		}
	}
}

void write(TypeOutput& out, const ::example::FileServerBase& value, const TypeCode* type_code, const uint16_t* code) {
	if(!type_code || (code && code[0] == CODE_ANY)) {
		type_code = example::vnx_native_type_code_FileServer;
		out.write_type_code(type_code);
		vnx::write_class_header<::example::FileServerBase>(out);
	}
	if(code && code[0] == CODE_STRUCT) {
		type_code = type_code->depends[code[1]];
	}
	char* const _buf = out.write(4);
	vnx::write_value(_buf + 0, value.num_threads);
	vnx::write(out, value.root_path, type_code, type_code->fields[0].code.data());
}

void read(std::istream& in, ::example::FileServerBase& value) {
	value.read(in);
}

void write(std::ostream& out, const ::example::FileServerBase& value) {
	value.write(out);
}

void accept(Visitor& visitor, const ::example::FileServerBase& value) {
	value.accept(visitor);
}

} // vnx