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
    Grid();
    ////////////////////////////////////////////////////////////
    /// \brief setup once the grid shape
    ///
    /// \param size grid size
    ////////////////////////////////////////////////////////////
    void setup(const sf::Vector2f& size);
private:
    ////////////////////////////////////////////////////////////
    /// \brief sfml method for drawing
    ////////////////////////////////////////////////////////////
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    /// grid lines
    sf::VertexArray vertices_;

    /// grid borders
    sf::RectangleShape plotBorder;
    sf::RectangleShape menuBorder;
    sf::RectangleShape graphBorder;

    /// grid color
    sf::Color color_;

    /// keep the size
    sf::Vector2f size_;
};
}

#endif // SFML_PLOT_GRID_H
