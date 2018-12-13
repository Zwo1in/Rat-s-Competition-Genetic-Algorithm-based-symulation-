cmake_minimum_required(VERSION 3.0.2)

set(LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BIN_DIR})

include_directories("${CMAKE_SOURCE_DIR}")

add_library(lrats STATIC dna.cpp geneticAlgorithm.cpp drawable.cpp labRat.cpp quicksort.cpp)
target_link_libraries(lrats collcheck ${SFML_LIBRARIES})