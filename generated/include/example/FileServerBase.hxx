
// AUTO GENERATED by vnxcppcodegen

#ifndef INCLUDE_example_FileServerBase_HXX_
#define INCLUDE_example_FileServerBase_HXX_

#include <example/package.hxx>
#include <example/File.hxx>
#include <vnx/Module.h>


namespace example {

class FileServerBase : public ::vnx::Module {
public:
	
	::std::string root_path;
	::int32_t num_threads = 10;
	
	typedef ::vnx::Module Super;
	
	static const vnx::Hash64 VNX_TYPE_HASH;
	static const vnx::Hash64 VNX_CODE_HASH;
	
	FileServerBase(const std::string& _vnx_name);
	
	vnx::Hash64 get_type_hash() const;
	const char* get_type_name() const;
	const vnx::TypeCode* get_type_code() const;
	
	void read(std::istream& _in);
	void write(std::ostream& _out) const;
	
	void accept(vnx::Visitor& _visitor) const;
	
	vnx::Object to_object() const;
	void from_object(const vnx::Object& object);
	
	friend std::ostream& operator<<(std::ostream& _out, const FileServerBase& _value);
	friend std::istream& operator>>(std::istream& _in, FileServerBase& _value);
	
	static const vnx::TypeCode* static_get_type_code();
	static std::shared_ptr<vnx::TypeCode> static_create_type_code();
	
protected:
	virtual void get_file_async(const ::std::string& file_name, const std::function<void(const ::std::shared_ptr<const ::example::File>&)>& _callback, const vnx::request_id_t& _request_id) const = 0;
	
	void vnx_handle_switch(std::shared_ptr<const ::vnx::Sample> _sample) override;
	std::shared_ptr<vnx::Value> vnx_call_switch(vnx::TypeInput& _in, const vnx::TypeCode* _call_type, const vnx::request_id_t& _request_id) override;
	
private:
	void get_file_async_return(const vnx::request_id_t& _request_id, const ::std::shared_ptr<const ::example::File>& _ret_0);
	
};


} // namespace example

#endif // INCLUDE_example_FileServerBase_HXX_
