#include "axis.h"
#include <iostream>
#include <sstream>
#include <iomanip>

namespace plot {

Axis::Axis() {
    xAxisName = "X AXIS";
    yAxisName = "Y AXIS";
}

void Axis::setup(std::string fileName) {
    if (!font.loadFromFile("font.ttf")) {
        std::cout << "font file not found \n";
        throw;
    } else {
        std::cout << "font file found\n";
    }
    xAxis.setFont(font);
    xAxis.setString(xAxisName);
    xAxis.setCharacterSize(16);
    xAxis.setFillColor(sf::Color::Black);
    int xPosition = 100 + (500 / 2) - (xAxisName.size() / 2);
    std::cout << "xPosition:" << xPosition << "\n";
    xAxis.setPosition(xPosition, 560);
    sf::Vector2f pos = xAxis.getPosition();
    std::cout << pos.x << "," << pos.y << "\n";
    std::cout << "after all settings\n";

    yAxis.setFont(font);
    yAxis.setString(yAxisName);
    yAxis.setCharacterSize(16);
    yAxis.setFillColor(sf::Color::Black);
    int yPosition = 50 + (500 / 2) - (yAxisName.size() / 2);
    std::cout << "yPosition:" << yPosition << "\n";
    yAxis.setPosition(90, yPosition);
    yAxis.setRotation(90);

}

void Axis::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(xAxis, states);
    target.draw(yAxis, states);
}

}
