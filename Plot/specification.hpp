#ifndef SPECIFICATION_HPP
#define SPECIFICATION_HPP

#include <SFML/Graphics.hpp>

constexpr int xOffset = 100; 
constexpr int yOffset = 50;

constexpr int xAxisStart = 100;
constexpr int xAxisEnd = 600;
constexpr int yAxisStart = 50;
constexpr int yAxisEnd = 550;

constexpr int graphWidth = 500;
constexpr int graphHeight = 500;

constexpr int distanceBetweenX = 3;

//borders
constexpr int kBorderSize = 2;

//axis
constexpr int xAxisNamePositionY = yAxisEnd + 20;
constexpr int yAxisNamePositionX = xOffset - 30;

//grid
constexpr int numOfGrids = 4;
constexpr int gridPositionX = 100;
constexpr int gridPositionY = 50;
#endif