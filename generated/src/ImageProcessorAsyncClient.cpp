
// AUTO GENERATED by vnxcppcodegen

#include <example/package.hxx>
#include <example/ImageProcessorAsyncClient.hxx>
#include <vnx/Input.h>
#include <vnx/Output.h>


namespace example {

ImageProcessorAsyncClient::ImageProcessorAsyncClient(const std::string& service_name)
	:	AsyncClient::AsyncClient(vnx::Hash64(service_name))
{
}

ImageProcessorAsyncClient::ImageProcessorAsyncClient(vnx::Hash64 service_addr)
	:	AsyncClient::AsyncClient(service_addr)
{
}

uint64_t ImageProcessorAsyncClient::handle(const ::std::shared_ptr<const ::automy::basic::ImageFrame8>& sample, const std::function<void()>& _callback) {
	std::shared_ptr<vnx::Binary> _argument_data = vnx::Binary::create();
	vnx::BinaryOutputStream _stream_out(_argument_data.get());
	vnx::TypeOutput _out(&_stream_out);
	const vnx::TypeCode* _type_code = example::vnx_native_type_code_ImageProcessor_handle_automy_basic_ImageFrame8;
	{
		vnx::write(_out, sample, _type_code, _type_code->fields[0].code.data());
	}
	_out.flush();
	_argument_data->type_code = _type_code;
	const uint64_t _request_id = vnx_request(_argument_data);
	vnx_queue_handle_automy_basic_ImageFrame8[_request_id] = _callback;
	vnx_num_pending++;
	return _request_id;
}

std::vector<uint64_t>ImageProcessorAsyncClient::vnx_get_pending_ids() const {
	std::vector<uint64_t> _list;
	for(const auto& entry : vnx_queue_handle_automy_basic_ImageFrame8) {
		_list.push_back(entry.first);
	}
	return _list;
}

void ImageProcessorAsyncClient::vnx_purge_request(uint64_t _request_id) {
	vnx_num_pending -= vnx_queue_handle_automy_basic_ImageFrame8.erase(_request_id);
}

void ImageProcessorAsyncClient::vnx_callback_switch(uint64_t _request_id, std::shared_ptr<const vnx::Binary> _data) {
	vnx::BinaryInputStream _stream_in(_data.get());
	vnx::TypeInput _in(&_stream_in);
	const vnx::TypeCode* _return_type = _data->type_code;
	
	if(_return_type->type_hash == vnx::Hash64(0x38d29c6677d6b067ull)) {
		auto _iter = vnx_queue_handle_automy_basic_ImageFrame8.find(_request_id);
		if(_iter != vnx_queue_handle_automy_basic_ImageFrame8.end()) {
			const auto _callback = std::move(_iter->second);
			vnx_queue_handle_automy_basic_ImageFrame8.erase(_iter);
			vnx_num_pending--;
			if(_callback) {
				_callback();
			}
		}
	}
}


} // namespace example