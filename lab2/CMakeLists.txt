cmake_minimum_required (VERSION 3.16)

project (lab2)

set(CMAKE_CXX_STANDARD 20)

add_library(prog STATIC Prog.cpp)

add_executable(main main.cpp)

target_link_libraries(main prog)

