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

void Axis::nameValuesOnXAxis(int xAxisStart, int xAxisEnd) {
    int kPart = 5;
    int difference = xAxisEnd - xAxisStart;
    double iOffset = graphSize.x / kPart;
    for (auto i = 0; i < kPart; i++) {
        sf::Text temp;
        temp.setFont(font);
        int positionX = offset.x + (i * iOffset);
        int positionY = 550 + 5;
        std::cout << "names position:" << positionX << "," << positionY << "\n";
        temp.setString(std::to_string(positionX - 100));
        temp.setCharacterSize(16);
        temp.setFont(font);
        temp.setFillColor(nameColor);
        temp.setPosition(positionX, positionY);
        xAxisNames.push_back(temp);
    }
    sf::Text temp;
    temp.setFont(font);
    int positionX = 600;
    int positionY = 550 + 5;
    std::cout << "names position:" << positionX << "," << positionY << "\n";
    temp.setString(std::to_string(positionX - 100));
    temp.setCharacterSize(16);
    temp.setFont(font);
    temp.setFillColor(nameColor);
    temp.setPosition(positionX, positionY);
    xAxisNames.push_back(temp);
}

void Axis::setup(std::string fileName) {
    //if (!font.loadFromFile("../Plot/OpenSans-Regular.ttf")) {
    if (!font.loadFromFile("/home/pavan/Documents/plotter_olderversion/plotter/Plot/OpenSans-Regular.ttf")) {
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
    xAxis.setPosition(xPosition, graphSize.x + 70);

    yAxis.setFont(font);
    yAxis.setString(yAxisName);
    yAxis.setCharacterSize(16);
    yAxis.setFillColor(nameColor);
    int yPosition = offset.y + (graphSize.y / 2) - (yAxisName.size() / 2);
    yAxis.setPosition(offset.y + 20, yPosition);
    yAxis.setRotation(90);
}

void Axis::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(xAxis, states);
    target.draw(yAxis, states);
    for (auto xAxisName:xAxisNames)
        target.draw(xAxisName, states);
}

}
