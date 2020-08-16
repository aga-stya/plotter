#include <iostream>
#include <chrono>
#include <thread>
#include "RealTimeGraph.hpp"

realTimeGraph::realTimeGraph(std::string nameOfTheWindow, std::shared_ptr<Buffer> ptr)
              :ptrBuffer(ptr), 
               ptrAxis(std::make_shared<plot::Axis>()),
               ptrGrid(std::make_shared<plot::Grid>()) {
    // create the window
    std::cout << "Constructor called" << std::endl;
    initializeWindow();
    event.reset(new sf::Event);
}

realTimeGraph::~realTimeGraph()
{
}

void realTimeGraph::initializeWindow(void) {
    window.reset(new sf::RenderWindow (sf::VideoMode(windowWidth, windowHeight), "My window"));
    sf::Sprite  exitButtonImage;
    exitButtonImage.setPosition(25.0f, 100.0f);
    ptrAxis->setup("font.ttf");
    ptrGrid->setup(sf::Vector2f(1000, 600));
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

