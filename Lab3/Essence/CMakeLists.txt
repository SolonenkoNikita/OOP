cmake_minimum_required(VERSION 3.16)
project(Essence)

set(CMAKE_CXX_STANDARD 20)

add_library (Essence STATIC source/Essence.cpp)

target_link_libraries(Essence Obstacle Cell)

target_include_directories(Essence PUBLIC include)
