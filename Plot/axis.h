#ifndef SFML_PLOT_Axis_H
#define SFML_PLOT_Axis_H

#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>

#include "specification.hpp"

namespace plot {

class Axis : public sf::Drawable
           , public sf::Transformable {

public:
    /**
     * constructor
     */
    Axis(std::string_view, std::string_view);

    /**
     * Copy constructor not required
     */
    Axis(const Axis&) = delete;

    /**
     * Copy assignment not required
     */
    Axis& operator=(const Axis&) = delete;

    /**
     * Move constructor not required
     */
    Axis(Axis&&) = delete;

    /**
     * Move assignment operator not required
     */
    Axis& operator=(Axis&&) = delete;

    /**
     * Default Destructor 
     */
    ~Axis() = default;

    /**
     * set the color of the axis
     */
    void setColor (const sf::Color &color) noexcept{
        nameColor = color;
    }

    /**
     * set the name of the X Axis
     */
    void setXAxisName(std::string_view name) noexcept{
        xAxisName = std::string(name);
    }

    /**
     * set the name of the Y Axis
     */
    void setYAxisName(std::string_view name) noexcept{
        yAxisName = std::string(name);
    }

    /**
     * set the name of the X Axis
     */
    void setCharacterSize(unsigned int characterSize) noexcept{
        this->characterSize = characterSize;
    }

    /**
     * set the name of the Y Axis
     */
    unsigned int getCharacterSize(void) noexcept{
        return characterSize;
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
    void setup() noexcept;

    /**
     * sfml method for drawing
     */
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    std::string xAxisName;
    std::string yAxisName;
    sf::Text xAxis;
    sf::Text yAxis;
    sf::Font font;
    sf::Color nameColor; //color of the Axis
    unsigned int characterSize;
};
}

#endif // SFML_PLOT_Axis_H
