cmake_minimum_required(VERSION 3.16)
project(Utilits)

set(CMAKE_CXX_STANDARD 20)

add_library(Utilits INTERFACE)

target_include_directories(Utilits INTERFACE include)