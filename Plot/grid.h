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
    void setColor(const sf::Color &color) {
        gridColor = color;
    }
private:
    
    /**
     * setup
     */
    void setup(void);

    /**
     * sfml method for drawing
     */
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    /// grid lines
    sf::VertexArray vertices;

    /// grid color
    sf::Color gridColor;
};
}

#endif // SFML_PLOT_GRID_H
