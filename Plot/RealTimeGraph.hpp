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

class realTimeGraph {
private:
    // create the window
    std::shared_ptr<sf::RenderWindow> window;
    // exit button
    sf::Sprite exitButtonImage;
    // check all the window's events that were triggered since the last iteration of the loop
    std::shared_ptr<sf::Event> event;
    // vector that holds the points to be plotted
    std::vector<sf::Vertex> curve;
    // max width of the window
    int windowWidth = 1000;
    // max height of the window
    int windowHeight = 600;
    // max width allocated for the graph
    int graphWidth = windowWidth - 300 - 100;
    // pointer to Buffer containing input values
    std::shared_ptr<Buffer> ptrBuffer;
    // pointer to Axis object
    std::shared_ptr<plot::Axis> ptrAxis;
    // pointer to Grid object
    std::shared_ptr<plot::Grid> ptrGrid;

private:
    // prepare the window for the plot
    void initializeWindow(void);
    // add the axes for the graph
    void drawAxes(void);
    // add grids to the graph
    void drawGrid(void);

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

    // add a new vertex to the curve
    void addNewPoint (sf::Vertex vertex);
    // add a new vertex with x co-ordinate and y co-ordinate
    void addNewPoint (double x, double y);
    // add a new vertex with y co-ordinate only
    void addNewPoint (double y);
    // add a new vertex with x co-ordinate and y co-ordinate with offsets
    void addNewPoint (double x, double y, double x_offset, double y_offset);


    // increase the x co-ordinate
    void increaseX();
    // draw graph 
    void drawGraph();
    // display window
    void displayWindow();
    // check if the window width has exceeded the maximum width
    bool hasWindowWidthExceeded(int val);
    // check if the window height has exceeded the maximum height
    bool hasWindowHeightExceeded(int val);
    // start the loop for the graph
    void startRealTimeGraph();
    // check for the value from the file
    bool checkForValue();
    //get value from the source
    double getValueFromFile();
    // move the vertices to the left to accommodate the new vertice
    void reassignVertices();
};


#endif //REAL_TIME_GRAPH_H