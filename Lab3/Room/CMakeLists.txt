cmake_minimum_required(VERSION 3.16)
project(Room)

set(CMAKE_CXX_STANDARD 20)

add_library(Room STATIC source/Room.cpp)

target_link_libraries(Room Matrix Cell)

target_include_directories(Room PUBLIC include)
