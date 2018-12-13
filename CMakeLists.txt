cmake_minimum_required(VERSION 3.0.2)
project(rats)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(SOURCE_DIR ${CMAKE_SOURCE_DIR}/src)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} /usr/share/SFML/cmake/Modules/)

find_package(SFML REQUIRED COMPONENTS graphics window system)

include_directories("${CMAKE_SOURCE_DIR}/inc")
include_directories("${CMAKE_SOURCE_DIR}/collcheck")
include_directories("${CMAKE_SOURCE_DIR}/Labrat")
include_directories("${CMAKE_SOURCE_DIR}/fpsclock")

add_subdirectory(${CMAKE_SOURCE_DIR}/collcheck)
add_subdirectory(${CMAKE_SOURCE_DIR}/fpsclock)
add_subdirectory(${CMAKE_SOURCE_DIR}/Labrat)

message(STATUS ${SFML_LIBRARIES})

add_library(core STATIC ${SOURCE_DIR}/core.cpp ${SOURCE_DIR}/population.cpp)

add_executable(rats ${SOURCE_DIR}/main.cpp)

target_link_libraries(rats sat core lrats clock ${SFML_LIBRARIES})