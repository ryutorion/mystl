cmake_minimum_required(VERSION 3.17.3)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(
	mystl
	VERSION 0.0.1
	LANGUAGES CXX
)

add_executable(
	mystl
	main.cpp
)

target_include_directories(
	mystl
	PRIVATE
	include
)

if(MSVC)
	target_compile_options(mystl PRIVATE "/permissive-")
endif()
