cmake_minimum_required(VERSION 3.16)
project(VectorForImages)

set(CMAKE_CXX_STANDARD 20)

add_library (VectorForImages  STATIC source/VectorForImages.cpp)

target_include_directories(VectorForImages PUBLIC include)
