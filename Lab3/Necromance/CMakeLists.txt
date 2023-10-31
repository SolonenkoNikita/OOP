cmake_minimum_required(VERSION 3.16)
project(Necromance)

set(CMAKE_CXX_STANDARD 20)

add_library(Necromance STATIC source/Necromance.cpp)

target_link_libraries(Necromance Ability)

target_include_directories(Necromance PUBLIC include)
