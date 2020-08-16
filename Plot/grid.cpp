#include "grid.h"
#include <iostream>

namespace plot {

Grid::Grid(sf::Vector2f position, sf::Vector2f size):gridPosition(position), 
                                                             gridSize(size) {
}

void Grid::setup(void)
{
    gridColor = sf::Color(150, 150, 150);
    vertices_.clear();
    vertices_.setPrimitiveType(sf::Lines);

    float offset = gridSize.y / kPart ;
    for(int i = 1; i < kPart; i++) {
        std::cout << (gridPosition.x) << "," << (i*offset + gridPosition.y) << "\n";
        vertices_.append(sf::Vertex(sf::Vector2f(gridPosition.x, i*offset + gridPosition.y), gridColor));
        std::cout << (gridSize.x + gridPosition.x) << "," << (i*offset + gridPosition.y) << "\n";
        vertices_.append(sf::Vertex(sf::Vector2f(gridSize.x + gridPosition.x, i*offset + gridPosition.y), gridColor));
    }

    offset = gridSize.x / kPart;
    for(int i = 1; i < kPart; i++) {
        vertices_.append(sf::Vertex(sf::Vector2f(i*offset + gridPosition.x, gridPosition.y), gridColor));
        vertices_.append(sf::Vertex(sf::Vector2f(i*offset + gridPosition.x, gridSize.y + gridPosition.y), gridColor));
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
