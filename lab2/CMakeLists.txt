cmake_minimum_required (VERSION 3.16)

project (lab2)

set(CMAKE_CXX_STANDARD 20)

add_library(prog STATIC Prog.cpp)

#add_executable(main main.cpp)

#target_link_libraries(main prog)

include(FetchContent)
FetchContent_Declare(
  googletest 
  URL https://github.com/google/googletest/archive/release-1.11.0.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(lab2 main.cpp Prog.cpp
                       TestCase1.cpp)

target_link_libraries(lab2 gtest gtest_main)

