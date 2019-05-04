
// AUTO GENERATED by vnxcppcodegen

#ifndef INCLUDE_example_PACKAGE_HXX_
#define INCLUDE_example_PACKAGE_HXX_

#include <vnx/Type.h>

#include <automy/basic/package.hxx>
#include <automy/math/package.hxx>
#include <vnx/package.hxx>


namespace example {

extern std::shared_ptr<vnx::Topic> transactions;

class CameraSensorBase;
class DatabaseBase;
class ImageProcessorBase;
class LidarInfo;
class LidarPointCloud;
class LidarProcessorBase;
class LidarSensorBase;
class Mat;
class Transaction;
class User;
struct lidar_point_t;
struct transaction_type_e;

} // namespace example


namespace vnx {

void read(TypeInput& in, ::example::CameraSensorBase& value, const TypeCode* type_code, const uint16_t* code); ///< \private
void read(TypeInput& in, ::example::DatabaseBase& value, const TypeCode* type_code, const uint16_t* code); ///< \private
void read(TypeInput& in, ::example::ImageProcessorBase& value, const TypeCode* type_code, const uint16_t* code); ///< \private
void read(TypeInput& in, ::example::LidarInfo& value, const TypeCode* type_code, const uint16_t* code); ///< \private
void read(TypeInput& in, ::example::LidarPointCloud& value, const TypeCode* type_code, const uint16_t* code); ///< \private
void read(TypeInput& in, ::example::LidarProcessorBase& value, const TypeCode* type_code, const uint16_t* code); ///< \private
void read(TypeInput& in, ::example::LidarSensorBase& value, const TypeCode* type_code, const uint16_t* code); ///< \private
void read(TypeInput& in, ::example::Mat& value, const TypeCode* type_code, const uint16_t* code); ///< \private
void read(TypeInput& in, ::example::Transaction& value, const TypeCode* type_code, const uint16_t* code); ///< \private
void read(TypeInput& in, ::example::User& value, const TypeCode* type_code, const uint16_t* code); ///< \private
void read(TypeInput& in, ::example::lidar_point_t& value, const TypeCode* type_code, const uint16_t* code); ///< \private
void read(TypeInput& in, ::example::transaction_type_e& value, const TypeCode* type_code, const uint16_t* code); ///< \private

void write(TypeOutput& out, const ::example::CameraSensorBase& value, const TypeCode* type_code, const uint16_t* code); ///< \private
void write(TypeOutput& out, const ::example::DatabaseBase& value, const TypeCode* type_code, const uint16_t* code); ///< \private
void write(TypeOutput& out, const ::example::ImageProcessorBase& value, const TypeCode* type_code, const uint16_t* code); ///< \private
void write(TypeOutput& out, const ::example::LidarInfo& value, const TypeCode* type_code, const uint16_t* code); ///< \private
void write(TypeOutput& out, const ::example::LidarPointCloud& value, const TypeCode* type_code, const uint16_t* code); ///< \private
void write(TypeOutput& out, const ::example::LidarProcessorBase& value, const TypeCode* type_code, const uint16_t* code); ///< \private
void write(TypeOutput& out, const ::example::LidarSensorBase& value, const TypeCode* type_code, const uint16_t* code); ///< \private
void write(TypeOutput& out, const ::example::Mat& value, const TypeCode* type_code, const uint16_t* code); ///< \private
void write(TypeOutput& out, const ::example::Transaction& value, const TypeCode* type_code, const uint16_t* code); ///< \private
void write(TypeOutput& out, const ::example::User& value, const TypeCode* type_code, const uint16_t* code); ///< \private
void write(TypeOutput& out, const ::example::lidar_point_t& value, const TypeCode* type_code, const uint16_t* code); ///< \private
void write(TypeOutput& out, const ::example::transaction_type_e& value, const TypeCode* type_code, const uint16_t* code); ///< \private

void read(std::istream& in, ::example::CameraSensorBase& value); ///< \private
void read(std::istream& in, ::example::DatabaseBase& value); ///< \private
void read(std::istream& in, ::example::ImageProcessorBase& value); ///< \private
void read(std::istream& in, ::example::LidarInfo& value); ///< \private
void read(std::istream& in, ::example::LidarPointCloud& value); ///< \private
void read(std::istream& in, ::example::LidarProcessorBase& value); ///< \private
void read(std::istream& in, ::example::LidarSensorBase& value); ///< \private
void read(std::istream& in, ::example::Mat& value); ///< \private
void read(std::istream& in, ::example::Transaction& value); ///< \private
void read(std::istream& in, ::example::User& value); ///< \private
void read(std::istream& in, ::example::lidar_point_t& value); ///< \private
void read(std::istream& in, ::example::transaction_type_e& value); ///< \private

void write(std::ostream& out, const ::example::CameraSensorBase& value); ///< \private
void write(std::ostream& out, const ::example::DatabaseBase& value); ///< \private
void write(std::ostream& out, const ::example::ImageProcessorBase& value); ///< \private
void write(std::ostream& out, const ::example::LidarInfo& value); ///< \private
void write(std::ostream& out, const ::example::LidarPointCloud& value); ///< \private
void write(std::ostream& out, const ::example::LidarProcessorBase& value); ///< \private
void write(std::ostream& out, const ::example::LidarSensorBase& value); ///< \private
void write(std::ostream& out, const ::example::Mat& value); ///< \private
void write(std::ostream& out, const ::example::Transaction& value); ///< \private
void write(std::ostream& out, const ::example::User& value); ///< \private
void write(std::ostream& out, const ::example::lidar_point_t& value); ///< \private
void write(std::ostream& out, const ::example::transaction_type_e& value); ///< \private

void accept(Visitor& visitor, const ::example::CameraSensorBase& value); ///< \private
void accept(Visitor& visitor, const ::example::DatabaseBase& value); ///< \private
void accept(Visitor& visitor, const ::example::ImageProcessorBase& value); ///< \private
void accept(Visitor& visitor, const ::example::LidarInfo& value); ///< \private
void accept(Visitor& visitor, const ::example::LidarPointCloud& value); ///< \private
void accept(Visitor& visitor, const ::example::LidarProcessorBase& value); ///< \private
void accept(Visitor& visitor, const ::example::LidarSensorBase& value); ///< \private
void accept(Visitor& visitor, const ::example::Mat& value); ///< \private
void accept(Visitor& visitor, const ::example::Transaction& value); ///< \private
void accept(Visitor& visitor, const ::example::User& value); ///< \private
void accept(Visitor& visitor, const ::example::lidar_point_t& value); ///< \private
void accept(Visitor& visitor, const ::example::transaction_type_e& value); ///< \private

/// \private
template<>
struct type<::example::CameraSensorBase> {
	void read(TypeInput& in, ::example::CameraSensorBase& value, const TypeCode* type_code, const uint16_t* code) {
		vnx::read(in, value, type_code, code);
	}
	void write(TypeOutput& out, const ::example::CameraSensorBase& value, const TypeCode* type_code, const uint16_t* code) {
		vnx::write(out, value, type_code, code);
	}
	void read(std::istream& in, ::example::CameraSensorBase& value) {
		vnx::read(in, value);
	}
	void write(std::ostream& out, const ::example::CameraSensorBase& value) {
		vnx::write(out, value);
	}
	void accept(Visitor& visitor, const ::example::CameraSensorBase& value) {
		vnx::accept(visitor, value);
	}
	void create_dynamic_code(std::vector<uint16_t>& code) {
		code.push_back(CODE_ANY);
	}
};

/// \private
template<>
struct type<::example::DatabaseBase> {
	void read(TypeInput& in, ::example::DatabaseBase& value, const TypeCode* type_code, const uint16_t* code) {
		vnx::read(in, value, type_code, code);
	}
	void write(TypeOutput& out, const ::example::DatabaseBase& value, const TypeCode* type_code, const uint16_t* code) {
		vnx::write(out, value, type_code, code);
	}
	void read(std::istream& in, ::example::DatabaseBase& value) {
		vnx::read(in, value);
	}
	void write(std::ostream& out, const ::example::DatabaseBase& value) {
		vnx::write(out, value);
	}
	void accept(Visitor& visitor, const ::example::DatabaseBase& value) {
		vnx::accept(visitor, value);
	}
	void create_dynamic_code(std::vector<uint16_t>& code) {
		code.push_back(CODE_ANY);
	}
};

/// \private
template<>
struct type<::example::ImageProcessorBase> {
	void read(TypeInput& in, ::example::ImageProcessorBase& value, const TypeCode* type_code, const uint16_t* code) {
		vnx::read(in, value, type_code, code);
	}
	void write(TypeOutput& out, const ::example::ImageProcessorBase& value, const TypeCode* type_code, const uint16_t* code) {
		vnx::write(out, value, type_code, code);
	}
	void read(std::istream& in, ::example::ImageProcessorBase& value) {
		vnx::read(in, value);
	}
	void write(std::ostream& out, const ::example::ImageProcessorBase& value) {
		vnx::write(out, value);
	}
	void accept(Visitor& visitor, const ::example::ImageProcessorBase& value) {
		vnx::accept(visitor, value);
	}
	void create_dynamic_code(std::vector<uint16_t>& code) {
		code.push_back(CODE_ANY);
	}
};

/// \private
template<>
struct type<::example::LidarInfo> {
	void read(TypeInput& in, ::example::LidarInfo& value, const TypeCode* type_code, const uint16_t* code) {
		vnx::read(in, value, type_code, code);
	}
	void write(TypeOutput& out, const ::example::LidarInfo& value, const TypeCode* type_code, const uint16_t* code) {
		vnx::write(out, value, type_code, code);
	}
	void read(std::istream& in, ::example::LidarInfo& value) {
		vnx::read(in, value);
	}
	void write(std::ostream& out, const ::example::LidarInfo& value) {
		vnx::write(out, value);
	}
	void accept(Visitor& visitor, const ::example::LidarInfo& value) {
		vnx::accept(visitor, value);
	}
	void create_dynamic_code(std::vector<uint16_t>& code) {
		code.push_back(CODE_ANY);
	}
};

/// \private
template<>
struct type<::example::LidarPointCloud> {
	void read(TypeInput& in, ::example::LidarPointCloud& value, const TypeCode* type_code, const uint16_t* code) {
		vnx::read(in, value, type_code, code);
	}
	void write(TypeOutput& out, const ::example::LidarPointCloud& value, const TypeCode* type_code, const uint16_t* code) {
		vnx::write(out, value, type_code, code);
	}
	void read(std::istream& in, ::example::LidarPointCloud& value) {
		vnx::read(in, value);
	}
	void write(std::ostream& out, const ::example::LidarPointCloud& value) {
		vnx::write(out, value);
	}
	void accept(Visitor& visitor, const ::example::LidarPointCloud& value) {
		vnx::accept(visitor, value);
	}
	void create_dynamic_code(std::vector<uint16_t>& code) {
		code.push_back(CODE_ANY);
	}
};

/// \private
template<>
struct type<::example::LidarProcessorBase> {
	void read(TypeInput& in, ::example::LidarProcessorBase& value, const TypeCode* type_code, const uint16_t* code) {
		vnx::read(in, value, type_code, code);
	}
	void write(TypeOutput& out, const ::example::LidarProcessorBase& value, const TypeCode* type_code, const uint16_t* code) {
		vnx::write(out, value, type_code, code);
	}
	void read(std::istream& in, ::example::LidarProcessorBase& value) {
		vnx::read(in, value);
	}
	void write(std::ostream& out, const ::example::LidarProcessorBase& value) {
		vnx::write(out, value);
	}
	void accept(Visitor& visitor, const ::example::LidarProcessorBase& value) {
		vnx::accept(visitor, value);
	}
	void create_dynamic_code(std::vector<uint16_t>& code) {
		code.push_back(CODE_ANY);
	}
};

/// \private
template<>
struct type<::example::LidarSensorBase> {
	void read(TypeInput& in, ::example::LidarSensorBase& value, const TypeCode* type_code, const uint16_t* code) {
		vnx::read(in, value, type_code, code);
	}
	void write(TypeOutput& out, const ::example::LidarSensorBase& value, const TypeCode* type_code, const uint16_t* code) {
		vnx::write(out, value, type_code, code);
	}
	void read(std::istream& in, ::example::LidarSensorBase& value) {
		vnx::read(in, value);
	}
	void write(std::ostream& out, const ::example::LidarSensorBase& value) {
		vnx::write(out, value);
	}
	void accept(Visitor& visitor, const ::example::LidarSensorBase& value) {
		vnx::accept(visitor, value);
	}
	void create_dynamic_code(std::vector<uint16_t>& code) {
		code.push_back(CODE_ANY);
	}
};

/// \private
template<>
struct type<::example::Mat> {
	void read(TypeInput& in, ::example::Mat& value, const TypeCode* type_code, const uint16_t* code) {
		vnx::read(in, value, type_code, code);
	}
	void write(TypeOutput& out, const ::example::Mat& value, const TypeCode* type_code, const uint16_t* code) {
		vnx::write(out, value, type_code, code);
	}
	void read(std::istream& in, ::example::Mat& value) {
		vnx::read(in, value);
	}
	void write(std::ostream& out, const ::example::Mat& value) {
		vnx::write(out, value);
	}
	void accept(Visitor& visitor, const ::example::Mat& value) {
		vnx::accept(visitor, value);
	}
	void create_dynamic_code(std::vector<uint16_t>& code) {
		const std::vector<int> tmp = {17};
		code.insert(code.end(), tmp.begin(), tmp.end());
	}
};

/// \private
template<>
struct type<::example::Transaction> {
	void read(TypeInput& in, ::example::Transaction& value, const TypeCode* type_code, const uint16_t* code) {
		vnx::read(in, value, type_code, code);
	}
	void write(TypeOutput& out, const ::example::Transaction& value, const TypeCode* type_code, const uint16_t* code) {
		vnx::write(out, value, type_code, code);
	}
	void read(std::istream& in, ::example::Transaction& value) {
		vnx::read(in, value);
	}
	void write(std::ostream& out, const ::example::Transaction& value) {
		vnx::write(out, value);
	}
	void accept(Visitor& visitor, const ::example::Transaction& value) {
		vnx::accept(visitor, value);
	}
	void create_dynamic_code(std::vector<uint16_t>& code) {
		code.push_back(CODE_ANY);
	}
};

/// \private
template<>
struct type<::example::User> {
	void read(TypeInput& in, ::example::User& value, const TypeCode* type_code, const uint16_t* code) {
		vnx::read(in, value, type_code, code);
	}
	void write(TypeOutput& out, const ::example::User& value, const TypeCode* type_code, const uint16_t* code) {
		vnx::write(out, value, type_code, code);
	}
	void read(std::istream& in, ::example::User& value) {
		vnx::read(in, value);
	}
	void write(std::ostream& out, const ::example::User& value) {
		vnx::write(out, value);
	}
	void accept(Visitor& visitor, const ::example::User& value) {
		vnx::accept(visitor, value);
	}
	void create_dynamic_code(std::vector<uint16_t>& code) {
		code.push_back(CODE_ANY);
	}
};

/// \private
template<>
struct type<::example::lidar_point_t> {
	void read(TypeInput& in, ::example::lidar_point_t& value, const TypeCode* type_code, const uint16_t* code) {
		vnx::read(in, value, type_code, code);
	}
	void write(TypeOutput& out, const ::example::lidar_point_t& value, const TypeCode* type_code, const uint16_t* code) {
		vnx::write(out, value, type_code, code);
	}
	void read(std::istream& in, ::example::lidar_point_t& value) {
		vnx::read(in, value);
	}
	void write(std::ostream& out, const ::example::lidar_point_t& value) {
		vnx::write(out, value);
	}
	void accept(Visitor& visitor, const ::example::lidar_point_t& value) {
		vnx::accept(visitor, value);
	}
	void create_dynamic_code(std::vector<uint16_t>& code) {
		code.push_back(CODE_ANY);
	}
};

/// \private
template<>
struct type<::example::transaction_type_e> {
	void read(TypeInput& in, ::example::transaction_type_e& value, const TypeCode* type_code, const uint16_t* code) {
		vnx::read(in, value, type_code, code);
	}
	void write(TypeOutput& out, const ::example::transaction_type_e& value, const TypeCode* type_code, const uint16_t* code) {
		vnx::write(out, value, type_code, code);
	}
	void read(std::istream& in, ::example::transaction_type_e& value) {
		vnx::read(in, value);
	}
	void write(std::ostream& out, const ::example::transaction_type_e& value) {
		vnx::write(out, value);
	}
	void accept(Visitor& visitor, const ::example::transaction_type_e& value) {
		vnx::accept(visitor, value);
	}
	void create_dynamic_code(std::vector<uint16_t>& code) {
		code.push_back(CODE_ANY);
	}
};


} // namespace vnx

#endif // INCLUDE_example_PACKAGE_HXX_
