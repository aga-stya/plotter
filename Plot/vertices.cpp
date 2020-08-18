#include "vertices.h"
#include <iostream>

namespace plot {

Curve::Curve(int width):graphWidth(width) {
    color = sf::Color(150, 150, 150);
}

void Curve::setup(void) {
}

void Curve::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();
    //target.draw(border, states);
    target.draw(&curve[0], curve.size(), sf::PrimitiveType::LineStrip);
}

// add a new vertex with y co-ordinate only
void Curve::addNewPoint (double y) {
    static int  current_x = 100;
    static bool startRemovingOldOnes = false;

    y += 50 + (500 / 2);
    y -= 250;

    std::cout << "current value to be added to curve:" << current_x << "," << y << "\n";

    if (startRemovingOldOnes) {
        reassignVertices();
        //over write the last element instead of adding a new element
        curve.back() = sf::Vertex(sf::Vector2f(current_x, y), sf::Color::Blue);
    } else {
        curve.push_back(sf::Vertex(sf::Vector2f(current_x, y), sf::Color::Blue));
        current_x += 2;
        if (current_x >= graphWidth) {
            startRemovingOldOnes = true;
        }
    }
    std::cout << "curve size:" << curve.size() << "\n";
}

// move the vertices to the left to accommodate the new vertice
void Curve::reassignVertices() {
    for (auto it = curve.begin(); it != curve.end(); it++) {
        it->position.y = (it + 1)->position.y;
    } 
}
}
