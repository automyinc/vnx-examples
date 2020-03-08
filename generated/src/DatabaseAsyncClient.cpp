
// AUTO GENERATED by vnxcppcodegen

#include <example/package.hxx>
#include <example/DatabaseAsyncClient.hxx>
#include <vnx/Input.h>
#include <vnx/Output.h>


namespace example {

DatabaseAsyncClient::DatabaseAsyncClient(const std::string& service_name)
	:	AsyncClient::AsyncClient(vnx::Hash64(service_name))
{
}

DatabaseAsyncClient::DatabaseAsyncClient(vnx::Hash64 service_addr)
	:	AsyncClient::AsyncClient(service_addr)
{
}

uint64_t DatabaseAsyncClient::add_user(const ::std::string& name, const std::function<void()>& _callback) {
	std::shared_ptr<vnx::Binary> _argument_data = vnx::Binary::create();
	vnx::BinaryOutputStream _stream_out(_argument_data.get());
	vnx::TypeOutput _out(&_stream_out);
	const vnx::TypeCode* _type_code = vnx::get_type_code(vnx::Hash64(0x2741180fbb8f23a1ull));
	{
		vnx::write(_out, name, _type_code, _type_code->fields[0].code.data());
	}
	_out.flush();
	_argument_data->type_code = _type_code;
	const uint64_t _request_id = vnx_request(_argument_data);
	vnx_queue_add_user[_request_id] = _callback;
	vnx_num_pending++;
	return _request_id;
}

uint64_t DatabaseAsyncClient::add_user_balance(const ::std::string& name, const ::vnx::float64_t& value, const std::function<void()>& _callback) {
	std::shared_ptr<vnx::Binary> _argument_data = vnx::Binary::create();
	vnx::BinaryOutputStream _stream_out(_argument_data.get());
	vnx::TypeOutput _out(&_stream_out);
	const vnx::TypeCode* _type_code = vnx::get_type_code(vnx::Hash64(0x3d6e042d45e04326ull));
	{
		char* const _buf = _out.write(8);
		vnx::write_value(_buf + 0, value);
		vnx::write(_out, name, _type_code, _type_code->fields[0].code.data());
	}
	_out.flush();
	_argument_data->type_code = _type_code;
	const uint64_t _request_id = vnx_request(_argument_data);
	vnx_queue_add_user_balance[_request_id] = _callback;
	vnx_num_pending++;
	return _request_id;
}

uint64_t DatabaseAsyncClient::get_user(const ::std::string& name, const std::function<void(::std::shared_ptr<const ::example::User>)>& _callback) {
	std::shared_ptr<vnx::Binary> _argument_data = vnx::Binary::create();
	vnx::BinaryOutputStream _stream_out(_argument_data.get());
	vnx::TypeOutput _out(&_stream_out);
	const vnx::TypeCode* _type_code = vnx::get_type_code(vnx::Hash64(0x3e6f70937269a136ull));
	{
		vnx::write(_out, name, _type_code, _type_code->fields[0].code.data());
	}
	_out.flush();
	_argument_data->type_code = _type_code;
	const uint64_t _request_id = vnx_request(_argument_data);
	vnx_queue_get_user[_request_id] = _callback;
	vnx_num_pending++;
	return _request_id;
}

uint64_t DatabaseAsyncClient::get_user_balance(const ::std::string& name, const std::function<void(::vnx::float64_t)>& _callback) {
	std::shared_ptr<vnx::Binary> _argument_data = vnx::Binary::create();
	vnx::BinaryOutputStream _stream_out(_argument_data.get());
	vnx::TypeOutput _out(&_stream_out);
	const vnx::TypeCode* _type_code = vnx::get_type_code(vnx::Hash64(0xe625a8cfd51e9a9eull));
	{
		vnx::write(_out, name, _type_code, _type_code->fields[0].code.data());
	}
	_out.flush();
	_argument_data->type_code = _type_code;
	const uint64_t _request_id = vnx_request(_argument_data);
	vnx_queue_get_user_balance[_request_id] = _callback;
	vnx_num_pending++;
	return _request_id;
}

uint64_t DatabaseAsyncClient::handle(const ::std::shared_ptr<const ::example::Transaction>& sample, const std::function<void()>& _callback) {
	std::shared_ptr<vnx::Binary> _argument_data = vnx::Binary::create();
	vnx::BinaryOutputStream _stream_out(_argument_data.get());
	vnx::TypeOutput _out(&_stream_out);
	const vnx::TypeCode* _type_code = vnx::get_type_code(vnx::Hash64(0xa9a81442632b020eull));
	{
		vnx::write(_out, sample, _type_code, _type_code->fields[0].code.data());
	}
	_out.flush();
	_argument_data->type_code = _type_code;
	const uint64_t _request_id = vnx_request(_argument_data);
	vnx_queue_handle_example_Transaction[_request_id] = _callback;
	vnx_num_pending++;
	return _request_id;
}

uint64_t DatabaseAsyncClient::subtract_user_balance(const ::std::string& name, const ::vnx::float64_t& value, const std::function<void()>& _callback) {
	std::shared_ptr<vnx::Binary> _argument_data = vnx::Binary::create();
	vnx::BinaryOutputStream _stream_out(_argument_data.get());
	vnx::TypeOutput _out(&_stream_out);
	const vnx::TypeCode* _type_code = vnx::get_type_code(vnx::Hash64(0xe58127da78610817ull));
	{
		char* const _buf = _out.write(8);
		vnx::write_value(_buf + 0, value);
		vnx::write(_out, name, _type_code, _type_code->fields[0].code.data());
	}
	_out.flush();
	_argument_data->type_code = _type_code;
	const uint64_t _request_id = vnx_request(_argument_data);
	vnx_queue_subtract_user_balance[_request_id] = _callback;
	vnx_num_pending++;
	return _request_id;
}

void DatabaseAsyncClient::vnx_purge_request(uint64_t _request_id) {
	vnx_num_pending -= vnx_queue_add_user.erase(_request_id);
	vnx_num_pending -= vnx_queue_add_user_balance.erase(_request_id);
	vnx_num_pending -= vnx_queue_get_user.erase(_request_id);
	vnx_num_pending -= vnx_queue_get_user_balance.erase(_request_id);
	vnx_num_pending -= vnx_queue_handle_example_Transaction.erase(_request_id);
	vnx_num_pending -= vnx_queue_subtract_user_balance.erase(_request_id);
}

void DatabaseAsyncClient::vnx_callback_switch(uint64_t _request_id, std::shared_ptr<const vnx::Binary> _data) {
	vnx::BinaryInputStream _stream_in(_data.get());
	vnx::TypeInput _in(&_stream_in);
	const vnx::TypeCode* _return_type = _data->type_code;
	
	if(_return_type->type_hash == vnx::Hash64(0x73df74b7d405f6b0ull)) {
		auto _iter = vnx_queue_add_user.find(_request_id);
		if(_iter != vnx_queue_add_user.end()) {
			if(_iter->second) {
				_iter->second();
			}
			vnx_queue_add_user.erase(_iter);
			vnx_num_pending--;
		}
	}
	else if(_return_type->type_hash == vnx::Hash64(0xce8eb9027f2289c3ull)) {
		auto _iter = vnx_queue_add_user_balance.find(_request_id);
		if(_iter != vnx_queue_add_user_balance.end()) {
			if(_iter->second) {
				_iter->second();
			}
			vnx_queue_add_user_balance.erase(_iter);
			vnx_num_pending--;
		}
	}
	else if(_return_type->type_hash == vnx::Hash64(0x36d19b92367474d9ull)) {
		::std::shared_ptr<const ::example::User> _ret_0;
		{
			const char* const _buf = _in.read(_return_type->total_field_size);
			if(_return_type->is_matched) {
			}
			for(const vnx::TypeField* _field : _return_type->ext_fields) {
				switch(_field->native_index) {
					case 0: vnx::read(_in, _ret_0, _return_type, _field->code.data()); break;
					default: vnx::skip(_in, _return_type, _field->code.data());
				}
			}
		}
		auto _iter = vnx_queue_get_user.find(_request_id);
		if(_iter != vnx_queue_get_user.end()) {
			if(_iter->second) {
				_iter->second(_ret_0);
			}
			vnx_queue_get_user.erase(_iter);
			vnx_num_pending--;
		}
	}
	else if(_return_type->type_hash == vnx::Hash64(0x50b361140a464af7ull)) {
		::vnx::float64_t _ret_0 = 0;
		{
			const char* const _buf = _in.read(_return_type->total_field_size);
			if(_return_type->is_matched) {
				{
					const vnx::TypeField* const _field = _return_type->field_map[0];
					if(_field) {
						vnx::read_value(_buf + _field->offset, _ret_0, _field->code.data());
					}
				}
			}
			for(const vnx::TypeField* _field : _return_type->ext_fields) {
				switch(_field->native_index) {
					default: vnx::skip(_in, _return_type, _field->code.data());
				}
			}
		}
		auto _iter = vnx_queue_get_user_balance.find(_request_id);
		if(_iter != vnx_queue_get_user_balance.end()) {
			if(_iter->second) {
				_iter->second(_ret_0);
			}
			vnx_queue_get_user_balance.erase(_iter);
			vnx_num_pending--;
		}
	}
	else if(_return_type->type_hash == vnx::Hash64(0xa6ede797ad62d986ull)) {
		auto _iter = vnx_queue_handle_example_Transaction.find(_request_id);
		if(_iter != vnx_queue_handle_example_Transaction.end()) {
			if(_iter->second) {
				_iter->second();
			}
			vnx_queue_handle_example_Transaction.erase(_iter);
			vnx_num_pending--;
		}
	}
	else if(_return_type->type_hash == vnx::Hash64(0x602e1ee9204ea132ull)) {
		auto _iter = vnx_queue_subtract_user_balance.find(_request_id);
		if(_iter != vnx_queue_subtract_user_balance.end()) {
			if(_iter->second) {
				_iter->second();
			}
			vnx_queue_subtract_user_balance.erase(_iter);
			vnx_num_pending--;
		}
	}
}


} // namespace example
