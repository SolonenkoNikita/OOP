cmake_minimum_required(VERSION 3.16)
project(Ghost)

set(CMAKE_CXX_STANDARD 20)

add_library(Ghost STATIC source/Ghost.cpp)

target_link_libraries(Ghost Unhead)

target_include_directories(Ghost PUBLIC include)
