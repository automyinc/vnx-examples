cmake_minimum_required(VERSION 2.6)
project(vnx-example)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

file(GLOB GENERATED_SOURCE_FILES generated/src/*.cpp)

add_library(vnx_example SHARED
	${GENERATED_SOURCE_FILES}
	src/LidarInfo.cpp
	)

target_include_directories(vnx_example
	PUBLIC include generated/include
)

target_link_libraries(vnx_example
	automy_basic automy_math vnx_base
)

add_executable(database_server src/database_server.cpp)
target_link_libraries(database_server vnx_example)

add_executable(camera_sensor src/camera_sensor.cpp)
target_link_libraries(camera_sensor vnx_example)

add_executable(image_processor src/image_processor.cpp)
target_link_libraries(image_processor vnx_example)

add_executable(lidar_sensor src/lidar_sensor.cpp)
target_link_libraries(lidar_sensor vnx_example)

add_executable(lidar_processor src/lidar_processor.cpp)
target_link_libraries(lidar_processor vnx_example)

add_subdirectory(examples)
