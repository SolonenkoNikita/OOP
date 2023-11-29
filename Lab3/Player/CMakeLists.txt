cmake_minimum_required(VERSION 3.16)
project(Player)

set(CMAKE_CXX_STANDARD 20)

add_library(Player INTERFACE)

target_link_libraries(Player INTERFACE Base)

target_include_directories(Player INTERFACE include)
