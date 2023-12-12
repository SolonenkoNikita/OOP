cmake_minimum_required(VERSION 3.16)
project(Search)

set(CMAKE_CXX_STANDARD 20)

add_library(Search STATIC source/Search.cpp)

target_link_libraries(Search Room)

target_include_directories(Search PUBLIC include)
