
#ifndef VNX_EXAMPLES_INCLUDE_EXAMPLE_DATABASE_H_
#define VNX_EXAMPLES_INCLUDE_EXAMPLE_DATABASE_H_

#include <example/DatabaseBase.hxx>
#include <example/Table.hxx>
#include <example/User.hxx>

/*
 * Included for vnx::read_from_file() and vnx::write_to_file().
 */
#include <vnx/Input.h>
#include <vnx/Output.h>


namespace example {

/*
 * The Database example shows how to use the request/response system.
 * 
 * Multiple clients from within the same process or from other processes can access the database.
 * 
 * Requests are processed first come first serve, interleaved with timer callbacks and processing samples.
 * 
 * Since a module has its own thread we are writing single threaded code,
 * just as if this module was a process with its own main() function.
 * 
 * In this example we only implement one table called 'user' even though the interface allows for multiple tables.
 */
class Database : public DatabaseBase {
public:
	/*
	 * Typically we do not want to hard-code a module name, hence we pass a name through
	 * and let the user pick one when creating an instance.
	 */
	Database(const std::string& _vnx_name)
		:	DatabaseBase(_vnx_name)
	{
	}
	
	/*
	 * Besides the constructor all functions and variables should be at least protected.
	 * To ensure thread safety, after a module has been started it is not allowed
	 * to access the object via pointer anymore.
	 */
protected:
	
	/*
	 * The main() function will be called when the module is started in its own thread.
	 */
	void main() override {
		
		/*
		 * Register ourselves as a service with our module name as service name.
		 */
		vnx::open_pipe(vnx_name, this);
		
		/*
		 * First we load existing data into memory. If no data found we create an empty table.
		 */
		user = vnx::read_from_file<Table>(root_path + "user.dat");
		if(!user) {
			user = Table::create();
			user->name = "user";
			log(INFO).out << "Created new user table.";
		} else {
			log(INFO).out << "Loaded user table with " << user->objects.size() << " entries.";
		}
		
		/*
		 * A max queue length of 0 means unlimited, we use it here since we don't want to drop any transactions,
		 * for example when the module is temporarily blocked on writing data to disk.
		 * 
		 * In case transaction_topic is a null pointer this call has no effect.
		 */
		subscribe(transaction_topic, 0);
		
		if(do_auto_save) {
			/*
			 * Register a periodic callback to our save() function.
			 * It will be called from within Super::main().
			 */
			set_timer_millis(auto_save_interval_ms, std::bind(&Database::save, this));
		}
		
		Super::main();		// enter main processing loop
		
		save();				// write data to disk before exit
	}
	
	void add_object(const std::string& table, const std::shared_ptr<const Object>& object) override {
		if(!object) {
			/*
			 * This can happen when either the client sent us a null pointer or the type of object
			 * which was sent to us is not linked into this process and thus cannot be instantiated.
			 */
			return;
		}
		if(table == "user") {
			/*
			 * Function arguments are a private copy for the module,
			 * hence we can just store the given pointer.
			 */
			user->objects[object->get_key()] = object;
		} else {
			throw std::runtime_error("table not found: '" + table + "'");
		}
	}
	
	std::shared_ptr<const Object> get_object(const std::string& table, const std::string& key) const override {
		if(table == "user") {
			auto iter = user->objects.find(key);
			if(iter != user->objects.end()) {
				/*
				 * Function return values are copied back to the client,
				 * hence we can just return a pointer to our copy.
				 */
				return iter->second;
			}
			throw std::runtime_error("object not found: '" + key + "'");
		}
		throw std::runtime_error("table not found: '" + table + "'");
	}
	
	std::vector<std::shared_ptr<const Object>> get_all_objects(const std::string& table) const override {
		if(table == "user") {
			std::vector<std::shared_ptr<const Object>> result;
			for(auto entry : user->objects) {
				/*
				 * Function return values are copied back to the client,
				 * hence we can just return a pointer to our copy.
				 */
				result.push_back(entry.second);
			}
			return result;
		}
		throw std::runtime_error("table not found: '" + table + "'");
	}
	
	void delete_object(const std::string& table, const std::string& key) override {
		if(table == "user") {
			auto iter = user->objects.find(key);
			if(iter != user->objects.end()) {
				user->objects.erase(iter);
			} else {
				throw std::runtime_error("object not found: '" + key + "'");
			}
		} else {
			throw std::runtime_error("table not found: '" + table + "'");
		}
	}
	
	void add_user(const std::string& name) override {
		if(user->objects.find(name) != user->objects.end()) {
			return;
		}
		std::shared_ptr<User> object = User::create();
		object->name = name;
		user->objects[name] = object;
	}
	
	void add_user_balance(const std::string& name, const float64_t& value) override {
		get_object<User>(user, name)->balance += value;
	}
	
	float64_t get_user_balance(const std::string& name) const override {
		return get_const_object<User>(user, name)->balance;
	}
	
	void subtract_user_balance(const std::string& name, const float64_t& value) override {
		get_object<User>(user, name)->balance -= value;
	}
	
	void save() override {
		/*
		 * In this example we just dump all the data to file, overwriting any previous content.
		 */
		vnx::write_to_file(root_path + "user.dat", user);
	}
	
	void handle(std::shared_ptr<const Transaction> value) override {
		switch(value->type) {
			case transaction_type_e::CREDIT:
				add_user_balance(value->to, value->amount);
				break;
			case transaction_type_e::DEBIT:
				subtract_user_balance(value->from, value->amount);
				break;
			case transaction_type_e::TRANSFER:
				add_user_balance(value->to, value->amount);
				subtract_user_balance(value->from, value->amount);
				break;
		}
	}
	
private:
	template<typename T>
	std::shared_ptr<T> get_object(std::shared_ptr<const Table> table, const std::string& key) {
		auto iter = table->objects.find(key);
		if(iter != table->objects.end()) {
			/*
			 * Here we have to const cast our pointer since VNI does not allow non-const pointers.
			 * This is a special case, it's ok since we know the data is ours and no other thread has a pointer to it.
			 */
			std::shared_ptr<T> object = std::dynamic_pointer_cast<T>(std::const_pointer_cast<Object>(iter->second));
			if(!object) {
				throw std::runtime_error("internal error when accessing object: '" + key + "'");
			}
			return object;
		}
		throw std::runtime_error("object not found: '" + key + "'");
	}
	
	template<typename T>
	std::shared_ptr<const T> get_const_object(std::shared_ptr<Table> table, const std::string& key) const {
		auto iter = table->objects.find(key);
		if(iter != table->objects.end()) {
			std::shared_ptr<const T> object = std::dynamic_pointer_cast<const T>(iter->second);
			if(!object) {
				throw std::runtime_error("internal error when accessing object: '" + key + "'");
			}
			return object;
		}
		throw std::runtime_error("object not found: '" + key + "'");
	}
	
private:
	std::shared_ptr<Table> user;
	
};


} // example

#endif /* VNX_EXAMPLES_INCLUDE_EXAMPLE_DATABASE_H_ */
