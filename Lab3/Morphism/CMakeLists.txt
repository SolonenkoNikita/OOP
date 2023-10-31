cmake_minimum_required(VERSION 3.16)
project(Morphism)

set(CMAKE_CXX_STANDARD 20)

add_library(Morphism STATIC source/Morphism.cpp)

target_link_libraries(Morphism Ability)

target_include_directories(Morphism PUBLIC include)
