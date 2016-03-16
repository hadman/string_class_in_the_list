cmake_minimum_required(VERSION 3.3)
project(string_class_in_the_list)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(string_class_in_the_list ${SOURCE_FILES})