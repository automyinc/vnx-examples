
// AUTO GENERATED by vnxcppcodegen

#include <example/package.hxx>
#include <example/ImageProcessorBase.hxx>
#include <vnx/Input.h>
#include <vnx/Output.h>
#include <vnx/Visitor.h>
#include <vnx/Object.h>
#include <vnx/Struct.h>
#include <vnx/Config.h>


namespace example {


const vnx::Hash64 ImageProcessorBase::VNX_TYPE_HASH(0x212f42213adea73dull);
const vnx::Hash64 ImageProcessorBase::VNX_CODE_HASH(0xba9f8378c7002733ull);

ImageProcessorBase::ImageProcessorBase(const std::string& _vnx_name)
	:	Module::Module(_vnx_name)
{
	vnx::read_config(vnx_name + ".input", input);
	vnx::read_config(vnx_name + ".output", output);
	vnx::read_config(vnx_name + ".scale_factor", scale_factor);
}

vnx::Hash64 ImageProcessorBase::get_type_hash() const {
	return VNX_TYPE_HASH;
}

const char* ImageProcessorBase::get_type_name() const {
	return "example.ImageProcessor";
}

void ImageProcessorBase::accept(vnx::Visitor& _visitor) const {
	const vnx::TypeCode* _type_code = get_type_code();
	_visitor.type_begin(*_type_code);
	_visitor.type_field(_type_code->fields[0], 0); vnx::accept(_visitor, input);
	_visitor.type_field(_type_code->fields[1], 1); vnx::accept(_visitor, output);
	_visitor.type_field(_type_code->fields[2], 2); vnx::accept(_visitor, scale_factor);
	_visitor.type_end(*_type_code);
}

void ImageProcessorBase::write(std::ostream& _out) const {
	_out << "{";
	_out << "\"input\": "; vnx::write(_out, input);
	_out << ", \"output\": "; vnx::write(_out, output);
	_out << ", \"scale_factor\": "; vnx::write(_out, scale_factor);
	_out << "}";
}

void ImageProcessorBase::read(std::istream& _in) {
	std::map<std::string, std::string> _object;
	vnx::read_object(_in, _object);
	for(const auto& _entry : _object) {
		if(_entry.first == "input") {
			vnx::from_string(_entry.second, input);
		} else if(_entry.first == "output") {
			vnx::from_string(_entry.second, output);
		} else if(_entry.first == "scale_factor") {
			vnx::from_string(_entry.second, scale_factor);
		}
	}
}

vnx::Object ImageProcessorBase::to_object() const {
	vnx::Object _object;
	_object["input"] = input;
	_object["output"] = output;
	_object["scale_factor"] = scale_factor;
	return _object;
}

void ImageProcessorBase::from_object(const vnx::Object& _object) {
	for(const auto& _entry : _object.field) {
		if(_entry.first == "input") {
			_entry.second.to(input);
		} else if(_entry.first == "output") {
			_entry.second.to(output);
		} else if(_entry.first == "scale_factor") {
			_entry.second.to(scale_factor);
		}
	}
}

/// \private
std::ostream& operator<<(std::ostream& _out, const ImageProcessorBase& _value) {
	_value.write(_out);
	return _out;
}

/// \private
std::istream& operator>>(std::istream& _in, ImageProcessorBase& _value) {
	_value.read(_in);
	return _in;
}

const vnx::TypeCode* ImageProcessorBase::get_type_code() {
	const vnx::TypeCode* type_code = vnx::get_type_code(vnx::Hash64(0x212f42213adea73dull));
	if(!type_code) {
		type_code = vnx::register_type_code(create_type_code());
	}
	return type_code;
}

std::shared_ptr<vnx::TypeCode> ImageProcessorBase::create_type_code() {
	std::shared_ptr<vnx::TypeCode> type_code = std::make_shared<vnx::TypeCode>(true);
	type_code->name = "example.ImageProcessor";
	type_code->type_hash = vnx::Hash64(0x212f42213adea73dull);
	type_code->code_hash = vnx::Hash64(0xba9f8378c7002733ull);
	type_code->methods.resize(1);
	{
		std::shared_ptr<vnx::TypeCode> call_type = std::make_shared<vnx::TypeCode>(true);
		call_type->name = "example.ImageProcessor.handle_basic_ImageFrame8";
		call_type->type_hash = vnx::Hash64(0xa58d038b8530634cull);
		call_type->code_hash = vnx::Hash64(0xca9a8c84c6c530ddull);
		call_type->is_method = true;
		{
			std::shared_ptr<vnx::TypeCode> return_type = std::make_shared<vnx::TypeCode>(true);
			return_type->name = "example.ImageProcessor.handle_basic_ImageFrame8.return";
			return_type->type_hash = vnx::Hash64(0x7dd6718e11eb831bull);
			return_type->code_hash = vnx::Hash64(0x520d3a60c1c3feacull);
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
		type_code->methods[0] = vnx::register_type_code(call_type);
	}
	type_code->fields.resize(3);
	{
		vnx::TypeField& field = type_code->fields[0];
		field.is_extended = true;
		field.name = "input";
		field.code = {12, 5};
	}
	{
		vnx::TypeField& field = type_code->fields[1];
		field.is_extended = true;
		field.name = "output";
		field.code = {12, 5};
	}
	{
		vnx::TypeField& field = type_code->fields[2];
		field.name = "scale_factor";
		field.value = vnx::to_string(1);
		field.code = {9};
	}
	type_code->build();
	return type_code;
}

void ImageProcessorBase::handle_switch(std::shared_ptr<const ::vnx::Sample> _sample) {
	const uint64_t _type_hash = _sample->value->get_type_hash();
	if(_type_hash == 0xd5cc519f12ca26ddull) {
		std::shared_ptr<const basic::ImageFrame8> _value = std::dynamic_pointer_cast<const basic::ImageFrame8>(_sample->value);
		if(_value) {
			handle(_value, _sample);
		}
	}
}

bool ImageProcessorBase::call_switch(vnx::TypeInput& _in, vnx::TypeOutput& _out, const vnx::TypeCode* _call_type, const vnx::TypeCode* _return_type) {
	if(_call_type->type_hash == vnx::Hash64(0xa58d038b8530634cull)) {
		::std::shared_ptr<const ::basic::ImageFrame8> sample;
		const char* const _buf = _in.read(_call_type->total_field_size);
		for(const vnx::TypeField* _field : _call_type->ext_fields) {
			switch(_field->native_index) {
				case 0: vnx::read(_in, sample, _call_type, _field->code.data()); break;
				default: vnx::skip(_in, _call_type, _field->code.data());
			}
		}
		handle(sample);
		return true;
	}
	return false;
}


} // namespace example


namespace vnx {

void read(TypeInput& in, ::example::ImageProcessorBase& value, const TypeCode* type_code, const uint16_t* code) {
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
	{
		const vnx::TypeField* const _field = type_code->field_map[2];
		if(_field) {
			vnx::read_value(_buf + _field->offset, value.scale_factor, _field->code.data());
		}
	}
	for(const vnx::TypeField* _field : type_code->ext_fields) {
		switch(_field->native_index) {
			case 0: vnx::read(in, value.input, type_code, _field->code.data()); break;
			case 1: vnx::read(in, value.output, type_code, _field->code.data()); break;
			default: vnx::skip(in, type_code, _field->code.data());
		}
	}
}

void write(TypeOutput& out, const ::example::ImageProcessorBase& value, const TypeCode* type_code, const uint16_t* code) {
	if(!type_code || (code && code[0] == CODE_ANY)) {
		type_code = vnx::write_type_code<::example::ImageProcessorBase>(out);
		vnx::write_class_header<::example::ImageProcessorBase>(out);
	}
	if(code && code[0] == CODE_STRUCT) {
		type_code = type_code->depends[code[1]];
	}
	char* const _buf = out.write(4);
	vnx::write_value(_buf + 0, value.scale_factor);
	vnx::write(out, value.input, type_code, type_code->fields[0].code.data());
	vnx::write(out, value.output, type_code, type_code->fields[1].code.data());
}

void read(std::istream& in, ::example::ImageProcessorBase& value) {
	value.read(in);
}

void write(std::ostream& out, const ::example::ImageProcessorBase& value) {
	value.write(out);
}

void accept(Visitor& visitor, const ::example::ImageProcessorBase& value) {
	value.accept(visitor);
}

} // vnx
