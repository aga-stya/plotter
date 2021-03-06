#include <iostream>
#include <memory>
#include <chrono>
#include <thread>

#include "Input/Input.hpp"
#include "Input/InputContext.hpp"
#include "Plot/RealTimeGraph.hpp"
#include "Buffer/Buffer.hpp"

void readInput(std::shared_ptr<Buffer> ptr) {
  std::unique_ptr<InputContext> input(new InputContext(inputFile, ptr));
  if (input->openInput()) {
    std::cout << "number of values read till now:" << input->readDataIntoBuffer() << "\n";
  } else {
    std::cerr << "Input cannot be opened\n";
    return;
  }
}

void plotting(std::shared_ptr<Buffer> ptr) {
  realTimeGraph MyGraph(ptr, "Plot ramp", "This is x axis", "This is y axis");
  MyGraph.startRealTimeGraph();
}

int main() {
  std::shared_ptr<Buffer> ptr = std::make_shared<Buffer>();
  std::thread readInputThread(readInput, ptr);
  std::thread plotThread(plotting, ptr);
  plotThread.join();
  readInputThread.join();
}