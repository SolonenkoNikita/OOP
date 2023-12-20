cmake_minimum_required (VERSION 3.16)

project (Lab3)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

add_subdirectory(Ability)

add_subdirectory (Golem)

add_subdirectory(Necromancer)

add_subdirectory(Creature)

add_subdirectory(Cell)

add_subdirectory(Characteristic)

add_subdirectory(DamageCaused)

add_subdirectory(Alive)

add_subdirectory(Unheader)

add_subdirectory(Curse)

add_subdirectory(MyVector)

add_subdirectory(Morphism)

add_subdirectory(Dialogue)

add_subdirectory(Tests)

add_subdirectory(Obstacle)

add_subdirectory(Door)

add_subdirectory(OpenDoor)

add_subdirectory(Lava)

add_subdirectory(Creator_Creature)

add_subdirectory(TableWithAbility)

add_subdirectory(Base)

add_subdirectory(Search)

add_subdirectory(Director)

add_subdirectory(DirectorForFile)

add_subdirectory(Orc)

add_subdirectory(Goblin)

add_subdirectory(Essence)

add_subdirectory(PushEssence)

add_subdirectory(Desiccation)

add_subdirectory(Utilits)

add_subdirectory(UnResponsive)

add_subdirectory(Necromancy)

add_subdirectory(TakeDamage)

add_subdirectory(Matrix)

add_subdirectory(MakeCharacteristicForGolem)

add_subdirectory(Player)

add_subdirectory(Room)

add_subdirectory(VectorForImages)

add_subdirectory(Game)

add_subdirectory(Controler)

add_subdirectory(ControlerPlayer)

add_subdirectory(ControlerAI)

add_subdirectory(ConcurrentQueue)

add_subdirectory(Plagin)

add_subdirectory(Boom)