#include "axisValues.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <iomanip>

namespace plot {

AxisValues::AxisValues(int valueStart, int valueEnd, 
                       int distBtwPts, Axis axisType)
                      :startValue(valueStart), 
                       endValue(valueEnd),
                       axisName(axisType) {
    setFont(fnt);
    setColor(sf::Color::Black);
    setCharacterSize(12); //default character size
    setup();
}

void AxisValues::setup() {
    double gridWidth = graphWidth/ numOfGrids; 
    for (auto i = 0; i <= numOfGrids; i++) {
        sf::Text gridValueText;
        gridValueText.setFont(font);
        //gridVal : the number that will be printed under each grid
        double actualGridWidth = (endValue - startValue)/ (double)numOfGrids;
        double gridVal = startValue + (i * actualGridWidth);//divide by distanceBetweenX to account for the distance between 2 points
        std::stringstream gridValStream;
        gridValStream << std::fixed << std::setprecision(2) << gridVal;
        //std::cout << "axis values:" << gridValStream.str() << "\n";
        gridValueText.setString(gridValStream.str());
        gridValueText.setCharacterSize(characterSize);
        gridValueText.setFillColor(axisNameColor);
        double gridValueTextPosition = 0;
        if (axisName == AxisValues::Axis::XAXIS) {
            gridValueTextPosition = (double)xAxisStart+ (i * gridWidth) - (double)std::ceil(std::to_string(gridVal).size() / 2) - 5; 
            gridValueText.setPosition(gridValueTextPosition, yAxisEnd + gridValuePositionY);
        } else {
            gridValueTextPosition = static_cast<double>(yAxisEnd) - (i * gridWidth) - (characterSize); 
            gridValueText.setPosition(xAxisStart - std::to_string(gridVal).size() * 3, gridValueTextPosition); //multiply by 3 is an adjustment made for proper positioning of the point
        }
        axisValues.push_back(gridValueText);
    }
}

void AxisValues::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();
    for (auto axisValue:axisValues)
        target.draw(axisValue, states);
}

}
