project(realTimePlot)

#set the output folder where your program will be created
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

# run moc automatically
set(CMAKE_AUTOMOC ON)
# if you're using Widgets and editing .ui forms in Designer
set(CMAKE_AUTOUIC ON)
# The following folder will be included
include_directories("${PROJECT_SOURCE_DIR}")

message("Looking for Qt...")
# Qt modules (https://doc.qt.io/qt-5/qtmodules.html) you're using in your application
find_package(Qt5 REQUIRED Widgets)
if (${Qt5_FOUND})
    message("Found Qt " ${Qt5_VERSION})
else()
    message("Couldn't find Qt")
endif()

# for linking libraries
find_library(CHARTDIR NAMES chartdir PATHS lib NO_DEFAULT_PATH)
# add the executable
add_library(realTimePlot qchartviewer.cpp realTimePlot.cpp)
# include the relavant directories
target_include_directories(realTimePlot PUBLIC include)
# link sfml libraries with Plot
target_link_libraries (realTimePlot 
                        Qt5::Widgets
                        ${CHARTDIR}
                        )