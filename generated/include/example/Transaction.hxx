
// AUTO GENERATED by vnxcppcodegen

#ifndef INCLUDE_example_Transaction_HXX_
#define INCLUDE_example_Transaction_HXX_

#include <example/package.hxx>
#include <example/transaction_type_e.hxx>
#include <vnx/Value.h>


namespace example {

class Transaction : public ::vnx::Value {
public:
	
	::example::transaction_type_e type;
	::std::string from;
	::std::string to;
	::float64_t amount = 0;
	
	typedef ::vnx::Value Super;
	
	static const vnx::Hash64 VNX_TYPE_HASH;
	static const vnx::Hash64 VNX_CODE_HASH;
	
	vnx::Hash64 get_type_hash() const;
	const char* get_type_name() const;
	
	static std::shared_ptr<Transaction> create();
	std::shared_ptr<vnx::Value> clone() const;
	
	void read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code);
	void write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const;
	
	void read(std::istream& _in);
	void write(std::ostream& _out) const;
	
	void accept(vnx::Visitor& _visitor) const;
	
	friend std::ostream& operator<<(std::ostream& _out, const Transaction& _value);
	friend std::istream& operator>>(std::istream& _in, Transaction& _value);
	
	static const vnx::TypeCode* get_type_code();
	static std::shared_ptr<vnx::TypeCode> create_type_code();
	
};


} // namespace example

#endif // INCLUDE_example_Transaction_HXX_
