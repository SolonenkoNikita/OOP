cmake_minimum_required(VERSION 3.16)
project(Desiccation)

set(CMAKE_CXX_STANDARD 20)

add_library (Desiccation  STATIC source/Desiccation.cpp)

target_link_libraries(Desiccation Ability Alive)

target_include_directories(Desiccation PUBLIC include)
