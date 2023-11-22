cmake_minimum_required(VERSION 3.16)
project(PushEssence)

set(CMAKE_CXX_STANDARD 20)

add_library(PushEssence STATIC source/PushEssence.cpp)

target_link_libraries(PushEssence
							Ability
							Essence)

target_include_directories(PushEssence PUBLIC include)
