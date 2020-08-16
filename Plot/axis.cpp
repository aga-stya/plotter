#include "axis.h"
#include <iostream>
#include <sstream>
#include <iomanip>

namespace plot {

Axis::Axis(sf::Vector2f size, sf::Vector2f off):graphSize(size) ,
                                            offset(off) {
    xAxisName = "X AXIS";
    yAxisName = "Y AXIS";
    nameColor = sf::Color::Black;
}

void Axis::setup(std::string fileName) {
    if (!font.loadFromFile("../Plot/OpenSans-Regular.ttf")) {
        std::cout << "font file not found \n";
        throw;
    } else {
        std::cout << "font file found\n";
    }
    xAxis.setFont(font);
    xAxis.setString(xAxisName);
    xAxis.setCharacterSize(16);
    xAxis.setFillColor(nameColor);
    int xPosition = offset.x + (graphSize.x / 2) - (xAxisName.size() / 2);
    xAxis.setPosition(xPosition, 560);
    sf::Vector2f pos = xAxis.getPosition();

    yAxis.setFont(font);
    yAxis.setString(yAxisName);
    yAxis.setCharacterSize(16);
    yAxis.setFillColor(nameColor);
    int yPosition = offset.y + (graphSize.y / 2) - (yAxisName.size() / 2);
    yAxis.setPosition(90, yPosition);
    yAxis.setRotation(90);
}

void Axis::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(xAxis, states);
    target.draw(yAxis, states);
}

}
