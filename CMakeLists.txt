cmake_minimum_required(VERSION 3.17)
#cmake_minimum_required(VERSION 3.24)

project(Hex VERSION 1.0)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "-Wall -g")

# DEFINE desired modules

set(Modules "Board" "Bot" "Config" "Game" "Player" "PlayerController" "Square" "System" "Turn")# "View")
#set(Modules "Square" "Board" "Player" "Turn")
#set(Modules "Board" "Bot" "Config" "Game" "Player" "PlayerController" "Square" "Turn")

set (INCLUDE_DIRS "src")
set (SOURCES "")


# Append all modules to INCLUDE_DIRS and SOURCES
foreach (Module ${Modules})
  list(APPEND INCLUDE_DIRS "src/${Module}")

  file(GLOB cpp_sources "src/${Module}/*.cpp")
  list(APPEND SOURCES ${cpp_sources})
endforeach()

#list(APPEND SOURCES "src/test.cpp")
list(APPEND SOURCES "src/main.cpp")
list(APPEND SOURCES "src/utils.cpp") #temporal

include_directories(${INCLUDE_DIRS})
add_executable(Hex ${SOURCES})


# inlude sfml libraries
target_link_libraries(Hex -lsfml-window -lsfml-audio -lsfml-system -lsfml-graphics)
