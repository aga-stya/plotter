#ifndef SFML_PLOT_BOUNDARY_H
#define SFML_PLOT_BOUNDARY_H 
#include "specification.hpp"
#include <vector>
#include <SFML/Graphics.hpp>

namespace plot {

class Boundary 
        : public sf::Drawable
        , public sf::Transformable {
private:

public:
    /**
     * constructor
     */
    Boundary(sf::Vector2f boundaryPosition, sf::Vector2f boundarySize);

    /**
     * setup
     */
    void setup();

    /**
     * set Color
     */
    void setColor(const sf::Color &color) {
        boundaryColor = color;
    }

    /**
     * get Color
     */
    sf::Color getColor() const {
        return boundaryColor;
    }
private:
    /**
     * sfml method for drawing
     */
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    // grid borders
    sf::RectangleShape border;
    // grid color
    sf::Color boundaryColor;
    // boundary position
    sf::Vector2f position;
    // boundary size
    sf::Vector2f size;

};
}

#endif // SFML_PLOT_GRID_H
