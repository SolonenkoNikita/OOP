cmake_minimum_required(VERSION 3.16)
project(Base)

set(CMAKE_CXX_STANDARD 20)

add_library(Base INTERFACE)

target_include_directories(Base INTERFACE include)
