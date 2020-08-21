#ifndef AXIS_VALUES_H
#define AXIS_VALUES_H 

#include <vector>
#include <SFML/Graphics.hpp>

#include "specification.hpp"

namespace plot {

class AxisValues 
        : public sf::Drawable
        , public sf::Transformable {
private:

public:
    enum Axis {
        XAXIS,
        YAXIS,
    };
    ////////////////////////////////////////////////////////////
    /// \brief constructor
    ////////////////////////////////////////////////////////////
    AxisValues(int, int, int, Axis);
    ////////////////////////////////////////////////////////////
    /// \brief setup once the Axis shape
    ///
    /// \param size Axis size
    ////////////////////////////////////////////////////////////
    void setup();
private:
    ////////////////////////////////////////////////////////////
    /// \brief sfml method for drawing
    ////////////////////////////////////////////////////////////
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    /// Axes 
    std::vector<sf::Text> axisValues;
    double startValue;
    double endValue;
    int xAxisStartPosition = 100;
    int totalSpaceAvailable = 500;
    int distBetweenX;

    sf::Font font;

    /// Axis color
    sf::Color nameColor;
    sf::Vector2f graphSize;
    sf::Vector2f offset;

    // axis under consideration
    Axis axis;
};
}

#endif // AXIS_VALUES_H 
