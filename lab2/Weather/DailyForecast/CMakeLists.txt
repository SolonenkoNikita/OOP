cmake_minimum_required(VERSION 3.16)
project(DailyForecast)

set(CMAKE_CXX_STANDARD 20)

add_library(DailyForecast STATIC source/DailyForecast.cpp)

target_include_directories(DailyForecast PUBLIC include)