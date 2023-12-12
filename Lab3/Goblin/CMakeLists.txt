cmake_minimum_required(VERSION 3.16)
project(Goblin)

set(CMAKE_CXX_STANDARD 20)

add_library (Goblin STATIC source/Goblin.cpp)

target_link_libraries(Goblin DirectorForFile TableWithAbility TakeDamage)

target_include_directories(Goblin PUBLIC include)
