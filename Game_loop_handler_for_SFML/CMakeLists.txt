cmake_minimum_required(VERSION 3.0.2)

set(LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

include_directories("${CMAKE_SOURCE_DIR}")

add_library(fpsclock STATIC fpsClock.cpp)
target_link_libraries(fpsclock ${SFML_LIBRARIES})