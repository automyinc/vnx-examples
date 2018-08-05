
#ifndef VNX_EXAMPLES_INCLUDE_EXAMPLE_DATABASE_H_
#define VNX_EXAMPLES_INCLUDE_EXAMPLE_DATABASE_H_

#include <example/DatabaseBase.hxx>
#include <example/User.hxx>

#include <vnx/Input.h>
#include <vnx/Output.h>


namespace example {

class Database : public DatabaseBase {
public:
	Database(const std::string& _vnx_name)
		:	DatabaseBase(_vnx_name)
	{
	}
	
protected:
	
	void main() override {
		
		/*
		 * First we load existing data into memory.
		 * If no data found we create an empty table.
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
		 * A max queue length of 0 means unlimited, we use it here since we don't want to
		 * drop any transactions, like when we are blocked on writing data to disk.
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
		
		save();				// save upon exit
	}
	
	std::shared_ptr<const Table> get_table(const std::string& name) const override {
		if(name == "user") {
			return user;
		}
		throw std::runtime_error("table not found: '" + name + "'");
	}
	
	void add_object(const std::string& table, const std::string& key, const std::shared_ptr<const Object>& object) override {
		if(table == "user") {
			user->objects[key] = vnx::clone(object);
		} else {
			throw std::runtime_error("table not found: '" + table + "'");
		}
	}
	
	std::shared_ptr<const Object> get_object(const std::string& table, const std::string& key) const override {
		if(table == "user") {
			auto iter = user->objects.find(key);
			if(iter != user->objects.end()) {
				return iter->second;
			}
			throw std::runtime_error("object not found: '" + key + "'");
		} else {
			throw std::runtime_error("table not found: '" + table + "'");
		}
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
			throw std::runtime_error("user already exists: '" + name + "'");
		}
		std::shared_ptr<User> object = User::create();
		object->name = name;
		user->objects[name] = object;
	}
	
	void add_user_balance(const std::string& name, const float64_t& value) override {
		auto iter = user->objects.find(name);
		if(iter != user->objects.end()) {
			get_user(name)->balance += value;
		} else {
			throw std::runtime_error("user not found: '" + name + "'");
		}
	}
	
	float64_t get_user_balance(const std::string& name) const override {
		auto iter = user->objects.find(name);
		if(iter != user->objects.end()) {
			return get_user(name)->balance;
		}
		throw std::runtime_error("user not found: '" + name + "'");
	}
	
	void subtract_user_balance(const std::string& name, const float64_t& value) override {
		auto iter = user->objects.find(name);
		if(iter != user->objects.end()) {
			get_user(name)->balance -= value;
		} else {
			throw std::runtime_error("user not found: '" + name + "'");
		}
	}
	
	void save() override {
		vnx::write_to_file(root_path + "user.dat", user);
	}
	
	void handle(std::shared_ptr<const Transaction> value) override {
		// TODO
	}
	
private:
	std::shared_ptr<User> get_user(const std::string& name) const {
		auto iter = user->objects.find(name);
		if(iter != user->objects.end()) {
			std::shared_ptr<User> object = std::dynamic_pointer_cast<User>(iter->second);
			if(!object) {
				throw std::runtime_error("internal error when accessing user: '" + name + "'");
			}
			return object;
		}
		throw std::runtime_error("user not found: '" + name + "'");
	}
	
private:
	std::shared_ptr<Table> user;
	
};


} // example

#endif /* VNX_EXAMPLES_INCLUDE_EXAMPLE_DATABASE_H_ */
