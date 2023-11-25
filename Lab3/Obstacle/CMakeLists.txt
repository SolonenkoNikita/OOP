cmake_minimum_required(VERSION 3.16)
project(Obstacle)

set(CMAKE_CXX_STANDARD 20)

add_library(Obstacle INTERFACE)

target_link_libraries(Obstacle INTERFACE Base Cell)

target_include_directories(Obstacle INTERFACE include)
