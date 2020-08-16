#include <iostream>
#include <chrono>
#include <thread>
#include "RealTimeGraph.hpp"

realTimeGraph::realTimeGraph(std::string nameOfTheWindow, std::shared_ptr<Buffer> ptr)
              :ptrBuffer(ptr){ 
    ptrGrid = std::make_unique<plot::Grid>(sf::Vector2f(gridAreaPositionX, gridAreaPositionY), 
                                sf::Vector2f(gridAreaWidth, gridAreaHeight));
    ptrAxis = std::make_unique<plot::Axis>(sf::Vector2f(gridAreaWidth, gridAreaHeight),
                                         sf::Vector2f(xAxisOffset, yAxisOffset));
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
}

void realTimeGraph::prepareBoundary(void) {
    std::unique_ptr<plot::Boundary> plotBoundary  = std::make_unique<plot::Boundary>(sf::Vector2f(0, 0), sf::Vector2f(700, 600));
    ptrBoundaries.push_back(std::move(plotBoundary));
    std::unique_ptr<plot::Boundary> graphBoundary = std::make_unique<plot::Boundary>(sf::Vector2f(100, 50), sf::Vector2f(500, 500));
    ptrBoundaries.push_back(std::move(graphBoundary));
    std::unique_ptr<plot::Boundary> menuBoundary  = std::make_unique<plot::Boundary>(sf::Vector2f(700, 0), sf::Vector2f(300, 600));
    ptrBoundaries.push_back(std::move(menuBoundary));
}

void realTimeGraph::changeWindowName(std::string newName) {
    window->setTitle(newName);
}

void realTimeGraph::clearWindow (sf::Color color) {
    window->clear(color);
}

void realTimeGraph::addNewPoint (double y) {
    static int  current_x = 100;
    static bool startRemovingOldOnes = false;

    y += 50 + (500 / 2);
    y -= 250;

    if (startRemovingOldOnes) {
        reassignVertices();
        //over write the last element instead of adding a new element
        curve.back() = sf::Vertex(sf::Vector2f(current_x, y), sf::Color::Blue);
    } else {
        curve.push_back(sf::Vertex(sf::Vector2f(current_x, y), sf::Color::Blue));
        current_x += 2;
        if (current_x >= graphWidth) {
            startRemovingOldOnes = true;
        }
    }
}

void realTimeGraph::reassignVertices() {
    for (auto it = curve.begin(); it != curve.end(); it++) {
        it->position.y = (it + 1)->position.y;
    } 
}

void realTimeGraph::drawGraph() {
    for (auto &boundary:ptrBoundaries) {
        window->draw(*boundary);
    }
    window->draw(*ptrGrid);
    window->draw(*ptrAxis);
    window->draw(&curve[0], curve.size(), sf::PrimitiveType::LineStrip);
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

bool realTimeGraph::hasWindowWidthExceeded(int val) {
    return (val > windowWidth);
}

bool realTimeGraph::hasWindowHeightExceeded(int val) {
    return (val > windowHeight);
}

void realTimeGraph::startRealTimeGraph() {
    int i,j;
    int count = 0;
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
            addNewPoint(val);
        }

        drawGraph();
        // end the current frame
        displayWindow();
    }
}

