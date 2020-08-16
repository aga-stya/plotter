#ifndef SFML_PLOT_Axis_H
#define SFML_PLOT_Axis_H

#include <vector>
#include <SFML/Graphics.hpp>

namespace plot {

class Axis
        : public sf::Drawable
        , public sf::Transformable {
private:

public:
    ////////////////////////////////////////////////////////////
    /// \brief constructor
    ////////////////////////////////////////////////////////////
    Axis();
    ////////////////////////////////////////////////////////////
    /// \brief setup once the Axis shape
    ///
    /// \param size Axis size
    ////////////////////////////////////////////////////////////
    void setup(std::string fileName);
private:
    ////////////////////////////////////////////////////////////
    /// \brief sfml method for drawing
    ////////////////////////////////////////////////////////////
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    /// Axes 
    std::string xAxisName;
    std::string yAxisName;
    sf::Text xAxis;
    sf::Text yAxis;

    sf::Font font;

    /// Axis color
    sf::Color color_;
};
}

#endif // SFML_PLOT_Axis_H
