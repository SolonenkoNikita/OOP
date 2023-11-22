cmake_minimum_required(VERSION 3.16)
project(Creature)

set(CMAKE_CXX_STANDARD 20)

add_library (Creature  STATIC source/Creature.cpp)

target_link_libraries(Creature Characteristic 
										TableWithAbility)

target_include_directories(Creature PUBLIC include)
