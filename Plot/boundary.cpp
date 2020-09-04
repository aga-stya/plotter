#include "boundary.h"
#include <iostream>

namespace plot {

Boundary::Boundary(sf::Vector2f boundaryPosition, sf::Vector2f boundarySize):
                                                            position(boundaryPosition), 
                                                            size(boundarySize) {
    sf::Color color = sf::Color(150, 150, 150);
    setColor(color);

}

void Boundary::setup(void) noexcept{
    border.setSize(sf::Vector2f(size.x - kBorderSize*2, size.y - kBorderSize*2));
    border.setFillColor(sf::Color(220, 220, 200));
    border.setOutlineColor(sf::Color(200, 0, 0));
    border.setOutlineThickness(kBorderSize);
    border.setPosition(sf::Vector2f(position.x + kBorderSize, position.y + kBorderSize)); 
}

void Boundary::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(border, states);
}

}
