cmake_minimum_required(VERSION 3.16)
project(Necromancy)

set(CMAKE_CXX_STANDARD 20)

add_library(Necromancy STATIC source/Necromancy.cpp)

target_link_libraries(Necromancy Ability Alive Unhead)

target_include_directories(Necromancy PUBLIC include)


