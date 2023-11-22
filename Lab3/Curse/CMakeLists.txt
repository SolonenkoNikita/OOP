cmake_minimum_required(VERSION 3.16)
project(Curse)

set(CMAKE_CXX_STANDARD 20)

add_library(Curse STATIC source/Curse.cpp)

target_link_libraries(Curse Ability DamageCaused)

target_include_directories(Curse PUBLIC include)
