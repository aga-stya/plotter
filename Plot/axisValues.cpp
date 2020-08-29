#include "axisValues.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <iomanip>

namespace plot {

AxisValues::AxisValues(int valueStart, int valueEnd, 
                       int distBtwPts, Axis axisType, std::size_t curveSize)
                      :startValue(valueStart), 
                       endValue(valueEnd),
                       axisName(axisType),
                       currentCurveSize(curveSize) {
    setFont(fnt);
    setColor(sf::Color::Black);
    setCharacterSize(12); //default character size
    setup();
}

sf::Text AxisValues::prepareTextToPrint(std::string_view val, 
                                        const double positionX, 
                                        const double positionY) const {
    sf::Text gridValueText;
    gridValueText.setFont(font);
    gridValueText.setString(std::string(val));
    gridValueText.setCharacterSize(characterSize);
    gridValueText.setFillColor(axisNameColor);
    gridValueText.setPosition(positionX, positionY);
    return gridValueText;
}

void AxisValues::setup() {
    double gridWidth = graphWidth/ numOfGrids; 
    for (auto i = 0; i <= numOfGrids; i++) {
        double actualGridWidth = (endValue - startValue)/ (double)numOfGrids;
        //gridVal : the number that will be printed under each grid
        double gridVal = startValue + (i * actualGridWidth);//divide by distanceBetweenPoints to account for the distance between 2 points
        double gridValueTextPositionX = 0;
        double gridValueTextPositionY = 0;
        std::stringstream gridValStream;
        if (axisName == AxisValues::Axis::XAXIS) {
            gridValStream << std::fixed << std::setprecision(2) << gridVal;
            gridValueTextPositionX = (double)xAxisStart+ (i * gridWidth) - (double)std::ceil(std::to_string(gridVal).size() / 2) - 5; 
            gridValueTextPositionY = yAxisEnd + gridValuePositionY;
            //gridValueText.setPosition(gridValueTextPosition_x, yAxisEnd + gridValuePositionY);
        } else {
            if (currentCurveSize == 0 && (i == 0 || i == numOfGrids)) {
                gridValStream << 0;
                //gridValueTextPositionX -= 5; //buffer between the line and numbers when there is a single digit 
                gridValueTextPositionX = xAxisStart - 10;
            } else if (currentCurveSize > 0) {
                gridValueTextPositionX = xAxisStart - (gridValStream.str().size()) - 40;
                gridValStream << std::scientific << std::setprecision(2) << gridVal;
            }
            if (!gridValStream.str().empty()) {
                gridValueTextPositionY = static_cast<double>(yAxisEnd) - (i * gridWidth) - 10; // 10 is buffer between the numbers to display and the axis
            }
        }
        if (!gridValStream.str().empty()) {
            axisValues.push_back(prepareTextToPrint(gridValStream.str(), gridValueTextPositionX, gridValueTextPositionY));
        }
    }
}


void AxisValues::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();
    for (auto axisValue:axisValues)
        target.draw(axisValue, states);
}

}
