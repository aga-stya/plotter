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

    double getMinInCurve() const {
        return minInCurve;
    }
    double getMaxInCurve() const {
        return maxInCurve;
    }
    std::size_t getCurveSize() const {
        return curve.size();
    }

    /**
     * add new vertex with only y co-ordinate
     */
    void addNewPoint (const double y);

private:
    /**
     * setup
     */
    void setup();

    /**
     * move the vertices to the left to accommodate the new vertice and calculate new max and min
     */
    void reassignVertices(double&, double&);

    /**
     * sfml method for drawing
     */
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
