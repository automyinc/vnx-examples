
// AUTO GENERATED by vnxcppcodegen

#include <example/package.hxx>
#include <example/DatabaseBase.hxx>
#include <vnx/Input.h>
#include <vnx/Output.h>
#include <vnx/Visitor.h>
#include <vnx/Object.h>
#include <vnx/Struct.h>
#include <vnx/Config.h>


namespace example {


const vnx::Hash64 DatabaseBase::VNX_TYPE_HASH(0x8d362075de8ee5efull);
const vnx::Hash64 DatabaseBase::VNX_CODE_HASH(0x3a9832bfc5d20720ull);

DatabaseBase::DatabaseBase(const std::string& _vnx_name)
	:	Module::Module(_vnx_name)
{
	vnx::read_config(vnx_name + ".input", input);
}

vnx::Hash64 DatabaseBase::get_type_hash() const {
	return VNX_TYPE_HASH;
}

const char* DatabaseBase::get_type_name() const {
	return "example.Database";
}

void DatabaseBase::accept(vnx::Visitor& _visitor) const {
	const vnx::TypeCode* _type_code = get_type_code();
	_visitor.type_begin(*_type_code);
	_visitor.type_field(_type_code->fields[0], 0); vnx::accept(_visitor, input);
	_visitor.type_end(*_type_code);
}

void DatabaseBase::write(std::ostream& _out) const {
	_out << "{";
	_out << "\"input\": "; vnx::write(_out, input);
	_out << "}";
}

void DatabaseBase::read(std::istream& _in) {
	std::map<std::string, std::string> _object;
	vnx::read_object(_in, _object);
	for(const auto& _entry : _object) {
		if(_entry.first == "input") {
			vnx::from_string(_entry.second, input);
		}
	}
}

vnx::Object DatabaseBase::to_object() const {
	vnx::Object _object;
	_object["input"] = input;
	return _object;
}

void DatabaseBase::from_object(const vnx::Object& _object) {
	for(const auto& _entry : _object.field) {
		if(_entry.first == "input") {
			_entry.second.to(input);
		}
	}
}

/// \private
std::ostream& operator<<(std::ostream& _out, const DatabaseBase& _value) {
	_value.write(_out);
	return _out;
}

/// \private
std::istream& operator>>(std::istream& _in, DatabaseBase& _value) {
	_value.read(_in);
	return _in;
}

const vnx::TypeCode* DatabaseBase::get_type_code() {
	const vnx::TypeCode* type_code = vnx::get_type_code(vnx::Hash64(0x8d362075de8ee5efull));
	if(!type_code) {
		type_code = vnx::register_type_code(create_type_code());
	}
	return type_code;
}

std::shared_ptr<vnx::TypeCode> DatabaseBase::create_type_code() {
	std::shared_ptr<vnx::TypeCode> type_code = std::make_shared<vnx::TypeCode>(true);
	type_code->name = "example.Database";
	type_code->type_hash = vnx::Hash64(0x8d362075de8ee5efull);
	type_code->code_hash = vnx::Hash64(0x3a9832bfc5d20720ull);
	type_code->methods.resize(6);
	{
		std::shared_ptr<vnx::TypeCode> call_type = std::make_shared<vnx::TypeCode>(true);
		call_type->name = "example.Database.add_user";
		call_type->type_hash = vnx::Hash64(0x2741180fbb8f23a1ull);
		call_type->code_hash = vnx::Hash64(0x34b9325b4297690eull);
		call_type->is_method = true;
		{
			std::shared_ptr<vnx::TypeCode> return_type = std::make_shared<vnx::TypeCode>(true);
			return_type->name = "example.Database.add_user.return";
			return_type->type_hash = vnx::Hash64(0x73df74b7d405f6b0ull);
			return_type->code_hash = vnx::Hash64(0x6b8c2257a0ee219cull);
			return_type->is_return = true;
			return_type->build();
			call_type->return_type = vnx::register_type_code(return_type);
		}
		call_type->fields.resize(1);
		{
			vnx::TypeField& field = call_type->fields[0];
			field.is_extended = true;
			field.name = "name";
			field.code = {12, 5};
		}
		call_type->build();
		type_code->methods[0] = vnx::register_type_code(call_type);
	}
	{
		std::shared_ptr<vnx::TypeCode> call_type = std::make_shared<vnx::TypeCode>(true);
		call_type->name = "example.Database.add_user_balance";
		call_type->type_hash = vnx::Hash64(0x3d6e042d45e04326ull);
		call_type->code_hash = vnx::Hash64(0x376338c76c60ba39ull);
		call_type->is_method = true;
		{
			std::shared_ptr<vnx::TypeCode> return_type = std::make_shared<vnx::TypeCode>(true);
			return_type->name = "example.Database.add_user_balance.return";
			return_type->type_hash = vnx::Hash64(0xce8eb9027f2289c3ull);
			return_type->code_hash = vnx::Hash64(0xcc09df8379dcb0a3ull);
			return_type->is_return = true;
			return_type->build();
			call_type->return_type = vnx::register_type_code(return_type);
		}
		call_type->fields.resize(2);
		{
			vnx::TypeField& field = call_type->fields[0];
			field.is_extended = true;
			field.name = "name";
			field.code = {12, 5};
		}
		{
			vnx::TypeField& field = call_type->fields[1];
			field.name = "value";
			field.code = {10};
		}
		call_type->build();
		type_code->methods[1] = vnx::register_type_code(call_type);
	}
	{
		std::shared_ptr<vnx::TypeCode> call_type = std::make_shared<vnx::TypeCode>(true);
		call_type->name = "example.Database.get_user";
		call_type->type_hash = vnx::Hash64(0x3e6f70937269a136ull);
		call_type->code_hash = vnx::Hash64(0xc95b2f4f5838f925ull);
		call_type->is_method = true;
		{
			std::shared_ptr<vnx::TypeCode> return_type = std::make_shared<vnx::TypeCode>(true);
			return_type->name = "example.Database.get_user.return";
			return_type->type_hash = vnx::Hash64(0x36d19b92367474d9ull);
			return_type->code_hash = vnx::Hash64(0x40cbb5f97573d661ull);
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
			field.name = "name";
			field.code = {12, 5};
		}
		call_type->build();
		type_code->methods[2] = vnx::register_type_code(call_type);
	}
	{
		std::shared_ptr<vnx::TypeCode> call_type = std::make_shared<vnx::TypeCode>(true);
		call_type->name = "example.Database.get_user_balance";
		call_type->type_hash = vnx::Hash64(0xe625a8cfd51e9a9eull);
		call_type->code_hash = vnx::Hash64(0x80f51ff269fb19ecull);
		call_type->is_method = true;
		{
			std::shared_ptr<vnx::TypeCode> return_type = std::make_shared<vnx::TypeCode>(true);
			return_type->name = "example.Database.get_user_balance.return";
			return_type->type_hash = vnx::Hash64(0x50b361140a464af7ull);
			return_type->code_hash = vnx::Hash64(0x9d38cba9437ca6ccull);
			return_type->is_return = true;
			return_type->fields.resize(1);
			{
				vnx::TypeField& field = return_type->fields[0];
				field.name = "_ret_0";
				field.code = {10};
			}
			return_type->build();
			call_type->return_type = vnx::register_type_code(return_type);
		}
		call_type->fields.resize(1);
		{
			vnx::TypeField& field = call_type->fields[0];
			field.is_extended = true;
			field.name = "name";
			field.code = {12, 5};
		}
		call_type->build();
		type_code->methods[3] = vnx::register_type_code(call_type);
	}
	{
		std::shared_ptr<vnx::TypeCode> call_type = std::make_shared<vnx::TypeCode>(true);
		call_type->name = "example.Database.handle_example_Transaction";
		call_type->type_hash = vnx::Hash64(0xa9a81442632b020eull);
		call_type->code_hash = vnx::Hash64(0xce06df0c86ca0b44ull);
		call_type->is_method = true;
		{
			std::shared_ptr<vnx::TypeCode> return_type = std::make_shared<vnx::TypeCode>(true);
			return_type->name = "example.Database.handle_example_Transaction.return";
			return_type->type_hash = vnx::Hash64(0xa6ede797ad62d986ull);
			return_type->code_hash = vnx::Hash64(0x3255fff283d23e37ull);
			return_type->is_return = true;
			return_type->build();
			call_type->return_type = vnx::register_type_code(return_type);
		}
		call_type->fields.resize(1);
		{
			vnx::TypeField& field = call_type->fields[0];
			field.is_extended = true;
			field.name = "sample";
			field.code = {16};
		}
		call_type->build();
		type_code->methods[4] = vnx::register_type_code(call_type);
	}
	{
		std::shared_ptr<vnx::TypeCode> call_type = std::make_shared<vnx::TypeCode>(true);
		call_type->name = "example.Database.subtract_user_balance";
		call_type->type_hash = vnx::Hash64(0xe58127da78610817ull);
		call_type->code_hash = vnx::Hash64(0xe73ce1cfed64567eull);
		call_type->is_method = true;
		{
			std::shared_ptr<vnx::TypeCode> return_type = std::make_shared<vnx::TypeCode>(true);
			return_type->name = "example.Database.subtract_user_balance.return";
			return_type->type_hash = vnx::Hash64(0x602e1ee9204ea132ull);
			return_type->code_hash = vnx::Hash64(0x2e113be5a7c21c1aull);
			return_type->is_return = true;
			return_type->build();
			call_type->return_type = vnx::register_type_code(return_type);
		}
		call_type->fields.resize(2);
		{
			vnx::TypeField& field = call_type->fields[0];
			field.is_extended = true;
			field.name = "name";
			field.code = {12, 5};
		}
		{
			vnx::TypeField& field = call_type->fields[1];
			field.name = "value";
			field.code = {10};
		}
		call_type->build();
		type_code->methods[5] = vnx::register_type_code(call_type);
	}
	type_code->fields.resize(1);
	{
		vnx::TypeField& field = type_code->fields[0];
		field.is_extended = true;
		field.name = "input";
		field.code = {12, 5};
	}
	type_code->build();
	return type_code;
}

void DatabaseBase::handle_switch(std::shared_ptr<const ::vnx::Sample> _sample) {
	const uint64_t _type_hash = _sample->value->get_type_hash();
	if(_type_hash == 0xcac4a4d10cff0323ull) {
		std::shared_ptr<const example::Transaction> _value = std::dynamic_pointer_cast<const example::Transaction>(_sample->value);
		if(_value) {
			handle(_value, _sample);
		}
	}
}

bool DatabaseBase::call_switch(vnx::TypeInput& _in, vnx::TypeOutput& _out, const vnx::TypeCode* _call_type, const vnx::TypeCode* _return_type) {
	if(_call_type->type_hash == vnx::Hash64(0x2741180fbb8f23a1ull)) {
		::std::string name;
		const char* const _buf = _in.read(_call_type->total_field_size);
		if(_call_type->is_matched) {
		}
		for(const vnx::TypeField* _field : _call_type->ext_fields) {
			switch(_field->native_index) {
				case 0: vnx::read(_in, name, _call_type, _field->code.data()); break;
				default: vnx::skip(_in, _call_type, _field->code.data());
			}
		}
		add_user(name);
		return true;
	} else if(_call_type->type_hash == vnx::Hash64(0x3d6e042d45e04326ull)) {
		::std::string name;
		::vnx::float64_t value = 0;
		const char* const _buf = _in.read(_call_type->total_field_size);
		if(_call_type->is_matched) {
			{
				const vnx::TypeField* const _field = _call_type->field_map[1];
				if(_field) {
					vnx::read_value(_buf + _field->offset, value, _field->code.data());
				}
			}
		}
		for(const vnx::TypeField* _field : _call_type->ext_fields) {
			switch(_field->native_index) {
				case 0: vnx::read(_in, name, _call_type, _field->code.data()); break;
				default: vnx::skip(_in, _call_type, _field->code.data());
			}
		}
		add_user_balance(name, value);
		return true;
	} else if(_call_type->type_hash == vnx::Hash64(0x3e6f70937269a136ull)) {
		::std::string name;
		const char* const _buf = _in.read(_call_type->total_field_size);
		if(_call_type->is_matched) {
		}
		for(const vnx::TypeField* _field : _call_type->ext_fields) {
			switch(_field->native_index) {
				case 0: vnx::read(_in, name, _call_type, _field->code.data()); break;
				default: vnx::skip(_in, _call_type, _field->code.data());
			}
		}
		::std::shared_ptr<const ::example::User> _ret_0;
		_ret_0 = get_user(name);
		{
			vnx::write(_out, _ret_0, _return_type, _return_type->fields[0].code.data());
		}
		return true;
	} else if(_call_type->type_hash == vnx::Hash64(0xe625a8cfd51e9a9eull)) {
		::std::string name;
		const char* const _buf = _in.read(_call_type->total_field_size);
		if(_call_type->is_matched) {
		}
		for(const vnx::TypeField* _field : _call_type->ext_fields) {
			switch(_field->native_index) {
				case 0: vnx::read(_in, name, _call_type, _field->code.data()); break;
				default: vnx::skip(_in, _call_type, _field->code.data());
			}
		}
		::vnx::float64_t _ret_0 = 0;
		_ret_0 = get_user_balance(name);
		{
			char* const _buf = _out.write(8);
			vnx::write_value(_buf + 0, _ret_0);
		}
		return true;
	} else if(_call_type->type_hash == vnx::Hash64(0xa9a81442632b020eull)) {
		::std::shared_ptr<const ::example::Transaction> sample;
		const char* const _buf = _in.read(_call_type->total_field_size);
		if(_call_type->is_matched) {
		}
		for(const vnx::TypeField* _field : _call_type->ext_fields) {
			switch(_field->native_index) {
				case 0: vnx::read(_in, sample, _call_type, _field->code.data()); break;
				default: vnx::skip(_in, _call_type, _field->code.data());
			}
		}
		handle(sample);
		return true;
	} else if(_call_type->type_hash == vnx::Hash64(0xe58127da78610817ull)) {
		::std::string name;
		::vnx::float64_t value = 0;
		const char* const _buf = _in.read(_call_type->total_field_size);
		if(_call_type->is_matched) {
			{
				const vnx::TypeField* const _field = _call_type->field_map[1];
				if(_field) {
					vnx::read_value(_buf + _field->offset, value, _field->code.data());
				}
			}
		}
		for(const vnx::TypeField* _field : _call_type->ext_fields) {
			switch(_field->native_index) {
				case 0: vnx::read(_in, name, _call_type, _field->code.data()); break;
				default: vnx::skip(_in, _call_type, _field->code.data());
			}
		}
		subtract_user_balance(name, value);
		return true;
	}
	return false;
}


} // namespace example


namespace vnx {

void read(TypeInput& in, ::example::DatabaseBase& value, const TypeCode* type_code, const uint16_t* code) {
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
			case 0: vnx::read(in, value.input, type_code, _field->code.data()); break;
			default: vnx::skip(in, type_code, _field->code.data());
		}
	}
}

void write(TypeOutput& out, const ::example::DatabaseBase& value, const TypeCode* type_code, const uint16_t* code) {
	if(!type_code || (code && code[0] == CODE_ANY)) {
		type_code = vnx::write_type_code<::example::DatabaseBase>(out);
		vnx::write_class_header<::example::DatabaseBase>(out);
	}
	if(code && code[0] == CODE_STRUCT) {
		type_code = type_code->depends[code[1]];
	}
	vnx::write(out, value.input, type_code, type_code->fields[0].code.data());
}

void read(std::istream& in, ::example::DatabaseBase& value) {
	value.read(in);
}

void write(std::ostream& out, const ::example::DatabaseBase& value) {
	value.write(out);
}

void accept(Visitor& visitor, const ::example::DatabaseBase& value) {
	value.accept(visitor);
}

} // vnx
