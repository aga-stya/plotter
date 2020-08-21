#ifndef SFML_PLOT_VERTICES_H
#define SFML_PLOT_VERTICES_H

#include <vector>
#include <SFML/Graphics.hpp>

#include "specification.hpp"
#include "axisValues.h"

namespace plot {

class Curve 
        : public sf::Drawable
        , public sf::Transformable {
public:
    Curve();

    void setup();
    // add a new vertex with y co-ordinate only
    void addNewPoint (double y);
    // increase the x co-ordinate
    void increaseX();
    // start the loop for the graph
    void startRealTimeGraph();
    // move the vertices to the left to accommodate the new vertice
    void reassignVertices(double&, double&);

    double getMinInCurve() {
        return minInCurve;
    }
    double getMaxInCurve() {
        return maxInCurve;
    }

private:
    ////////////////////////////////////////////////////////////
    /// \brief sfml method for drawing
    ////////////////////////////////////////////////////////////
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    /// grid color
    sf::Color color;
    // vector that holds the points to be plotted
    std::vector<sf::Vertex> curve;
    std::unique_ptr<plot::AxisValues> ptrYAxisValues;
    double minInCurve;
    double maxInCurve;
};
}

#endif // SFML_PLOT_VERTICES_H
