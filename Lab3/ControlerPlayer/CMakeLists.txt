cmake_minimum_required(VERSION 3.16)
project(ControlerPlayer)

set(CMAKE_CXX_STANDARD 20)

add_library (ControlerPlayer STATIC source/ControlerPlayer.cpp)

target_link_libraries(ControlerPlayer Room Player Controler)

target_include_directories(ControlerPlayer PUBLIC include)
