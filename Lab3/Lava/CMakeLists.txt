cmake_minimum_required(VERSION 3.16)
project(Lava)

set(CMAKE_CXX_STANDARD 20)

add_library(Lava STATIC source/Lava.cpp)

target_link_libraries(Lava
							DamageCaused
							Cell)

target_include_directories(Lava PUBLIC include)
