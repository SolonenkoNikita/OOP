cmake_minimum_required(VERSION 3.16)
project(Ability)

set(CMAKE_CXX_STANDARD 20)

add_library(Ability INTERFACE)

target_link_libraries(Ability INTERFACE Cell Characteristic)

target_include_directories(Ability INTERFACE include)
