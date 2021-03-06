#ifndef SFML_PLOT_BOUNDARY_H
#define SFML_PLOT_BOUNDARY_H 
#include "specification.hpp"
#include <vector>
#include <SFML/Graphics.hpp>

namespace plot {

class Boundary : public sf::Drawable
               , public sf::Transformable {

public:
    /**
     * constructor
     */
    Boundary(sf::Vector2f boundaryPosition, sf::Vector2f boundarySize);

    /**
     * Copy constructor not required
     */
    Boundary(const Boundary&) = delete;

    /**
     * Copy assignment not required
     */
    Boundary& operator=(const Boundary&) = delete;

    /**
     * Move constructor not required
     */
    Boundary(Boundary&&) = delete;

    /**
     * Move assignment operator not required
     */
    Boundary& operator=(Boundary&&) = delete;

    /**
     * Default Destructor 
     */
    ~Boundary() = default;

    /**
     * setup
     */
    void setup(void) noexcept;

    /**
     * set Color
     */
    void setColor(const sf::Color &color) noexcept{
        boundaryColor = color;
    }

    /**
     * get Color
     */
    sf::Color getColor() const noexcept{
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
