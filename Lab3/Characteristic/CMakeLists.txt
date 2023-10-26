cmake_minimum_required(VERSION 3.16)
project(Characteristic)

set(CMAKE_CXX_STANDARD 20)

add_library (Characteristic  STATIC source/Characteristic.cpp)

target_include_directories(Characteristic PUBLIC include)
