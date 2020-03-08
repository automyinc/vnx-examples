
// AUTO GENERATED by vnxcppcodegen

#ifndef INCLUDE_example_Database_ASYNC_CLIENT_HXX_
#define INCLUDE_example_Database_ASYNC_CLIENT_HXX_

#include <vnx/AsyncClient.h>
#include <example/Transaction.hxx>
#include <example/User.hxx>
#include <vnx/Module.h>
#include <vnx/TopicPtr.h>


namespace example {

class DatabaseAsyncClient : public vnx::AsyncClient {
public:
	DatabaseAsyncClient(const std::string& service_name);
	
	DatabaseAsyncClient(vnx::Hash64 service_addr);
	
	uint64_t add_user(const ::std::string& name, const std::function<void()>& _callback);
	
	uint64_t add_user_balance(const ::std::string& name, const ::vnx::float64_t& value, const std::function<void()>& _callback);
	
	uint64_t get_user(const ::std::string& name, const std::function<void(::std::shared_ptr<const ::example::User>)>& _callback);
	
	uint64_t get_user_balance(const ::std::string& name, const std::function<void(::vnx::float64_t)>& _callback);
	
	uint64_t handle(const ::std::shared_ptr<const ::example::Transaction>& sample, const std::function<void()>& _callback);
	
	uint64_t subtract_user_balance(const ::std::string& name, const ::vnx::float64_t& value, const std::function<void()>& _callback);
	
protected:
	void vnx_purge_request(uint64_t _request_id) override;
	
	void vnx_callback_switch(uint64_t _request_id, std::shared_ptr<const vnx::Binary> _data) override;
	
private:
	std::map<uint64_t, std::function<void()>> vnx_queue_add_user;
	std::map<uint64_t, std::function<void()>> vnx_queue_add_user_balance;
	std::map<uint64_t, std::function<void(::std::shared_ptr<const ::example::User>)>> vnx_queue_get_user;
	std::map<uint64_t, std::function<void(::vnx::float64_t)>> vnx_queue_get_user_balance;
	std::map<uint64_t, std::function<void()>> vnx_queue_handle_example_Transaction;
	std::map<uint64_t, std::function<void()>> vnx_queue_subtract_user_balance;
	
};


} // namespace example

#endif // INCLUDE_example_Database_ASYNC_CLIENT_HXX_
