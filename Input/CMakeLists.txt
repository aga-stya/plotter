cmake_minimum_required(VERSION 3.10)
  
# set the project name
project(Input)

#set the output folder where your program will be created
#set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
#set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
#set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

# The following folder will be included
include_directories("${PROJECT_SOURCE_DIR}")
add_subdirectory(FileInput)
add_subdirectory(ComInput)
set(inputSourceFiles Input.cpp Input.hpp 
                     InputContext.hpp)
# add the executable
add_library(Input ${inputSourceFiles})

# link with FileInput
target_link_libraries(Input FileInput ComInput)

