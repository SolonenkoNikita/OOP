cmake_minimum_required(VERSION 3.16)
project(Dialogue)

set(CMAKE_CXX_STANDARD 20)

add_executable (Dialogue source/main.cpp)

target_link_libraries(Dialogue
							Alive
							Characteristic
							Creator_Creature
							Creature 
							DirectorForFile
							Necromancer
							Orc
							Lava
							Golem
							Cell
							Skeleton
							Unhead
							Matrix
							Room
							VectorForImages
							Controler
							Game
							UnResponsive
							MakeCharacteristicForGolem
							Search
							Door)