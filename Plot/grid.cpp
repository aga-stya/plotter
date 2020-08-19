#include "grid.h"
#include <iostream>

namespace plot {

Grid::Grid() {
}

void Grid::setup(void)
{
    gridColor = sf::Color(150, 150, 150);
    vertices_.clear();
    vertices_.setPrimitiveType(sf::Lines);

    float offset = graphHeight / numOfGrids;
    for(int i = 1; i < numOfGrids; i++) {
        std::cout << (gridPositionX) << "," << (i*offset + gridPositionY) << "\n";
        vertices_.append(sf::Vertex(sf::Vector2f(gridPositionX, i*offset + gridPositionY), gridColor));
        std::cout << (graphWidth + gridPositionX) << "," << (i*offset + gridPositionY) << "\n";
        vertices_.append(sf::Vertex(sf::Vector2f(graphWidth + gridPositionX, i*offset + gridPositionY), gridColor));
    }

    offset = graphWidth / numOfGrids;
    for(int i = 1; i < numOfGrids; i++) {
        vertices_.append(sf::Vertex(sf::Vector2f(i*offset + gridPositionX, gridPositionY), gridColor));
        vertices_.append(sf::Vertex(sf::Vector2f(i*offset + gridPositionX, graphHeight + gridPositionY), gridColor));
    }

    //std::cout << "vertices: \n";
    //for (auto i = 0; i < vertices_.getVertexCount(); i++)
    //    std::cout << vertices_[i].position.x << "," << vertices_[i].position.y << "\n";
}

void Grid::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(vertices_, states);
}

}
