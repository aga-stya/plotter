#ifndef SFML_PLOT_VERTICES_H
#define SFML_PLOT_VERTICES_H

#include <vector>
#include <SFML/Graphics.hpp>

namespace plot {

class Curve 
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
    //Vertices(sf::Vector2f boundaryPosition, sf::Vector2f boundarySize);
    Curve(int width);
    ////////////////////////////////////////////////////////////
    /// \brief setup once the grid shape
    ///
    /// \param size grid size
    ////////////////////////////////////////////////////////////
    void setup();
    // add a new vertex with y co-ordinate only
    void addNewPoint (double y);
    // increase the x co-ordinate
    void increaseX();
    // start the loop for the graph
    void startRealTimeGraph();
    // move the vertices to the left to accommodate the new vertice
    void reassignVertices();
private:
    ////////////////////////////////////////////////////////////
    /// \brief sfml method for drawing
    ////////////////////////////////////////////////////////////
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    /// grid borders
    sf::RectangleShape border;
    /// grid color
    sf::Color color;
    /// boundary size
    sf::Vector2f size;
    /// boundary position
    sf::Vector2f position;
    // vector that holds the points to be plotted
    std::vector<sf::Vertex> curve;
    // graph width
    int graphWidth;

};
}

#endif // SFML_PLOT_VERTICES_H
