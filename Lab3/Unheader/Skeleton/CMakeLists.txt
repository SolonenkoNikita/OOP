cmake_minimum_required(VERSION 3.16)
project(Skeleton)

set(CMAKE_CXX_STANDARD 20)

add_library(Skeleton STATIC source/Skeleton.cpp)

target_link_libraries(Skeleton Unhead)

target_include_directories(Skeleton PUBLIC include)
