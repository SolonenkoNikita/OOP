cmake_minimum_required(VERSION 3.16)
project(TakeDamage)

set(CMAKE_CXX_STANDARD 20)

add_library (TakeDamage  STATIC source/TakeDamage.cpp)

target_link_libraries(TakeDamage Ability)

target_include_directories(TakeDamage PUBLIC include)
