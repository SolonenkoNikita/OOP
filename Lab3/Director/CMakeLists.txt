cmake_minimum_required(VERSION 3.16)
project(Director)

set(CMAKE_CXX_STANDARD 20)

add_library(Director INTERFACE)

target_link_libraries(Director INTERFACE Creator_Creature Creature)

target_include_directories(Director INTERFACE include)
