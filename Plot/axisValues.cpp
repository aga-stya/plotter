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
        std::stringstream gridValStream;
        // when display value is above 1000.0 print it is scientific mode
        if (gridVal < 1000.0) {
            gridValStream << std::fixed      << std::setprecision(2) << gridVal;
        } else {
            gridValStream << std::scientific << std::setprecision(2) << gridVal;
        }
        double gridValueTextPositionX = 0;
        double gridValueTextPositionY = 0;
        if (axisName == AxisValues::Axis::XAXIS) {
            gridValueTextPositionX = (double)xAxisStart+ (i * gridWidth) - (double)std::ceil(std::to_string(gridVal).size() / 2) - 5; 
            gridValueTextPositionY = yAxisEnd + gridValuePositionY;
        } else {  //if YAXIS
            if (currentCurveSize == 0 && (i == 0 || i == numOfGrids)) {
                gridValStream << 0; //overwrite the value to 0 if no points in the curve
                gridValueTextPositionX = xAxisStart - 10;
            } else if (currentCurveSize > 0) {
                gridValueTextPositionX = xAxisStart - (gridValStream.str().size()) - 40;
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
