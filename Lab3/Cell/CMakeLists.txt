cmake_minimum_required(VERSION 3.16)
project(Cell)

set(CMAKE_CXX_STANDARD 20)

add_library(Cell STATIC source/Cell.cpp)

target_link_libraries(Cell General_Class)

target_include_directories(Creature PUBLIC include)
