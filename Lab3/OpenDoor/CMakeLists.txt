cmake_minimum_required(VERSION 3.16)
project(OpenDoor)

set(CMAKE_CXX_STANDARD 20)

add_library (OpenDoor  STATIC source/OpenDoor.cpp)

target_link_libraries(OpenDoor Ability Door)

target_include_directories(OpenDoor PUBLIC include)
