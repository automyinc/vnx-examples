
// AUTO GENERATED by vnxcppcodegen

#ifndef INCLUDE_example_DatabaseBase_HXX_
#define INCLUDE_example_DatabaseBase_HXX_

#include <example/package.hxx>
#include <example/Transaction.hxx>
#include <example/User.hxx>
#include <vnx/Module.h>
#include <vnx/TopicPtr.h>


namespace example {

class DatabaseBase : public ::vnx::Module {
public:
	
	::vnx::TopicPtr input;
	
	typedef ::vnx::Module Super;
	
	static const vnx::Hash64 VNX_TYPE_HASH;
	static const vnx::Hash64 VNX_CODE_HASH;
	
	DatabaseBase(const std::string& _vnx_name);
	
	vnx::Hash64 get_type_hash() const;
	const char* get_type_name() const;
	
	void read(std::istream& _in);
	void write(std::ostream& _out) const;
	
	void accept(vnx::Visitor& _visitor) const;
	
	vnx::Object to_object() const;
	void from_object(const vnx::Object& object);
	
	friend std::ostream& operator<<(std::ostream& _out, const DatabaseBase& _value);
	friend std::istream& operator>>(std::istream& _in, DatabaseBase& _value);
	
	static const vnx::TypeCode* get_type_code();
	static std::shared_ptr<vnx::TypeCode> create_type_code();
	
protected:
	virtual void add_user(const ::std::string& name) = 0;
	virtual void add_user_balance(const ::std::string& name, const ::vnx::float64_t& value) = 0;
	virtual ::std::shared_ptr<const ::example::User> get_user(const ::std::string& name) const = 0;
	virtual ::vnx::float64_t get_user_balance(const ::std::string& name) const = 0;
	virtual void handle(std::shared_ptr<const ::example::Transaction> _value, std::shared_ptr<const ::vnx::Sample> _sample) { handle(_value); }
	virtual void handle(std::shared_ptr<const ::example::Transaction> _value) {}
	virtual void subtract_user_balance(const ::std::string& name, const ::vnx::float64_t& value) = 0;
	
	void vnx_handle_switch(std::shared_ptr<const ::vnx::Sample> _sample) override;
	std::shared_ptr<vnx::Value> vnx_call_switch(vnx::TypeInput& _in, const vnx::TypeCode* _call_type, const vnx::request_id_t& _request_id) override;
	
private:
	
};


} // namespace example

#endif // INCLUDE_example_DatabaseBase_HXX_
