
// AUTO GENERATED by vnxcppcodegen

#include <example/package.hxx>
#include <example/Transaction.hxx>
#include <vnx/Input.h>
#include <vnx/Output.h>
#include <vnx/Visitor.h>


namespace example {


const vnx::Hash64 Transaction::VNX_TYPE_HASH(0xcac4a4d10cff0323ull);
const vnx::Hash64 Transaction::VNX_CODE_HASH(0x73d37227291af40ull);

vnx::Hash64 Transaction::get_type_hash() const {
	return VNX_TYPE_HASH;
}

const char* Transaction::get_type_name() const {
	return "example.Transaction";
}

std::shared_ptr<Transaction> Transaction::create() {
	return std::make_shared<Transaction>();
}

std::shared_ptr<vnx::Value> Transaction::clone() const {
	return std::make_shared<Transaction>(*this);
}

void Transaction::read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code) {
	vnx::read(_in, *this, _type_code, _code);
}

void Transaction::write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const {
	vnx::write(_out, *this, _type_code, _code);
}

void Transaction::accept(vnx::Visitor& _visitor) const {
	const vnx::TypeCode* _type_code = get_type_code();
	_visitor.type_begin(*_type_code);
	_visitor.type_field(_type_code->fields[0], 0); vnx::accept(_visitor, type);
	_visitor.type_field(_type_code->fields[1], 1); vnx::accept(_visitor, from);
	_visitor.type_field(_type_code->fields[2], 2); vnx::accept(_visitor, to);
	_visitor.type_field(_type_code->fields[3], 3); vnx::accept(_visitor, amount);
	_visitor.type_end(*_type_code);
}

void Transaction::write(std::ostream& _out) const {
	_out << "{";
	_out << "\"type\": "; vnx::write(_out, type);
	_out << ", \"from\": "; vnx::write(_out, from);
	_out << ", \"to\": "; vnx::write(_out, to);
	_out << ", \"amount\": "; vnx::write(_out, amount);
	_out << "}";
}

void Transaction::read(std::istream& _in) {
	std::map<std::string, std::string> _object;
	vnx::read_object(_in, _object);
	for(const auto& _entry : _object) {
		if(_entry.first == "type") {
			vnx::from_string(_entry.second, type);
		} else if(_entry.first == "from") {
			vnx::from_string(_entry.second, from);
		} else if(_entry.first == "to") {
			vnx::from_string(_entry.second, to);
		} else if(_entry.first == "amount") {
			vnx::from_string(_entry.second, amount);
		}
	}
}

std::ostream& operator<<(std::ostream& _out, const Transaction& _value) {
	_value.write(_out);
	return _out;
}

std::istream& operator>>(std::istream& _in, Transaction& _value) {
	_value.read(_in);
	return _in;
}

const vnx::TypeCode* Transaction::get_type_code() {
	const vnx::TypeCode* type_code = vnx::get_type_code(vnx::Hash64(0xcac4a4d10cff0323ull));
	if(!type_code) {
		type_code = vnx::register_type_code(create_type_code());
	}
	return type_code;
}

std::shared_ptr<vnx::TypeCode> Transaction::create_type_code() {
	std::shared_ptr<vnx::TypeCode> type_code = std::make_shared<vnx::TypeCode>(true);
	type_code->name = "example.Transaction";
	type_code->type_hash = vnx::Hash64(0xcac4a4d10cff0323ull);
	type_code->code_hash = vnx::Hash64(0x73d37227291af40ull);
	type_code->create_value = []() -> std::shared_ptr<vnx::Value> { return std::make_shared<Transaction>(); };
	type_code->depends.resize(1);
	type_code->depends[0] = ::example::transaction_type_e::get_type_code();
	type_code->fields.resize(4);
	{
		vnx::TypeField& field = type_code->fields[0];
		field.is_extended = true;
		field.name = "type";
		field.code = {15, 0};
	}
	{
		vnx::TypeField& field = type_code->fields[1];
		field.is_extended = true;
		field.name = "from";
		field.code = {12, 5};
	}
	{
		vnx::TypeField& field = type_code->fields[2];
		field.is_extended = true;
		field.name = "to";
		field.code = {12, 5};
	}
	{
		vnx::TypeField& field = type_code->fields[3];
		field.name = "amount";
		field.code = {10};
	}
	type_code->build();
	return type_code;
}


} // namespace example


namespace vnx {

void read(TypeInput& in, ::example::Transaction& value, const TypeCode* type_code, const uint16_t* code) {
	if(code) {
		type_code = type_code->depends[code[1]];
	}
	const char* const _buf = in.read(type_code->total_field_size);
	{
		const vnx::TypeField* const _field = type_code->field_map[3];
		if(_field) {
			vnx::read_value(_buf + _field->offset, value.amount, _field->code.data());
		}
	}
	for(const vnx::TypeField* _field : type_code->ext_fields) {
		switch(_field->native_index) {
			case 0: vnx::read(in, value.type, type_code, _field->code.data()); break;
			case 1: vnx::read(in, value.from, type_code, _field->code.data()); break;
			case 2: vnx::read(in, value.to, type_code, _field->code.data()); break;
			default: vnx::skip(in, type_code, _field->code.data());
		}
	}
}

void write(TypeOutput& out, const ::example::Transaction& value, const TypeCode* type_code, const uint16_t* code) {
	if(!type_code) {
		type_code = vnx::write_type_code<::example::Transaction>(out);
		vnx::write_class_header<::example::Transaction>(out);
	} else {
		type_code = type_code->depends[code[1]];
	}
	if(!type_code->is_native) {
		throw std::logic_error("write(example::Transaction): type_code is not native");
	}
	char* const _buf = out.write(8);
	vnx::write_value(_buf + 0, value.amount);
	vnx::write(out, value.type, type_code, type_code->fields[0].code.data());
	vnx::write(out, value.from, type_code, type_code->fields[1].code.data());
	vnx::write(out, value.to, type_code, type_code->fields[2].code.data());
}

void read(std::istream& in, ::example::Transaction& value) {
	value.read(in);
}

void write(std::ostream& out, const ::example::Transaction& value) {
	value.write(out);
}

void accept(Visitor& visitor, const ::example::Transaction& value) {
	value.accept(visitor);
}

} // vnx