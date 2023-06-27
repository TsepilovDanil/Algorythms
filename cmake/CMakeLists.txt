cmake_minimum_required(VERSION 3.0)

project(algorythms)

#add_subdirectory(testDir)

#add_compile_options(-std=c++14)

#set(CMAKE_CXX_STANDARD 11



add_executable(executable ../Algorythms/src/main.cpp)

target_compile_options(executable PRIVATE -std=c++11)

set_target_properties(
	executable PROPERTIES
	CXX_STANDARD 11
	CXX_STANDARD_REQUIRED ON
)


