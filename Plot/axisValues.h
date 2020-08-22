#ifndef AXIS_VALUES_H
#define AXIS_VALUES_H 

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

#include "specification.hpp"

namespace plot {

class AxisValues 
        : public sf::Drawable
        , public sf::Transformable {
private:

public:
    enum Axis {
        XAXIS,
        YAXIS,
    };
    /**
     * \brief constructor
     */
    AxisValues(int, int, int, Axis);

    /**
     * set the color for axisValue
     */
    void setColor(const sf::Color &color) {
        axisNameColor = color;
    }

    /**
     * get the color of axisValue
     */
    sf::Color getColor(void) {
        return axisNameColor;
    }

    /**
     * set the color for axisValue
     */
    void setFont(std::string_view fontFile) {
        if (!font.loadFromFile(std::string(fontFile))) {
            std::cerr << "font file for axisValues not found\n";
            throw;
        }
    }

private:
    /**
     * sfml method for drawing
     */
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    /**
     * \brief setup once the Axis shape
     */
    void setup();

    /// Axes 
    std::vector<sf::Text> axisValues;
    double startValue;
    double endValue;
    int distBetweenPoints;
    sf::Font font;
    sf::Color axisNameColor; // Axis color
    Axis axisName; // axis under consideration
};
}

#endif // AXIS_VALUES_H 
