cmake_minimum_required(VERSION 3.16)
project(Matrix)

set(CMAKE_CXX_STANDARD 20)

add_library (Matrix  STATIC source/Matrix.cpp)

target_link_libraries(Matrix MyVector)

target_include_directories(Matrix PUBLIC include)
