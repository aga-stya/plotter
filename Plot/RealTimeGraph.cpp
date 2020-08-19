#include <iostream>
#include <chrono>
#include <thread>
#include "RealTimeGraph.hpp"

realTimeGraph::realTimeGraph(std::string nameOfTheWindow, std::shared_ptr<Buffer> ptr)
              :ptrBuffer(ptr){ 
    ptrGrid = std::make_unique<plot::Grid>();
    ptrAxis = std::make_unique<plot::Axis>(); 
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

    window.reset(new sf::RenderWindow (sf::VideoMode(windowWidth, windowHeight), "My window"));
    ptrAxis->setup("font.ttf");
    ptrGrid->setup();
    ptrCurve->setup();
}

void realTimeGraph::prepareBoundary(void) {
    std::unique_ptr<plot::Boundary> plotBoundary  = std::make_unique<plot::Boundary>(sf::Vector2f(plotAreaPositionX, plotAreaPositionY), 
                                                                                     sf::Vector2f(plotAreaWidth, plotAreaHeight));
    ptrBoundaries.push_back(std::move(plotBoundary));
    std::unique_ptr<plot::Boundary> graphBoundary = std::make_unique<plot::Boundary>(sf::Vector2f(gridAreaPositionX, gridAreaPositionY), 
                                                                                     sf::Vector2f(gridAreaWidth, gridAreaHeight));
    ptrBoundaries.push_back(std::move(graphBoundary));
    std::unique_ptr<plot::Boundary> menuBoundary  = std::make_unique<plot::Boundary>(sf::Vector2f(menuAreaPositionX, menuAreaPositionY), 
                                                                                     sf::Vector2f(menuAreaWidth, menuAreaHeight));
    ptrBoundaries.push_back(std::move(menuBoundary));
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
    window->draw(*ptrAxisValues);
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
    int i,j;
    static int count = 0;
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
            std::cout << "total values written:" << ++count << "\n";
            //addNewPoint(val);
            ptrCurve->addNewPoint(val);
        }
        if (count < 500)
            ptrAxisValues = std::make_unique<plot::AxisValues>(0, 500);
        else 
            ptrAxisValues = std::make_unique<plot::AxisValues>(count - 500, count);

        drawGraph();
        // end the current frame
        displayWindow();
    }
}

