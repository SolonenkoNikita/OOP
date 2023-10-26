cmake_minimum_required(VERSION 3.16)
project(Ability)

set(CMAKE_CXX_STANDARD 20)

add_library(Ability STATIC source/Ability.cpp)

target_link_libraries(Ability Cell Creature)

target_include_directories(Ability PUBLIC include)
