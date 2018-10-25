
## Dependencies

vnx-base, automy-basic, automy-math

## How to compile

`$ ./make.sh`

## Examples

- [Configuration](examples/configuration_example)
- [Zero-copy publish/subscribe](examples/zero_copy_publish_subscribe)
- [Local UNIX domain publish/subscribe](examples/local_publish_subscribe)
- [Remote TCP publish/subscribe](examples/remote_publish_subscribe)

## Benchmarks

- [Raw data throughput](examples/benchmark_raw_data_throughput)
- [Structured data throughput](examples/benchmark_struct_data_throughput)
- [Synchronous request/response throughput](examples/benchmark_request_response)

## VNI class

- [LidarInfo.vni](interface/LidarInfo.vni)
- [LidarPointCloud.vni](interface/LidarPointCloud.vni)
- [Transaction.vni](interface/Transaction.vni)
- [User.vni](interface/User.vni)

## VNI struct

- [lidar_point_t.vni](interface/lidar_point_t.vni)

## VNI enum

- [transaction_type_e.vni](interface/transaction_type_e.vni)

## VNI package

- [package.vni](interface/package.vni)

## VNI module

- [CameraSensor.vni](modules/CameraSensor.vni)
- [Database.vni](modules/Database.vni)
- [ImageProcessor.vni](modules/ImageProcessor.vni)
- [LidarProcessor.vni](modules/LidarProcessor.vni)
- [LidarSensor.vni](modules/LidarSensor.vni)

## C++ Module

- [CameraSensor.h](include/example/CameraSensor.h)
- [Database.h](include/example/Database.h)
- [ImageProcessor.h](include/example/ImageProcessor.h)
- [LidarProcessor.h](include/example/LidarProcessor.h)
- [LidarSensor.h](include/example/LidarSensor.h)

## C++ Process

- [camera_sensor.cpp](src/camera_sensor.cpp)
- [lidar_sensor.cpp](src/lidar_sensor.cpp)
- [database_server.cpp](src/database_server.cpp)
- [image_processor.cpp](src/image_processor.cpp)
- [lidar_processor.cpp](src/lidar_processor.cpp)

## How to generate code

- [codegen.sh](codegen.sh)

