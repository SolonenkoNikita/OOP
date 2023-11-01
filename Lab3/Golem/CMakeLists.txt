cmake_minimum_required(VERSION 3.16)
project(Golem)

set(CMAKE_CXX_STANDARD 20)

add_library (Golem  STATIC source/Golem.cpp)

target_link_libraries(Golem General_Class
							Characteristic
							Cell)

target_include_directories(Golem PUBLIC include)
