cmake_minimum_required(VERSION 2.6)
project(example)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

file(GLOB GENERATED_SOURCE_FILES generated/src/*.cpp)

add_library(example SHARED
	${GENERATED_SOURCE_FILES}
	src/LidarInfo.cpp
	src/Object.cpp
	src/User.cpp
)

target_include_directories(example
	PUBLIC include generated/include
)

target_link_libraries(example
	automy_basic automy_math vnx_base
)

add_executable(database_server src/database_server.cpp)
target_link_libraries(database_server example)

add_executable(camera_sensor src/camera_sensor.cpp)
target_link_libraries(camera_sensor example)

add_subdirectory(examples)
