
// AUTO GENERATED by vnxcppcodegen

#ifndef INCLUDE_example_LidarSensor_ASYNC_CLIENT_HXX_
#define INCLUDE_example_LidarSensor_ASYNC_CLIENT_HXX_

#include <vnx/AsyncClient.h>
#include <example/LidarInfo.hxx>
#include <vnx/Module.h>
#include <vnx/TopicPtr.h>


namespace example {

class LidarSensorAsyncClient : public vnx::AsyncClient {
public:
	LidarSensorAsyncClient(const std::string& service_name);
	
	LidarSensorAsyncClient(vnx::Hash64 service_addr);
	
	std::vector<uint64_t> vnx_get_pending_ids() const override;
	
protected:
	void vnx_purge_request(uint64_t _request_id) override;
	
	void vnx_callback_switch(uint64_t _request_id, std::shared_ptr<const vnx::Binary> _data) override;
	
private:
	
};


} // namespace example

#endif // INCLUDE_example_LidarSensor_ASYNC_CLIENT_HXX_
