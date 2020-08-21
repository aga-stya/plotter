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

constexpr int distanceBetweenX = 1;

//borders
constexpr int kBorderSize = 2;

//axis
constexpr int xAxisNamePositionY = yAxisEnd + 20;
constexpr int yAxisNamePositionX = xOffset - 30;

//grid
constexpr int numOfGrids = 4;
constexpr int gridPositionX = 100;
constexpr int gridPositionY = 50;
constexpr int gridValuePositionY = 5;

//font file location
constexpr auto openSans = "/home/pavan/Documents/fonts/OpenSans-Regular.ttf";
constexpr auto fnt = "/home/pavan/Documents/fonts/font.ttf";

//input file location
//constexpr auto inputFile = "/home/pavan/Documents/plotter_olderversion/plotter/sample_ramp.txt";
//constexpr auto inputFile = "/home/pavan/Documents/plotter_olderversion/plotter/sample.txt";
constexpr auto inputFile = "/home/pavan/Documents/plotter_olderversion/plotter/Plot/rampData.txt";

#endif