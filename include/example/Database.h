
#ifndef INCLUDE_EXAMPLE_DATABASE_H_
#define INCLUDE_EXAMPLE_DATABASE_H_

#include <example/DatabaseBase.hxx>


namespace example {

/**
 * The Database example shows how to use the request/response system.
 * 
 * Multiple clients from within the same process and/or from other processes can access the database.
 * 
 * Requests are processed first come first serve, interleaved with timer callbacks and processing of samples.
 * 
 * Since a module has its own thread we are writing single threaded code, as if a module is a normal process
 * with its own main() function.
 */
class Database : public DatabaseBase {
public:
	/**
	 * Typically we don't want to hard-code a module name so we pass a name through
	 * and let the user pick one when creating an instance.
	 */
	Database(const std::string& _vnx_name)
		:	DatabaseBase(_vnx_name)
	{
	}
	
	/*
	 * Besides the constructor all functions should be at least protected.
	 */
	
protected:
	/**
	 * The main() function will be called when the module is started in its own thread.
	 */
	void main() override {
		
		// Register ourselves as a service with our module name as service name.
		vnx::open_pipe(vnx_name, this);
		
		/*
		 * A max queue length of 0 means unlimited, we use it here since we don't want to drop any transactions.
		 * 
		 * In case input is a null pointer this call has no effect.
		 */
		subscribe(input, 0);
		
		// Enter main processing loop
		Super::main();
	}
	
	/*
	 * The following functions will be called from within Super::main() when a corresponding
	 * request has been received. The return values will be sent back to the client.
	 */
	
	std::shared_ptr<const User> get_user(const std::string& name) const override {
		auto iter = table.find(name);
		if(iter != table.end()) {
			return vnx::clone(iter->second);
		}
		return nullptr;
	}
	
	void add_user(const std::string& name) override {
		table[name].name = name;
	}
	
	vnx::float64_t get_user_balance(const std::string& name) const override {
		auto iter = table.find(name);
		if(iter != table.end()) {
			return iter->second.balance;
		} else {
			// The exception will be caught in Super::main() and sent back to the client.
			throw std::logic_error("Unknown user: " + name);
		}
	}
	
	void add_user_balance(const std::string& name, const vnx::float64_t& value) override {
		table[name].balance += value;
	}
	
	void subtract_user_balance(const std::string& name, const vnx::float64_t& value) override {
		table[name].balance -= value;
	}
	
	/**
	 * The handle() function will be called from within Super::main() every time a
	 * example::Transaction sample is received.
	 * 
	 * Be careful: Throwing an exception inside a handle() function will terminate the module.
	 */
	void handle(std::shared_ptr<const Transaction> sample) override {
		switch(sample->type) {
			case transaction_type_e::CREDIT:
				add_user_balance(sample->to, sample->amount);
				break;
			case transaction_type_e::DEBIT:
				subtract_user_balance(sample->from, sample->amount);
				break;
			case transaction_type_e::TRANSFER:
				add_user_balance(sample->to, sample->amount);
				subtract_user_balance(sample->from, sample->amount);
				break;
		}
	}
	
private:
	std::map<std::string, User> table;
	
};


} // example

#endif /* INCLUDE_EXAMPLE_DATABASE_H_ */
