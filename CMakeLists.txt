cmake_minimum_required(VERSION 3.17)
#cmake_minimum_required(VERSION 3.24)

project(Hex VERSION 1.0)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "-Wall")

# DEFINE desired modules

#set(Modules "Board" "Game" "Config" "Player" "Square" "Turn" "View" "PlayerController" "System" "Bot")
set(Modules "Square" "Board" "Player" "Turn")

set (INCLUDE_DIRS "src")
set (SOURCES "")

# Append all modules to INCLUDE_DIRS and SOURCES
foreach (Module ${Modules})
    list(APPEND INCLUDE_DIRS "src/${Module}")
    list(APPEND SOURCES "src/${Module}/${Module}.cpp")
endforeach()

# IF using Bot
#list(APPEND SOURCES "src/Bot/Engines.cpp")


set (Bot_engines list(FIND Modules "Bot"))

IF (${Bot_engines} GREATER -1)
    list(APPEND SOURCES "src/Bot/Engines.cpp")

list(APPEND SOURCES "src/test.cpp")
#list(APPEND SOURCES "src/main.cpp")

include_directories(${INCLUDE_DIRS})
add_executable(exec ${SOURCES})




# MANUAL INCLUDES
#include_directories("src" "src/Board" "src/Player" "src/Turn" "src/Square")

#add_executable(exec "src/Board/Board.cpp" "src/Player/Player.cpp" "src/Turn/Turn.cpp" "src/Square/Square.cpp" "src/test.cpp")