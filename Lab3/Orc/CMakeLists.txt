cmake_minimum_required(VERSION 3.16)
project(Orc)

set(CMAKE_CXX_STANDARD 20)

add_library (Orc STATIC source/Orc.cpp)

target_link_libraries(Orc DirectorForFile TableWithAbility TakeDamage)

target_include_directories(Orc PUBLIC include)
