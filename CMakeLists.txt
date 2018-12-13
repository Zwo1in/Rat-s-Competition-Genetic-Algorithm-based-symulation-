cmake_minimum_required(VERSION 3.0.2)
project(rats)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(SOURCE_DIR ${CMAKE_SOURCE_DIR}/src)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} /usr/share/SFML/cmake/Modules/)

find_package(SFML REQUIRED COMPONENTS graphics window system)

include_directories("${CMAKE_SOURCE_DIR}/inc")
include_directories("${CMAKE_SOURCE_DIR}/Colsion_detection_based_on_SAT")
include_directories("${CMAKE_SOURCE_DIR}/Labrat")
include_directories("${CMAKE_SOURCE_DIR}/Game_loop_handler_for_SFML")
include_directories("${CMAKE_BINARY_DIR}")

add_subdirectory(${CMAKE_SOURCE_DIR}/Colsion_detection_based_on_SAT)
add_subdirectory(${CMAKE_SOURCE_DIR}/Game_loop_handler_for_SFML)
add_subdirectory(${CMAKE_SOURCE_DIR}/Labrat)

add_library(core STATIC ${SOURCE_DIR}/core.cpp ${SOURCE_DIR}/population.cpp)
target_link_libraries(core collcheck lrats fpsclock)

add_executable(rats ${SOURCE_DIR}/main.cpp)
target_link_libraries(rats core ${SFML_LIBRARIES})