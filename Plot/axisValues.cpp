#include "axisValues.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cmath>

namespace plot {

AxisValues::AxisValues(int valueStart, int valueEnd):start(valueStart), end(valueEnd) {
    nameColor = sf::Color::Black;
    //if (!font.loadFromFile("../Plot/font.ttf")) {
    if (!font.loadFromFile("/home/ppa/Documents/plotter/plotter/Plot/OpenSans-Regular.ttf")) {
        std::cout << "font file not found \n";
        throw;
    } else {
        setup();
    }
}

void AxisValues::setup() {
    int offset = totalSpaceAvailable / numOfGrids;
    for (auto i = 0; i <= numOfGrids; i++) {
        sf::Text temp;
        temp.setFont(font);
        int axisVal = start + (i * offset);
        temp.setString(std::to_string(axisVal));
        temp.setCharacterSize(12);
        temp.setFillColor(nameColor);
        int xValue = xAxisStartPosition + (i * offset) - std::ceil(std::to_string(axisVal).size() / 2) - 5; 
        //std::cout << "axisvalue:" << axisVal << ", at position:" << xValue << ":" << 555 << "\n";
        temp.setPosition(xValue, 555);
        axisValues.push_back(temp);
    }
}

void AxisValues::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();
    for (auto axisValue:axisValues)
        target.draw(axisValue, states);
}

}
