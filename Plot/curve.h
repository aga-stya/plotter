#ifndef SFML_PLOT_VERTICES_H
#define SFML_PLOT_VERTICES_H

#include <vector>
#include <SFML/Graphics.hpp>

#include "specification.hpp"
#include "axisValues.h"

namespace plot {

class Curve : public sf::Drawable
            , public sf::Transformable {

public:
    /**
     * Default constructor
     */
    Curve();

    /**
     * Copy constructor not required
     */
    Curve(const Curve&) = delete;

    /**
     * Copy assignment not required
     */
    Curve& operator=(const Curve&) = delete;

    /**
     * Move constructor not required
     */
    Curve(Curve&&) = delete;

    /**
     * Move assignment operator not required
     */
    Curve& operator=(Curve&&) = delete;

    /**
     * Default Destructor 
     */
    ~Curve() = default;

    /**
     * getter for minimum most value in curve 
     */
    double getMinInCurve() const noexcept{
        return minInCurve;
    }

    /**
     * getter for maximum most value in curve 
     */
    double getMaxInCurve() const noexcept{
        return maxInCurve;
    }

    /**
     * get the number of values in the curve
     */
    std::size_t getCurveSize() const noexcept{
        return curve.size();
    }

    /**
     * add new vertex with only y co-ordinate
     */
    void addNewPoint (const double y) noexcept;

private:
    /**
     * setup
     */
    void setup() noexcept;

    /**
     * move the vertices to the left to accommodate the new vertice and calculate new max and min
     */
    void reassignVertices(double&, double&) noexcept;

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
