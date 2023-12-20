cmake_minimum_required(VERSION 3.16)
project(Plagin)

set(CMAKE_CXX_STANDARD 20)

add_library (Plagin STATIC source/Plagin.cpp)

target_link_libraries(Plagin DirectorForFile TableWithAbility TakeDamage Boom)

target_include_directories(Plagin PUBLIC include)
