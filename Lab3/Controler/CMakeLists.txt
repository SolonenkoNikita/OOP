cmake_minimum_required(VERSION 3.16)
project(Controler)

set(CMAKE_CXX_STANDARD 20)

add_library (Controler INTERFACE)

#target_link_libraries(Controler Room Player)

target_include_directories(Controler INTERFACE include)
