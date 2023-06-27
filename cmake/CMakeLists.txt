cmake_minimum_required(VERSION 3.0)

project(algorythms)

add_executable(executable ../Algorythms/src/main.cpp)

set_target_properties(
	executable PROPERTIES
	CXX_STANDARD 11
	CXX_STANDARD_REQUIRED ON
)


