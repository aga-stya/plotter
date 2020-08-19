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
    /// means that cut the grid in kPart
    static const int kPart = 5;
    static const int menuWidth = 300;
    static const int plotWidth = 700;

    //border space for grids
    static const int borderWidthX = 100;
    static const int borderWidthY = 50;
public:
    ////////////////////////////////////////////////////////////
    /// \brief constructor
    ////////////////////////////////////////////////////////////
    Boundary(sf::Vector2f boundaryPosition, sf::Vector2f boundarySize);
    ////////////////////////////////////////////////////////////
    /// \brief setup once the grid shape
    ///
    /// \param size grid size
    ////////////////////////////////////////////////////////////
    void setup();
private:
    ////////////////////////////////////////////////////////////
    /// \brief sfml method for drawing
    ////////////////////////////////////////////////////////////
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    /// grid borders
    sf::RectangleShape border;

    /// grid color
    sf::Color color;
    /// boundary size
    sf::Vector2f size;
    /// boundary position
    sf::Vector2f position;

};
}

#endif // SFML_PLOT_GRID_H
