cmake_minimum_required(VERSION 3.6)
project(Tec_Media_File_System)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp client.cpp server.cpp client.h server.h tinyxml2.cpp tinyxml2.h)
add_executable(Tec_Media_File_System ${SOURCE_FILES})

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(Tec_Media_File_System Threads::Threads)