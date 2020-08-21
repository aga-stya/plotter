#include "axisValues.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <iomanip>

namespace plot {

AxisValues::AxisValues(int valueStart, int valueEnd):start(valueStart), end(valueEnd) {
    nameColor = sf::Color::Black;
    if (!font.loadFromFile(fnt)) {
        std::cout << "font file not found \n";
        throw;
    } else {
        setup();
    }
}

void AxisValues::setup() {
    int gridWidth = graphWidth/ numOfGrids; 
    std::cout << "start:" << start << "\n";
    for (auto i = 0; i <= numOfGrids; i++) {
        sf::Text gridValueText;
        gridValueText.setFont(font);
        //gridVal : the number that will be printed under each grid
        double gridVal = start + (i * (gridWidth / (double)distanceBetweenX));//divide by distanceBetweenX to account for the distance between 2 points
        std::stringstream gridValStream;
        gridValStream << std::fixed << std::setprecision(2) << gridVal;
        //std::cout << "axis values:" << gridValStream.str() << "\n";
        gridValueText.setString(gridValStream.str());
        gridValueText.setCharacterSize(12);
        gridValueText.setFillColor(nameColor);
        int gridValueTextPositionX = xAxisStartPosition + (i * gridWidth) - std::ceil(std::to_string(gridVal).size() / 2) - 5; 
        gridValueText.setPosition(gridValueTextPositionX, yAxisEnd + gridValuePositionY);
        axisValues.push_back(gridValueText);
    }
}

void AxisValues::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();
    for (auto axisValue:axisValues)
        target.draw(axisValue, states);
}

}
