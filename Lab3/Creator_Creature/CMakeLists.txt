cmake_minimum_required(VERSION 3.16)
project(Creator_Creature)

set(CMAKE_CXX_STANDARD 20)

add_library (Creator_Creature  STATIC source/Creator_Creature.cpp)

target_link_libraries(Creator_Creature Creature)

target_include_directories(Creator_Creature PUBLIC include)
