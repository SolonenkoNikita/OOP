cmake_minimum_required(VERSION 3.16)
project(Dialugue)

set(CMAKE_CXX_STANDARD 20)

add_executable (Dialugue   source/mainC.cpp)
target_link_libraries(Dialugue WeatherForecast_C)