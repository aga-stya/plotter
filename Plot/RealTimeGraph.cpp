#include <iostream>
#include <chrono>
#include <thread>
#include "RealTimeGraph.hpp"

realTimeGraph::realTimeGraph(int width, int height, std::string nameOfTheWindow, std::shared_ptr<Buffer> ptr)
            : windowHeight(height ),
              windowWidth (width),
              ptrBuffer(ptr) {
    // create the window
    std::cout << "Constructor called" << std::endl;
    window.reset(new sf::RenderWindow (sf::VideoMode(width, height ), "My window"));
    event.reset(new sf::Event);
}

realTimeGraph::~realTimeGraph()
{
}

void realTimeGraph::clearWindow (sf::Color color) {
    window->clear(color);
}

void realTimeGraph::addNewPoint (double y) {
    static int current_x = 0;
    static bool startRemovingOldOnes = false;

    if (startRemovingOldOnes) {
        reassignVertices();
        //over write the last element instead of adding a new element
        curve.back() = sf::Vertex(sf::Vector2f(current_x, y));
    } else {
        curve.push_back(sf::Vertex(sf::Vector2f(current_x, y)));
    }

    if (++current_x >= windowWidth) {
        startRemovingOldOnes = true;
    }
}

void realTimeGraph::reassignVertices() {
    for (auto it = curve.begin(); it != (curve.end() - 1); it++) {
        it->position.y = (it + 1)->position.y;
    } 
}

void realTimeGraph::drawGraph() {
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
        //std::cout << "is window open :" << isWindowOpen() << std::endl;
        // check all the window's events that were triggered since the last iteration of the loop
        checkCloseWindow();

        // clear the window with black color
        clearWindow(sf::Color::Black);

        //add new point if there is a new value in the file
        //if (checkForValue())
        double val = 0.0;
        if (ptrBuffer->getValueFromBufferQueue(val)) {
            std::cout << "total values written:" << ++count << "\n";
            addNewPoint(val);
        }

        drawGraph();
        // end the current frame
        displayWindow();

        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

