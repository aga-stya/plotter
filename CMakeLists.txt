cmake_minimum_required(VERSION 3.10)
  
# set the project name
project(Test)

#set the output folder where your program will be created
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

# The following folder will be included
include_directories("${PROJECT_SOURCE_DIR}/Input")
include_directories("${PROJECT_SOURCE_DIR}/Plot")
add_subdirectory(Input)
add_subdirectory(Plot)
add_subdirectory(Buffer)
# add the executable
add_executable(tester test.cpp)
# link with Input directory
target_link_libraries(tester Input Plot pthread)