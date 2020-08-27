#include "grid.h"
#include <iostream>

namespace plot {

Grid::Grid() {
    setup();
    sf::Color color = sf::Color(150, 150, 150);
    setColor(color);
}

void Grid::setup(void)
{
    vertices.clear();
    vertices.setPrimitiveType(sf::Lines);

    float offset = graphHeight / numOfGrids;
    for(int i = 1; i < numOfGrids; i++) {
        std::cout << (gridPositionX) << "," << (i*offset + gridPositionY) << "\n";
        vertices.append(sf::Vertex(sf::Vector2f(gridPositionX, i*offset + gridPositionY), gridColor));
        std::cout << (graphWidth + gridPositionX) << "," << (i*offset + gridPositionY) << "\n";
        vertices.append(sf::Vertex(sf::Vector2f(graphWidth + gridPositionX, i*offset + gridPositionY), gridColor));
    }

    offset = graphWidth / numOfGrids;
    for(int i = 1; i < numOfGrids; i++) {
        vertices.append(sf::Vertex(sf::Vector2f(i*offset + gridPositionX, gridPositionY), gridColor));
        vertices.append(sf::Vertex(sf::Vector2f(i*offset + gridPositionX, graphHeight + gridPositionY), gridColor));
    }
}

void Grid::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(vertices, states);
}

}
