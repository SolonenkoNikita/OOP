cmake_minimum_required(VERSION 3.16)
project(MyVector)

set(CMAKE_CXX_STANDARD 20)

add_library (MyVector  STATIC source/MyVector.cpp)

target_include_directories(MyVector PUBLIC include)
