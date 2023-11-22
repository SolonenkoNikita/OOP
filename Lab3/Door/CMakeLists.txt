cmake_minimum_required(VERSION 3.16)
project(Door)

set(CMAKE_CXX_STANDARD 20)

add_library(Door STATIC source/Door.cpp)

target_link_libraries(Door	
							Cell
							DamageCaused
							Obstacle)

target_include_directories(Door PUBLIC include)
