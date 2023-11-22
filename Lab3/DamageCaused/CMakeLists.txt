cmake_minimum_required(VERSION 3.16)
project(DamageCaused)

set(CMAKE_CXX_STANDARD 20)

add_library(DamageCaused INTERFACE)

target_link_libraries(DamageCaused INTERFACE Base)

target_include_directories(DamageCaused INTERFACE include)