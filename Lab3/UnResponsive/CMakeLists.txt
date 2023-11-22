cmake_minimum_required(VERSION 3.16)
project(UnResponsive)

set(CMAKE_CXX_STANDARD 20)

add_library (UnResponsive  STATIC source/UnResponsive.cpp)

target_link_libraries(UnResponsive 
							Obstacle
)

target_include_directories(UnResponsive PUBLIC include)
