cmake_minimum_required(VERSION 2.6)
project(example)

file(GLOB GENERATED_SOURCE_FILES generated/src/*.cpp)

add_library(example SHARED
	${GENERATED_SOURCE_FILES}
	src/LidarInfo.cpp
)

target_include_directories(example
	PUBLIC include generated/include
)

target_link_libraries(example
	automy_basic automy_math vnx_base
)

add_executable(database_main src/database_main.cpp)
target_link_libraries(database_main example)
