cmake_minimum_required(VERSION 3.16)
project(Tests)

set(CMAKE_CXX_STANDARD 20)

if(UNIX)
    set(gtest_source_url https://github.com/google/googletest/archive/release-1.11.0.tar.gz)
elseif(WIN32)
    set(gtest_source_url https://github.com/google/googletest/archive/release-1.11.0.zip)
else()
    message(FATAL_ERROR "������������ ������� �� ��������������")
endif()

include(FetchContent)
FetchContent_Declare(
  googletest
  URL ${gtest_source_url}
)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable (Tests   source/main.cpp
                        source/TestsCase1.cpp
                        source/TestsCase2Characteristic.cpp 
                        source/TestsCase3Door.cpp
                        source/TestCase4Abilites.cpp
                        source/TestCase5Golem.cpp source/TestCase6MatrixAndIterator.cpp)

target_link_libraries(Tests gtest
                            gtest_main
                            Characteristic
                            Door
                            OpenDoor
                            MyVector
                            TableWithAbility
                            Lava
                            Necromancy
                            Desiccation
                            TakeDamage
                            Creature
                            Creator_Creature
                            Alive
                            Orc
                            Necromancer
                            Essence
                            Golem
                            MakeCharacteristicForGolem
                            Matrix
                            )

