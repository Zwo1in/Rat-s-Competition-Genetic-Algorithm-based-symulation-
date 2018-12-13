cmake_minimum_required(VERSION 3.0.2)

include_directories("${CMAKE_SOURCE_DIR}")

set(LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
add_library(collcheck STATIC separatedAxisTheorem.cpp)
target_link_libraries(collcheck ${SFML_LIBRARIES})