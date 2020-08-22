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
#include "curve.h"
#include "axisValues.h"

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
    // pointer to xAxisValues object
    std::unique_ptr<plot::AxisValues> ptrXAxisValues;
    // pointer to yAxisValues object
    std::unique_ptr<plot::AxisValues> ptrYAxisValues;
    // pointer to Boundary object
    std::vector<std::unique_ptr<plot::Boundary>> ptrBoundaries;

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