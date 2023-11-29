cmake_minimum_required(VERSION 3.16)
project(Alive)

set(CMAKE_CXX_STANDARD 20)

add_library(Alive STATIC source/Alive.cpp)

target_link_libraries(Alive Cell DamageCaused Creature Player)

target_include_directories(Alive PUBLIC include)
