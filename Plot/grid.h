#ifndef SFML_PLOT_GRID_H
#define SFML_PLOT_GRID_H

#include <vector>
#include <SFML/Graphics.hpp>

#include "specification.hpp"

namespace plot {

class Grid
        : public sf::Drawable
        , public sf::Transformable {
public:
    /**
     * constructor
     */
    Grid();

    /**
     * setColor
     */
    void setColor(const sf::Color &color) noexcept{
        gridColor = color;
    }
private:
    
    /**
     * setup
     */
    void setup(void) noexcept;

    /**
     * sfml method for drawing
     */
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    // grid line vertices
    sf::VertexArray vertices;

    // grid color
    sf::Color gridColor;
};
}

#endif // SFML_PLOT_GRID_H
