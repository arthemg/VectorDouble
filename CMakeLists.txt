cmake_minimum_required(VERSION 3.6)
project(Vector_double)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp vector_double.cpp vector_double.h)
add_executable(Vector_double ${SOURCE_FILES})