cmake_minimum_required(VERSION 3.16)
project(Unhead)

set(CMAKE_CXX_STANDARD 20)

add_library(Unhead STATIC source/Unhead.cpp)

target_link_libraries(Unhead DamageCaused Creature Obstacle)

target_include_directories(Unhead PUBLIC include)
