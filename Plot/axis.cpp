#include "axis.h"
#include <iostream>
#include <sstream>
#include <iomanip>

namespace plot {

Axis::Axis() {
    xAxisName = "X AXIS";
    yAxisName = "Y AXIS";
    nameColor = sf::Color::Black;
    //if (!font.loadFromFile("../Plot/OpenSans-Regular.ttf")) {
    if (!font.loadFromFile("/home/ppa/Documents/plotter/plotter/Plot/OpenSans-Regular.ttf")) {
        std::cout << "font file not found \n";
        throw;
    } else {
        std::cout << "font file found\n";
    }

}

void Axis::setup(std::string fileName) {
    
    xAxis.setFont(font);
    xAxis.setString(xAxisName);
    xAxis.setCharacterSize(16);
    xAxis.setFillColor(nameColor);
    int xPosition = xOffset + (graphWidth / 2) - (xAxisName.size() / 2);
    xAxis.setPosition(xPosition, xAxisNamePositionY);

    yAxis.setFont(font);
    yAxis.setString(yAxisName);
    yAxis.setCharacterSize(16);
    yAxis.setFillColor(nameColor);
    int yPosition = yOffset + (graphHeight / 2) - (yAxisName.size() / 2);
    yAxis.setPosition(yAxisNamePositionX, yPosition);
    yAxis.setRotation(90);
}

void Axis::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(xAxis, states);
    target.draw(yAxis, states);
}

}
