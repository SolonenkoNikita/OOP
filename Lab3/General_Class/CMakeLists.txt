cmake_minimum_required(VERSION 3.16)
project(General_Class)

set(CMAKE_CXX_STANDARD 20)

add_library(General_Class STATIC source/General_Class.cpp)

target_link_libraries(General_Class
							Cell)

target_include_directories(General_Class PUBLIC include)
