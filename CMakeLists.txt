cmake_minimum_required(VERSION 3.0)
  
# set the project name
project(Test)

#set C++ standard to C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#set the output folder where your program will be created
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

# The following folder will be included
include_directories("${PROJECT_SOURCE_DIR}/Input")
include_directories("${PROJECT_SOURCE_DIR}/Plot")
include_directories("${PROJECT_SOURCE_DIR}/realTimePlot")
add_subdirectory(Input)
add_subdirectory(realTimePlot)
add_subdirectory(Buffer)
# add the executable
add_executable(tester test.cpp)
# link with Input directory
target_link_libraries(tester Input realTimePlot pthread)