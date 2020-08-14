cmake_minimum_required(VERSION 3.10)
  
# set the project name
project(sample)

#set the output folder where your program will be created
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

# The following folder will be included
include_directories("${PROJECT_SOURCE_DIR}")

# detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
#find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)
#if(SFML_FOUND)
    #message(STATUS "SFML LIBRARIES FOUND")
#endif()

# add the executable
add_library(Plot RealTimeGraph.cpp RealTimeGraph.hpp)

# link sfml libraries with Plot
target_link_libraries (Plot sfml-graphics sfml-window sfml-system)
