# Introduction
Plotter produces a real time graph of the values provided through various sources such as Files, comport etc. Plotter also lets you to also define your source by deriving from the interface "Input".

Plotter is written in C++17 and uses SFML to produce the graphics. Cmake is used to manage the build process.

![Screenshot](github_screenshot.png)

# Minimum Requirements

* C++17
* Cmake version 3.10

# Overview of Plotter

There are 3 modules:
* Input: Input module refers to the source for the plot. The interface can be inherited to suite new sources. Currently, the file class has be provided.
* Buffer: Buffer is where the Input module stores the values it gets from the source.
* RealTimeGraph: RealTimeGraph gets the values from the buffer and plots it on to the graph.

![Screenshot](/Diagrams/Overview.png)

The Plotter consists of 2 threads:

* Read the input from the source and store in the buffer
* Take the value from the buffer and plot

