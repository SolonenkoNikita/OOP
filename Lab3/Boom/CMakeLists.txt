cmake_minimum_required(VERSION 3.16)
project(Boom)

set(CMAKE_CXX_STANDARD 20)

add_library (Boom STATIC source/Boom.cpp)

target_link_libraries(Boom Ability)

target_include_directories(Boom PUBLIC include)
