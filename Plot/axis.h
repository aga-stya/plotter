#ifndef SFML_PLOT_Axis_H
#define SFML_PLOT_Axis_H

#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>

#include "specification.hpp"

namespace plot {

class Axis
        : public sf::Drawable
        , public sf::Transformable {
private:

public:
    ////////////////////////////////////////////////////////////
    /// \brief constructor
    ////////////////////////////////////////////////////////////
    Axis();
    /**
     * set the color of the axis
     */
    void setColor (const sf::Color &color) {
        nameColor = color;
    }

    /**
     * set the name of the X Axis
     */
    void setXAxisName(std::string_view name) {
        xAxisName = std::string(name);
    }

    /**
     * set the name of the Y Axis
     */
    void setYAxisName(std::string_view name) {
        yAxisName = std::string(name);
    }


private:

    /**
     * set the font for axis 
     */
    void setFont(std::string_view fontFile) {
        if (!font.loadFromFile(std::string(fontFile))) {
            std::cerr << "font file for axisValues not found\n";
            throw;
        }
    }

    /**
     * setup the Axis
     */
    void setup();

    /**
     * sfml method for drawing
     */
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    /// Axes 
    std::string xAxisName;
    std::string yAxisName;
    sf::Text xAxis;
    sf::Text yAxis;
    sf::Font font;
    /// Axis color
    sf::Color nameColor;
};
}

#endif // SFML_PLOT_Axis_H
