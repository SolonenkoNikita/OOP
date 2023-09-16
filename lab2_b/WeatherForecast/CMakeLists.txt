cmake_minimum_required(VERSION 3.16)
project(WeatherForecast)

set(CMAKE_CXX_STANDARD 20)

add_executable (WeatherForecast  prog/WeatherForecast.cpp)

target_link_directories(WeatherForecast PUBLIC include)

target_link_libraries(WeatherForecast DailyForecast)