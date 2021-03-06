
// AUTO GENERATED by vnxcppcodegen

#ifndef INCLUDE_example_Database_CLIENT_HXX_
#define INCLUDE_example_Database_CLIENT_HXX_

#include <vnx/Client.h>
#include <example/Transaction.hxx>
#include <example/User.hxx>
#include <vnx/Module.h>
#include <vnx/TopicPtr.h>


namespace example {

class DatabaseClient : public vnx::Client {
public:
	DatabaseClient(const std::string& service_name);
	
	DatabaseClient(vnx::Hash64 service_addr);
	
	void add_user(const ::std::string& name);
	
	void add_user_async(const ::std::string& name);
	
	void add_user_balance(const ::std::string& name, const ::vnx::float64_t& value);
	
	void add_user_balance_async(const ::std::string& name, const ::vnx::float64_t& value);
	
	::std::shared_ptr<const ::example::User> get_user(const ::std::string& name);
	
	::vnx::float64_t get_user_balance(const ::std::string& name);
	
	void handle(const ::std::shared_ptr<const ::example::Transaction>& sample);
	
	void handle_async(const ::std::shared_ptr<const ::example::Transaction>& sample);
	
	void subtract_user_balance(const ::std::string& name, const ::vnx::float64_t& value);
	
	void subtract_user_balance_async(const ::std::string& name, const ::vnx::float64_t& value);
	
};


} // namespace example

#endif // INCLUDE_example_Database_CLIENT_HXX_
