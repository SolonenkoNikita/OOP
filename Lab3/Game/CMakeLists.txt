cmake_minimum_required(VERSION 3.16)
project(Game)

set(CMAKE_CXX_STANDARD 20)

add_library(Game STATIC source/Game.cpp)

target_link_libraries(Game
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
							ControlerPlayer
							ControlerAI
							Lava;
							UnResponsive
							MakeCharacteristicForGolem
							Golem
							Door)
target_include_directories(Game PUBLIC include)