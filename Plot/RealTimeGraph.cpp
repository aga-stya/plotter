#include <iostream>
#include <chrono>
#include <thread>
#include <algorithm>
#include "RealTimeGraph.hpp"

realTimeGraph::realTimeGraph(std::shared_ptr<Buffer> ptr, std::string windowName, 
                             std::string xAxisName, std::string yAxisName)
                            :ptrBuffer(ptr), windowName(windowName), 
                             xAxisName(xAxisName), yAxisName(yAxisName) { 
    ptrGrid = std::make_unique<plot::Grid>();
    ptrAxis = std::make_unique<plot::Axis>(xAxisName, yAxisName); 
    ptrCurve = std::make_unique<plot::Curve>();
    // create the window
    initializeWindow();
    event.reset(new sf::Event);
}

realTimeGraph::~realTimeGraph() {
}

void realTimeGraph::initializeWindow(void) {
    prepareBoundary();
    for (auto &boundary:ptrBoundaries)
        boundary->setup();
    window.reset(new sf::RenderWindow (sf::VideoMode(plotAreaWidth, plotAreaHeight), windowName));
}

void realTimeGraph::prepareBoundary(void) {
    std::unique_ptr<plot::Boundary> plotBoundary  = std::make_unique<plot::Boundary>(sf::Vector2f(plotAreaPositionX, plotAreaPositionY), 
                                                                                     sf::Vector2f(plotAreaWidth, plotAreaHeight));
    ptrBoundaries.push_back(std::move(plotBoundary));
    std::unique_ptr<plot::Boundary> graphBoundary = std::make_unique<plot::Boundary>(sf::Vector2f(xAxisStart, yAxisStart), 
                                                                                     sf::Vector2f(graphWidth, graphHeight));
    ptrBoundaries.push_back(std::move(graphBoundary));
}

void realTimeGraph::changeWindowName(std::string newName) {
    window->setTitle(newName);
}

void realTimeGraph::clearWindow (sf::Color color) {
    window->clear(color);
}

void realTimeGraph::drawGraph() {
    for (auto &boundary:ptrBoundaries) {
        window->draw(*boundary);
    }
    window->draw(*ptrGrid);
    window->draw(*ptrAxis);
    window->draw(*ptrCurve);
    window->draw(*ptrXAxisValues);
    window->draw(*ptrYAxisValues);
}

bool realTimeGraph::isWindowOpen() {
    return window->isOpen();
}

bool realTimeGraph::isThereAnEvent() {
    return window->pollEvent(*event);
}

void realTimeGraph::checkCloseWindow() {
    // check all the window's events that were triggered since the last iteration of the loop
    while (window->pollEvent(*event)) {
        // "close requested" event: we close the window
        if (event->type == sf::Event::Closed) {
            std::cout << "Close the window" << std::endl;
            window->close();
        }
    }
}

void realTimeGraph::displayWindow() {
    // end the current frame
    window->display();
}

void realTimeGraph::startRealTimeGraph() {
    static int count = 0;
    double minOfAll = 0;
    double maxOfAll = 0;
    // run the program as long as the window is open
    while (isWindowOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        checkCloseWindow();

        // clear the window with black color
        clearWindow(sf::Color::White);

        //add new point if there is a new value in the file
        double val = 0.0;
        if (ptrBuffer->getValueFromBufferQueue(val)) {
            minOfAll = std::min(minOfAll, val);
            maxOfAll = std::min(maxOfAll, val);
            std::cout << "new value:" << val << ", total values written:" << ++count << "\n";
            ptrCurve->addNewPoint(val);
        }

        int totalPointsOnGraph = graphWidth / distanceBetweenX;
        if (count < totalPointsOnGraph)
            ptrXAxisValues = std::make_unique<plot::AxisValues>(0, totalPointsOnGraph, distanceBetweenX, plot::AxisValues::Axis::XAXIS);
        else 
            ptrXAxisValues = std::make_unique<plot::AxisValues>(count - totalPointsOnGraph, count, distanceBetweenX, plot::AxisValues::Axis::XAXIS);

        ptrYAxisValues = std::make_unique<plot::AxisValues>(ptrCurve->getMinInCurve(), ptrCurve->getMaxInCurve(), 1, plot::AxisValues::Axis::YAXIS); 
        drawGraph();
        // end the current frame
        displayWindow();
    }
}

