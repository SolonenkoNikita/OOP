cmake_minimum_required(VERSION 3.16)
project(TableWithAbility)

set(CMAKE_CXX_STANDARD 20)

add_library(TableWithAbility STATIC source/TableWithAbility.cpp)

target_link_libraries(TableWithAbility	
							Ability)

target_include_directories(TableWithAbility PUBLIC include)
