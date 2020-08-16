#ifndef SFML_PLOT_GRID_H
#define SFML_PLOT_GRID_H

#include <vector>
#include <SFML/Graphics.hpp>

namespace plot {

class Grid
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
    Grid(sf::Vector2f gridPosition, sf::Vector2f gridSize);
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

    /// keep the size
    sf::Vector2f gridSize;
    /// position
    sf::Vector2f gridPosition;
};
}

#endif // SFML_PLOT_GRID_H
