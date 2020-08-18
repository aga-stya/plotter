#include <iostream>
#include <memory>
#include <chrono>
#include <thread>

#include "Input/Input.hpp"
#include "Input/InputContext.hpp"
#include "Plot/RealTimeGraph.hpp"
#include "Buffer/Buffer.hpp"

void readInput(std::shared_ptr<Buffer> ptr) {
  std::string filePath = "/home/pavan/plotter/sample.txt";
  std::unique_ptr<InputContext> input(new InputContext(filePath, ptr));
  if (input->openInput()) {
    input->readDataIntoBuffer();
  } else {
    std::cerr << "Input cannot be opened\n";
    return;
  }
}

void plotting(std::shared_ptr<Buffer> ptr) {
  realTimeGraph MyGraph("My Window", ptr);
  MyGraph.startRealTimeGraph();
}

int main() {
  std::shared_ptr<Buffer> ptr(new Buffer());
  std::thread readInputThread(readInput, ptr);
  std::thread plotThread(plotting, ptr);
  plotThread.join();
  readInputThread.join();
}