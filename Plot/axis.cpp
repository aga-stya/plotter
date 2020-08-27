#include "axis.h"
#include <iostream>
#include <sstream>
#include <iomanip>

namespace plot {

Axis::Axis(std::string xAxisName, std::string yAxisName) 
                : xAxisName(xAxisName), yAxisName(yAxisName) {
    setColor(sf::Color::Black);
    setFont(openSans);
    setup();
}

void Axis::setup() {
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
