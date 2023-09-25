cmake_minimum_required(VERSION 3.16)
project(WeatherForecast)

set(CMAKE_CXX_STANDARD 20)

add_library (WeatherForecast  STATIC source/WeatherForecast.cpp)

target_link_libraries(WeatherForecast DailyForecast)

target_include_directories(WeatherForecast PUBLIC include)
