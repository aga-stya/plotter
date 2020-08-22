#include "curve.h"
#include <iostream>
#include <limits>

namespace plot {

Curve::Curve() {
    color = sf::Color(150, 150, 150);
    maxInCurve = std::numeric_limits<int>::min();
    minInCurve = std::numeric_limits<int>::max();
    setup();
}

void Curve::setup(void) {
}

void Curve::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();
    //target.draw(&curve[0], curve.size(), sf::PrimitiveType::LineStrip);
    double newValue = 0.0;
    // remap the vertices based on minInCurve and maxInCurve
    std::vector<sf::Vertex> drawCurve;
    for (auto vertex:curve) {
        if (maxInCurve == minInCurve) {
            newValue = (vertex.position.y * 100.0) / (500.0 - 0.0);
        } else {
            newValue = ((vertex.position.y - minInCurve) * 100.0) / (maxInCurve - minInCurve);
        }
        newValue = (newValue / 100.0) * 500 ;
        //invert the value because for y axis the numbers actually is opposite way
        newValue = 550 - newValue;
        //std::cout << "oldvalue:" << vertex.position.y << ", maxInCurve:" << maxInCurve << ", minInCurve:" << minInCurve << ", newValue:" << newValue << "\n";
        sf::Vertex temp(sf::Vector2f(vertex.position.x, newValue), sf::Color::Blue);
        drawCurve.push_back(sf::Vertex(sf::Vector2f(vertex.position.x, newValue), sf::Color::Blue));
    }
    target.draw(&drawCurve[0], drawCurve.size(), sf::PrimitiveType::LineStrip);
}

// add a new vertex with y co-ordinate only
void Curve::addNewPoint (double y) {
    static int  current_x = 100;
    static bool startRemovingOldOnes = false;
    if (startRemovingOldOnes) {
        reassignVertices(minInCurve, maxInCurve);
        minInCurve = std::min(minInCurve, y);
        maxInCurve = std::max(maxInCurve, y);
        //over write the last element instead of adding a new element
        curve.back() = sf::Vertex(sf::Vector2f(current_x, y), sf::Color::Blue);
    } else {
        minInCurve = std::min(minInCurve, y);
        maxInCurve = std::max(maxInCurve, y);
        curve.push_back(sf::Vertex(sf::Vector2f(current_x, y), sf::Color::Blue));
        current_x += distanceBetweenX;
        if (current_x >= xAxisEnd) {
            startRemovingOldOnes = true;
        }
    }
    //std::cout << "min:" << minInCurve << ", max:" << maxInCurve << "\n";
    //std::cout << "curve size:" << curve.size() << "\n";
}

// move the vertices to the left to accommodate the new vertice
void Curve::reassignVertices(double &minInCurve, double &maxInCurve) {
    minInCurve = std::numeric_limits<int>::max();
    maxInCurve = std::numeric_limits<int>::min();
    for (auto it = curve.begin(); it != curve.end() - 1; it++) {
        double currentYValue = (it + 1)->position.y;
        minInCurve = std::min(minInCurve, currentYValue);
        maxInCurve = std::max(maxInCurve, currentYValue);
        it->position.y = (it + 1)->position.y;
    } 
}
}
