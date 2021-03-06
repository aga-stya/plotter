#ifndef SPECIFICATION_HPP
#define SPECIFICATION_HPP

#include <SFML/Graphics.hpp>

//menu area specifications
static constexpr int menuAreaWidth    = 300;
static constexpr int menuAreaHeight   = 600;
static constexpr int menuAreaPositionX = 700;
static constexpr int menuAreaPositionY = 0;

//plot area specifications
static constexpr int plotAreaWidth  = 700 ;
static constexpr int plotAreaHeight = 600 ;
static constexpr int plotAreaPositionX = 0;
static constexpr int plotAreaPositionY = 0;

constexpr int xOffset = 100; 
constexpr int yOffset = 50;

constexpr int xAxisStart = 100;
constexpr int xAxisEnd = 600;
constexpr int yAxisStart = 50;
constexpr int yAxisEnd = 550;

constexpr int graphWidth = 500;
constexpr int graphHeight = 500;

constexpr int distanceBetweenPoints = 1;

//borders
constexpr int kBorderSize = 2;

//axis
constexpr int xAxisNamePositionY = yAxisEnd + 20;
constexpr int yAxisNamePositionX = xOffset - 50;

//grid
constexpr int numOfGrids = 4;
constexpr int gridPositionX = 100;
constexpr int gridPositionY = 50;
constexpr int gridValuePositionY = 5;

//font file location
constexpr auto openSans = "/home/pavan/Documents/fonts/OpenSans-Regular.ttf";
//constexpr auto fnt = "/home/pavan/Documents/fonts/font.ttf";
constexpr auto fnt = "/home/pavan/Documents/fonts/font.ttf";

//input file location
//constexpr auto inputFile = "/home/pavan/Documents/plotter_olderversion/plotter/sample_ramp.txt";
//constexpr auto inputFile = "/home/pavan/Documents/plotter_olderversion/plotter/sample.txt";
constexpr auto inputFile = "/home/pavan//plotter/Plot/rampData.txt";

#endif