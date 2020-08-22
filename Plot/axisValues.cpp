#include "axisValues.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <iomanip>

namespace plot {

AxisValues::AxisValues(int valueStart, int valueEnd, int distBtwPts, Axis axisType)
                                                    :startValue(valueStart), endValue(valueEnd),
                                                     distBetweenPoints(distBtwPts), axisName(axisType){
    setFont(fnt);
    setup();
    setColor(sf::Color::Black);
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
        gridValueText.setCharacterSize(12);
        gridValueText.setFillColor(axisNameColor);
        double gridValueTextPosition = 0;
        if (axisName == AxisValues::Axis::XAXIS) {
            gridValueTextPosition = (double)xAxisStart+ (i * gridWidth) - (double)std::ceil(std::to_string(gridVal).size() / 2) - 5; 
            gridValueText.setPosition(gridValueTextPosition, yAxisEnd + gridValuePositionY);
            //std::cout << "x axis values position:" << gridValueText.getPosition().x << "," << gridValueText.getPosition().y << "\n";
        } else {
            gridValueTextPosition = 550.0 - (i * gridWidth); 
            gridValueText.setPosition(xAxisStart - std::to_string(gridVal).size() * 3, gridValueTextPosition);
            //std::cout << "y axis values position:" << gridValueText.getPosition().x << "," << gridValueText.getPosition().y << "\n";
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
