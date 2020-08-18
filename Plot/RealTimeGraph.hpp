#ifndef REAL_TIME_GRAPH_H
#define REAL_TIME_GRAPH_H

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <memory>
#include <fstream>

#include "../Buffer/Buffer.hpp"
#include "axis.h"
#include "grid.h"
#include "boundary.h"
#include "vertices.h"

class realTimeGraph {
private:
    // create the window
    std::shared_ptr<sf::RenderWindow> window;
    // check all the window's events that were triggered since the last iteration of the loop
    std::shared_ptr<sf::Event> event;
    // max width of the window
    int windowWidth = 1000;
    // max height of the window
    int windowHeight = 600;
    // pointer to Buffer containing input values
    std::shared_ptr<Buffer> ptrBuffer;
    // pointer to Axis object
    std::unique_ptr<plot::Axis> ptrAxis;
    // pointer to Grid object
    std::unique_ptr<plot::Grid> ptrGrid;
    // pointer to Grid object
    std::unique_ptr<plot::Curve> ptrCurve;
    // pointer to Boundary object
    std::vector<std::unique_ptr<plot::Boundary>> ptrBoundaries;

    //plot area specifications
    static constexpr int plotAreaWidth  = 700;
    static constexpr int plotAreaHeight = 600;
    static constexpr int plotAreaPositionX = 0;
    static constexpr int plotAreaPositionY = 0;
    //grid area specifications
    static constexpr int gridAreaWidth    = 500;
    static constexpr int gridAreaHeight   = 500;
    static constexpr int gridAreaPositionX = 100;
    static constexpr int gridAreaPositionY = 50;
    //menu area specifications
    static constexpr int menuAreaWidth    = 300;
    static constexpr int menuAreaHeight   = 600;
    static constexpr int menuAreaPositionX = 700;
    static constexpr int menuAreaPositionY = 0;
    //offset
    static constexpr int xAxisOffset = 100;
    static constexpr int yAxisOffset = 50;

private:
    // prepare the window for the plot
    void initializeWindow(void);
    // prepare boundary
    void prepareBoundary(void);

public:
    //Initialize the window within which the graph is to be created
    //realTimeGraph(int width, int height, std::string nameOfTheWindow, std::shared_ptr<Buffer> ptr);
    realTimeGraph(std::string nameOfTheWindow, std::shared_ptr<Buffer> ptr);
    // Destructor
    ~realTimeGraph();
    // rename the window
    void changeWindowName(std::string newName); 
    //Clear the window with a particular color
    void clearWindow (sf::Color color);
    // check if window is open
    bool isWindowOpen ();
    // check if somebody wants to close a window
    void checkCloseWindow();
    // check if there is an event
    bool isThereAnEvent();
    // draw graph 
    void drawGraph();
    // display window
    void displayWindow();
    // start the loop for the graph
    void startRealTimeGraph();
};


#endif //REAL_TIME_GRAPH_H