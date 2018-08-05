
// AUTO GENERATED by vnxcppcodegen

#include <example/package.hxx>
#include <example/transaction_type_e.hxx>
#include <vnx/Input.h>
#include <vnx/Output.h>
#include <vnx/Visitor.h>


namespace example {


const vnx::Hash64 transaction_type_e::VNX_TYPE_HASH(0xcbdf8f90f7bbb940ull);
const vnx::Hash64 transaction_type_e::VNX_CODE_HASH(0x4cccd552defba37eull);

vnx::Hash64 transaction_type_e::get_type_hash() const {
	return VNX_TYPE_HASH;
}

const char* transaction_type_e::get_type_name() const {
	return "example.transaction_type_e";
}

void transaction_type_e::accept(vnx::Visitor& _visitor) const {
	std::string _name;
	switch(value) {
		case CREDIT: _name = "CREDIT"; break;
		case DEBIT: _name = "DEBIT"; break;
		case TRANSFER: _name = "TRANSFER"; break;
	}
	_visitor.enum_value(value, _name);
}

void transaction_type_e::write(std::ostream& _out) const {
	switch(value) {
		case CREDIT: _out << "\"CREDIT\""; break;
		case DEBIT: _out << "\"DEBIT\""; break;
		case TRANSFER: _out << "\"TRANSFER\""; break;
		default: _out << value;
	}
}

void transaction_type_e::read(std::istream& _in) {
	std::string _name;
	vnx::read(_in, _name);
	if(_name == "CREDIT") value = 1905840622;
	else if(_name == "DEBIT") value = 3638737151;
	else if(_name == "TRANSFER") value = 858544509;
	else value = std::atoi(_name.c_str());
}

std::ostream& operator<<(std::ostream& _out, const transaction_type_e& _value) {
	_value.write(_out);
	return _out;
}

std::istream& operator>>(std::istream& _in, transaction_type_e& _value) {
	_value.read(_in);
	return _in;
}

const vnx::TypeCode* transaction_type_e::get_type_code() {
	const vnx::TypeCode* type_code = vnx::get_type_code(vnx::Hash64(0xcbdf8f90f7bbb940ull));
	if(!type_code) {
		type_code = vnx::register_type_code(create_type_code());
	}
	return type_code;
}

std::shared_ptr<vnx::TypeCode> transaction_type_e::create_type_code() {
	std::shared_ptr<vnx::TypeCode> type_code = std::make_shared<vnx::TypeCode>(true);
	type_code->name = "example.transaction_type_e";
	type_code->type_hash = vnx::Hash64(0xcbdf8f90f7bbb940ull);
	type_code->code_hash = vnx::Hash64(0x4cccd552defba37eull);
	type_code->fields.resize(1);
	{
		vnx::TypeField& field = type_code->fields[0];
		field.name = "value";
		field.code = {3};
	}
	type_code->enum_map[1905840622] = "CREDIT";
	type_code->enum_map[3638737151] = "DEBIT";
	type_code->enum_map[858544509] = "TRANSFER";
	type_code->build();
	return type_code;
}


} // namespace example


namespace vnx {

void read(TypeInput& in, ::example::transaction_type_e& value, const TypeCode* type_code, const uint16_t* code) {
	if(code) {
		type_code = type_code->depends[code[1]];
	}
	const char* const _buf = in.read(type_code->total_field_size);
	{
		const vnx::TypeField* const _field = type_code->field_map[0];
		if(_field) {
			vnx::read_value(_buf + _field->offset, value.value, _field->code.data());
		}
	}
	for(const vnx::TypeField* _field : type_code->ext_fields) {
		switch(_field->native_index) {
			default: vnx::skip(in, type_code, _field->code.data());
		}
	}
}

void write(TypeOutput& out, const ::example::transaction_type_e& value, const TypeCode* type_code, const uint16_t* code) {
	if(code) {
		type_code = type_code->depends[code[1]];
	}
	char* const _buf = out.write(4);
	vnx::write_value(_buf + 0, value.value);
}

void read(std::istream& in, ::example::transaction_type_e& value) {
	value.read(in);
}

void write(std::ostream& out, const ::example::transaction_type_e& value) {
	value.write(out);
}

void accept(Visitor& visitor, const ::example::transaction_type_e& value) {
	value.accept(visitor);
}

} // vnx