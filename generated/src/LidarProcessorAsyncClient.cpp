
// AUTO GENERATED by vnxcppcodegen

#include <example/package.hxx>
#include <example/LidarProcessorAsyncClient.hxx>
#include <vnx/Input.h>
#include <vnx/Output.h>


namespace example {

LidarProcessorAsyncClient::LidarProcessorAsyncClient(const std::string& service_name)
	:	AsyncClient::AsyncClient(vnx::Hash64(service_name))
{
}

LidarProcessorAsyncClient::LidarProcessorAsyncClient(vnx::Hash64 service_addr)
	:	AsyncClient::AsyncClient(service_addr)
{
}

uint64_t LidarProcessorAsyncClient::handle(const ::std::shared_ptr<const ::example::LidarInfo>& sample, const std::function<void()>& _callback) {
	std::shared_ptr<vnx::Binary> _argument_data = vnx::Binary::create();
	vnx::BinaryOutputStream _stream_out(_argument_data.get());
	vnx::TypeOutput _out(&_stream_out);
	const vnx::TypeCode* _type_code = example::vnx_native_type_code_LidarProcessor_handle_example_LidarInfo;
	{
		vnx::write(_out, sample, _type_code, _type_code->fields[0].code.data());
	}
	_out.flush();
	_argument_data->type_code = _type_code;
	const uint64_t _request_id = vnx_request(_argument_data);
	vnx_queue_handle_example_LidarInfo[_request_id] = _callback;
	vnx_num_pending++;
	return _request_id;
}

uint64_t LidarProcessorAsyncClient::handle(const ::std::shared_ptr<const ::example::LidarPointCloud>& sample, const std::function<void()>& _callback) {
	std::shared_ptr<vnx::Binary> _argument_data = vnx::Binary::create();
	vnx::BinaryOutputStream _stream_out(_argument_data.get());
	vnx::TypeOutput _out(&_stream_out);
	const vnx::TypeCode* _type_code = example::vnx_native_type_code_LidarProcessor_handle_example_LidarPointCloud;
	{
		vnx::write(_out, sample, _type_code, _type_code->fields[0].code.data());
	}
	_out.flush();
	_argument_data->type_code = _type_code;
	const uint64_t _request_id = vnx_request(_argument_data);
	vnx_queue_handle_example_LidarPointCloud[_request_id] = _callback;
	vnx_num_pending++;
	return _request_id;
}

std::vector<uint64_t>LidarProcessorAsyncClient::vnx_get_pending_ids() const {
	std::vector<uint64_t> _list;
	for(const auto& entry : vnx_queue_handle_example_LidarInfo) {
		_list.push_back(entry.first);
	}
	for(const auto& entry : vnx_queue_handle_example_LidarPointCloud) {
		_list.push_back(entry.first);
	}
	return _list;
}

void LidarProcessorAsyncClient::vnx_purge_request(uint64_t _request_id) {
	vnx_num_pending -= vnx_queue_handle_example_LidarInfo.erase(_request_id);
	vnx_num_pending -= vnx_queue_handle_example_LidarPointCloud.erase(_request_id);
}

void LidarProcessorAsyncClient::vnx_callback_switch(uint64_t _request_id, std::shared_ptr<const vnx::Binary> _data) {
	vnx::BinaryInputStream _stream_in(_data.get());
	vnx::TypeInput _in(&_stream_in);
	const vnx::TypeCode* _return_type = _data->type_code;
	
	if(_return_type->type_hash == vnx::Hash64(0x7967c878d16d870aull)) {
		auto _iter = vnx_queue_handle_example_LidarInfo.find(_request_id);
		if(_iter != vnx_queue_handle_example_LidarInfo.end()) {
			const auto _callback = std::move(_iter->second);
			vnx_queue_handle_example_LidarInfo.erase(_iter);
			vnx_num_pending--;
			if(_callback) {
				_callback();
			}
		}
	}
	else if(_return_type->type_hash == vnx::Hash64(0x563c486fd84f7fa3ull)) {
		auto _iter = vnx_queue_handle_example_LidarPointCloud.find(_request_id);
		if(_iter != vnx_queue_handle_example_LidarPointCloud.end()) {
			const auto _callback = std::move(_iter->second);
			vnx_queue_handle_example_LidarPointCloud.erase(_iter);
			vnx_num_pending--;
			if(_callback) {
				_callback();
			}
		}
	}
}


} // namespace example