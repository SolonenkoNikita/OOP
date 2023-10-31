cmake_minimum_required(VERSION 3.16)
project(Zombie)

set(CMAKE_CXX_STANDARD 20)

add_library(Zombie STATIC source/Zombie.cpp)

target_link_libraries(Zombie Unhead)

target_include_directories(Zombie PUBLIC include)
