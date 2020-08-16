#include "grid.h"
#include <iostream>

namespace plot {

Grid::Grid() {
}

void Grid::setup(const sf::Vector2f& size)
{
    color_ = sf::Color(150, 150, 150);

    size_.x = size.x - menuWidth;
    size_.y = size.y;
    std::cout << size_.x << "," << size_.y << "\n";
    vertices_.clear();
    vertices_.setPrimitiveType(sf::Lines);

    sf::Vector2f graphPlotSize;
    graphPlotSize.x = size_.x - 2 * borderWidthX;
    graphPlotSize.y = size_.y - 2 * borderWidthY;

    sf::Vector2f graphPlotStartPosition;
    graphPlotStartPosition.x = borderWidthX;
    graphPlotStartPosition.y = borderWidthY;

    float offset = graphPlotSize.y / kPart ;
    for(int i=1;i<kPart;i++)
    {
        vertices_.append(sf::Vertex(sf::Vector2f(graphPlotStartPosition.x, i*offset + graphPlotStartPosition.y), color_));
        vertices_.append(sf::Vertex(sf::Vector2f(graphPlotSize.x + graphPlotStartPosition.x, i*offset + graphPlotStartPosition.y), color_));
    }

    offset = graphPlotSize.x / kPart;
    for(int i=1;i<kPart;i++)
    {
        vertices_.append(sf::Vertex(sf::Vector2f(i*offset + graphPlotStartPosition.x, graphPlotStartPosition.y), color_));
        vertices_.append(sf::Vertex(sf::Vector2f(i*offset + graphPlotStartPosition.x, graphPlotSize.y + graphPlotStartPosition.y), color_));
    }

    //std::cout << "vertices: \n";
    //for (auto i = 0; i < vertices_.getVertexCount(); i++)
    //    std::cout << vertices_[i].position.x << "," << vertices_[i].position.y << "\n";

    int kBorderSize = 2;
    plotBorder.setSize(sf::Vector2f(size_.x - kBorderSize*2, size_.y - kBorderSize*2));
    plotBorder.setFillColor(sf::Color(220, 220, 200));
    plotBorder.setOutlineColor(sf::Color(200, 0, 0));
    plotBorder.setOutlineThickness(kBorderSize);
    plotBorder.setPosition(sf::Vector2f(kBorderSize, kBorderSize)); 

    graphBorder.setSize(sf::Vector2f(graphPlotSize.x - kBorderSize*2, graphPlotSize.y - kBorderSize*2));
    graphBorder.setFillColor(sf::Color(220, 220, 200));
    //graphBorder.setOutlineColor(sf::Color(200, 0, 0));
    graphBorder.setOutlineColor(sf::Color::Magenta);
    graphBorder.setOutlineThickness(kBorderSize);
    graphBorder.setPosition(sf::Vector2f(graphPlotStartPosition.x + kBorderSize, graphPlotStartPosition.y + kBorderSize)); 

    sf::Vector2f menuSize = sf::Vector2f(menuWidth, size.y);
    menuBorder.setSize(sf::Vector2f(menuSize.x - kBorderSize*2, menuSize.y - kBorderSize*2));
    menuBorder.setFillColor(sf::Color(220, 220, 200));
    menuBorder.setOutlineColor(sf::Color(200, 0, 0));
    menuBorder.setOutlineThickness(kBorderSize);
    menuBorder.setPosition(sf::Vector2f(kBorderSize + plotWidth, kBorderSize)); 
}

void Grid::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(plotBorder, states);
    target.draw(menuBorder, states);
    target.draw(graphBorder, states);
    target.draw(vertices_, states);
}

}
