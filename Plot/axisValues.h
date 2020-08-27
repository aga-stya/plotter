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
    enum class Axis {
        XAXIS,
        YAXIS,
    };
    /**
     * constructor
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
    sf::Color getColor(void) const{
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

    /**
     * set the character size of the value displayed 
     */
    void setCharacterSize(unsigned int characterSize) {
        this->characterSize = characterSize;
    }

    /**
     * get the character size of axisValue
     */
    unsigned int getCharacterSize(void) const{
        return characterSize;
    }

private:
    /**
     * sfml method for drawing
     */
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    /**
     * setup the values 
     */
    void setup();

    // array of values that will be displayed for the axis
    std::vector<sf::Text> axisValues;
    // start value of the values displayed for the axis
    double startValue;
    // end value of the values displayed for the axis
    double endValue;
    sf::Font font;
    sf::Color axisNameColor; 
    unsigned int characterSize;
    Axis axisName; 
};
}

#endif // AXIS_VALUES_H 
