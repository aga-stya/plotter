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
    ////////////////////////////////////////////////////////////
    /// \brief constructor
    ////////////////////////////////////////////////////////////
    Grid();
    ////////////////////////////////////////////////////////////
    /// \brief setup once the grid shape
    ///
    /// \param size grid size
    ////////////////////////////////////////////////////////////
    void setup(void);
private:
    ////////////////////////////////////////////////////////////
    /// \brief sfml method for drawing
    ////////////////////////////////////////////////////////////
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    /// grid lines
    sf::VertexArray vertices_;

    /// grid color
    sf::Color gridColor;
};
}

#endif // SFML_PLOT_GRID_H
