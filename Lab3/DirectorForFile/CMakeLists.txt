cmake_minimum_required(VERSION 3.16)
project(DirectorForFile)

set(CMAKE_CXX_STANDARD 20)

add_library(DirectorForFile STATIC source/DirectorForFile.cpp)

target_link_libraries(DirectorForFile Director)

target_include_directories(DirectorForFile PUBLIC include)
