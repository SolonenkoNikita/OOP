cmake_minimum_required(VERSION 3.16)
project(MakeCharacteristicForGolem)

set(CMAKE_CXX_STANDARD 20)

add_library (MakeCharacteristicForGolem STATIC source/MakeCharacteristicForGolem.cpp)

target_link_libraries(MakeCharacteristicForGolem Characteristic)

target_include_directories(MakeCharacteristicForGolem PUBLIC include)
