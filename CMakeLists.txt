cmake_minimum_required(VERSION 3.6)
project(Tec_Media_File_System)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(Tec_Media_File_System ${SOURCE_FILES})