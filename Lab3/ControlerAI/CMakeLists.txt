cmake_minimum_required(VERSION 3.16)
project(ControlerAI)

set(CMAKE_CXX_STANDARD 20)

add_library (ControlerAI STATIC source/ControlerAI.cpp)

target_link_libraries(ControlerAI Room Player Controler)

target_include_directories(ControlerAI PUBLIC include)
