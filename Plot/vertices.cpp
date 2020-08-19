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
sf::Vector2f Curve::addNewPoint (double y) {
    static int  current_x = 100;
    static bool startRemovingOldOnes = false;

    y += 50 + (500 / 2);
    y -= 250;

    std::cout << "current value to be added to curve:" << current_x << "," << y << "\n";

    sf::Vector2f temp;
    if (startRemovingOldOnes) {
        reassignVertices();
        //over write the last element instead of adding a new element
        current_x += 2;
        curve.back() = sf::Vertex(sf::Vector2f(current_x, y), sf::Color::Blue);
        temp.x = curve[0].position.x;
        temp.y = curve[curve.size() - 1].position.x;
    } else {
        curve.push_back(sf::Vertex(sf::Vector2f(current_x, y), sf::Color::Blue));
        current_x += 2;
        if (current_x >= graphWidth) {
            startRemovingOldOnes = true;
        }
        temp.x = 100; 
        temp.y = 600;
    }
    std::cout << "curve size:" << curve.size() << "\n";
    return temp;
}

// move the vertices to the left to accommodate the new vertice
void Curve::reassignVertices() {
    for (auto it = curve.begin(); it != curve.end(); it++) {
        it->position.x = (it + 1)->position.x;
        it->position.y = (it + 1)->position.y;
    } 
}
}
