
// AUTO GENERATED by vnxcppcodegen

#include <example/package.hxx>
#include <example/LidarProcessorBase.hxx>
#include <vnx/Input.h>
#include <vnx/Output.h>
#include <vnx/Visitor.h>
#include <vnx/Config.h>


namespace example {


const vnx::Hash64 LidarProcessorBase::VNX_TYPE_HASH(0x7df3e7fe5968fe76ull);
const vnx::Hash64 LidarProcessorBase::VNX_CODE_HASH(0x19b45925a23b741eull);

LidarProcessorBase::LidarProcessorBase(const std::string& _vnx_name)
	:	Module::Module(_vnx_name)
{
}

vnx::Hash64 LidarProcessorBase::get_type_hash() const {
	return VNX_TYPE_HASH;
}

const char* LidarProcessorBase::get_type_name() const {
	return "example.LidarProcessor";
}

void LidarProcessorBase::accept(vnx::Visitor& _visitor) const {
	const vnx::TypeCode* _type_code = get_type_code();
	_visitor.type_begin(*_type_code);
	_visitor.type_end(*_type_code);
}

void LidarProcessorBase::write(std::ostream& _out) const {
	_out << "{";
	_out << "}";
}

void LidarProcessorBase::read(std::istream& _in) {
	std::map<std::string, std::string> _object;
	vnx::read_object(_in, _object);
	for(const auto& _entry : _object) {
	}
}

std::ostream& operator<<(std::ostream& _out, const LidarProcessorBase& _value) {
	_value.write(_out);
	return _out;
}

std::istream& operator>>(std::istream& _in, LidarProcessorBase& _value) {
	_value.read(_in);
	return _in;
}

const vnx::TypeCode* LidarProcessorBase::get_type_code() {
	const vnx::TypeCode* type_code = vnx::get_type_code(vnx::Hash64(0x7df3e7fe5968fe76ull));
	if(!type_code) {
		type_code = vnx::register_type_code(create_type_code());
	}
	return type_code;
}

std::shared_ptr<vnx::TypeCode> LidarProcessorBase::create_type_code() {
	std::shared_ptr<vnx::TypeCode> type_code = std::make_shared<vnx::TypeCode>(true);
	type_code->name = "example.LidarProcessor";
	type_code->type_hash = vnx::Hash64(0x7df3e7fe5968fe76ull);
	type_code->code_hash = vnx::Hash64(0x19b45925a23b741eull);
	type_code->methods.resize(0);
	type_code->build();
	return type_code;
}

void LidarProcessorBase::handle_switch(std::shared_ptr<const ::vnx::Sample> _sample) {
	const uint64_t _type_hash = _sample->value->get_type_hash();
}

bool LidarProcessorBase::call_switch(vnx::TypeInput& _in, vnx::TypeOutput& _out, const vnx::TypeCode* _call_type, const vnx::TypeCode* _return_type) {
	return false;
}


} // namespace example


namespace vnx {

void read(TypeInput& in, ::example::LidarProcessorBase& value, const TypeCode* type_code, const uint16_t* code) {
	if(code) {
		type_code = type_code->depends[code[1]];
	}
	const char* const _buf = in.read(type_code->total_field_size);
	for(const vnx::TypeField* _field : type_code->ext_fields) {
		switch(_field->native_index) {
			default: vnx::skip(in, type_code, _field->code.data());
		}
	}
}

void write(TypeOutput& out, const ::example::LidarProcessorBase& value, const TypeCode* type_code, const uint16_t* code) {
	if(code) {
		type_code = type_code->depends[code[1]];
	}
}

void read(std::istream& in, ::example::LidarProcessorBase& value) {
	value.read(in);
}

void write(std::ostream& out, const ::example::LidarProcessorBase& value) {
	value.write(out);
}

void accept(Visitor& visitor, const ::example::LidarProcessorBase& value) {
	value.accept(visitor);
}

} // vnx
