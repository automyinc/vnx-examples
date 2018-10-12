
## Dependencies

vnx-base, automy-basic, automy-math

## How to compile

`$ ./make.sh`

## Examples

- [Zero-copy publish/subscribe](examples/zero_copy_publish_subscribe)
- [Local UNIX domain publish/subscribe](examples/local_publish_subscribe)
- [Remote TCP publish/subscribe](examples/remote_publish_subscribe)

## Benchmarks

- [Raw data throughput](examples/benchmark_raw_data_throughput)
- [Structured data throughput](examples/benchmark_struct_data_throughput)
- [Synchronous request/response throughput](examples/benchmark_request_response)

## VNI class

- [LidarInfo](interface/LidarInfo.vni)
- [LidarPointCloud](interface/LidarPointCloud.vni)
- [Transaction](interface/Transaction.vni)
- [User](interface/User.vni)

## VNI struct

- [lidar_point_t](interface/lidar_point_t.vni)

## VNI enum

- [transaction_type_e](interface/transaction_type_e.vni)

## VNI package

- [package](interface/package.vni)

## VNI module

- [CameraSensor](modules/CameraSensor.vni)
- [Database](modules/Database.vni)
- [ImageProcessor](modules/ImageProcessor.vni)
- [LidarProcessor](modules/LidarProcessor.vni)
- [LidarSensor](modules/LidarSensor.vni)

## C++ Module

- [CameraSensor](include/example/CameraSensor.h)
- [Database](include/example/Database.h)
- [ImageProcessor](include/example/ImageProcessor.h)
- [LidarProcessor](include/example/LidarProcessor.h)
- [LidarSensor](include/example/LidarSensor.h)

## C++ Process

- [camera_sensor](src/camera_sensor.cpp)
- [lidar_sensor](src/lidar_sensor.cpp)
- [database_server](src/database_server.cpp)
- [image_processor](src/image_processor.cpp)
- [lidar_processor](src/lidar_processor.cpp)

