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
    std::shared_ptr<sf::RenderWindow> window;
    // window's events 
    std::shared_ptr<sf::Event> event;
    // pointer to Buffer containing input values
    std::shared_ptr<Buffer> ptrBuffer;
    // pointer to Axis object
    std::unique_ptr<plot::Axis> ptrAxis;
    // pointer to Grid object
    std::unique_ptr<plot::Grid> ptrGrid;
    // pointer to Curve object
    std::unique_ptr<plot::Curve> ptrCurve;
    // pointer to xAxisValues object
    std::unique_ptr<plot::AxisValues> ptrXAxisValues;
    // pointer to yAxisValues object
    std::unique_ptr<plot::AxisValues> ptrYAxisValues;
    // pointer to Boundary object
    std::vector<std::unique_ptr<plot::Boundary>> ptrBoundaries;
    // window Name
    std::string windowName;
    // xAxis Name
    std::string xAxisName;
    // yAxis Name
    std::string yAxisName;

private:
    // prepare the window for the plot
    void initializeWindow(void);
    // prepare boundary
    void prepareBoundary(void);

public:
    //Initialize the window within which the graph is to be created
    realTimeGraph(std::shared_ptr<Buffer>, std::string, std::string, std::string);
    // Destructor
    ~realTimeGraph();
    // rename the window
    void changeWindowName(std::string_view newName); 
    //Clear the window with a particular color
    void clearWindow(sf::Color color);
    // check if window is open
    bool isWindowOpen() const;
    // check if somebody wants to close a window
    void checkCloseWindow() const;
    // draw graph 
    void drawGraph() const;
    // display window
    void displayWindow() const;
    // start the loop for the graph
    void startRealTimeGraph();
};


#endif //REAL_TIME_GRAPH_H