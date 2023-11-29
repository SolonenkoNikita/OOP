cmake_minimum_required(VERSION 3.16)
project(Necromancer)

set(CMAKE_CXX_STANDARD 20)

add_library (Necromancer  STATIC source/Necromancer.cpp)

target_link_libraries(Necromancer DirectorForFile OpenDoor Desiccation Curse Necromancy 
									PushEssence
									Morphism TakeDamage Skeleton Ghost Zombie)

target_include_directories(Necromancer PUBLIC include)
