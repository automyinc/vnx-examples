
// AUTO GENERATED by vnxcppcodegen

#ifndef INCLUDE_example_FileServer_ASYNC_CLIENT_HXX_
#define INCLUDE_example_FileServer_ASYNC_CLIENT_HXX_

#include <vnx/AsyncClient.h>
#include <example/File.hxx>
#include <vnx/Module.h>


namespace example {

class FileServerAsyncClient : public vnx::AsyncClient {
public:
	FileServerAsyncClient(const std::string& service_name);
	
	FileServerAsyncClient(vnx::Hash64 service_addr);
	
	uint64_t get_file(const ::std::string& file_name, const std::function<void(::std::shared_ptr<const ::example::File>)>& _callback);
	
	std::vector<uint64_t> vnx_get_pending_ids() const override;
	
protected:
	void vnx_purge_request(uint64_t _request_id) override;
	
	void vnx_callback_switch(uint64_t _request_id, std::shared_ptr<const vnx::Binary> _data) override;
	
private:
	std::map<uint64_t, std::function<void(::std::shared_ptr<const ::example::File>)>> vnx_queue_get_file;
	
};


} // namespace example

#endif // INCLUDE_example_FileServer_ASYNC_CLIENT_HXX_