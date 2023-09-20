cmake_minimum_required(VERSION 3.16)
project(WeatherForecast_C)

set(CMAKE_CXX_STANDARD 20)

add_library (WeatherForecast_C  STATIC source/WeatherForecastC.cpp)

target_link_libraries(WeatherForecast_C DailyForecast)

target_include_directories(WeatherForecast_C PUBLIC include)
