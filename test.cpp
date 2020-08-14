#include <iostream>
#include <memory>
#include <chrono>
#include <thread>

#include "Input/Input.hpp"
#include "Input/InputContext.hpp"
#include "Plot/RealTimeGraph.hpp"
#include "Buffer/Buffer.hpp"

void readInput(std::shared_ptr<Buffer> ptr) {
  std::string filePath = "/home/pavan/Documents/plotter_olderversion/plotter/sample.txt";
  std::unique_ptr<InputContext> input(new InputContext(filePath, ptr));
  if (input->openInput()) {
    input->readDataIntoBuffer();
  }
  //double val;
  //while (ptr->getValueFromBufferQueue(val)) {
  //  std::cout << val << " ";
  //  std::this_thread::sleep_for(std::chrono::milliseconds(100));
  //}
  //std::cout << std::endl;
}

void plotting(std::shared_ptr<Buffer> ptr) {
  realTimeGraph MyGraph(500, 500, "My Window", ptr);
  MyGraph.startRealTimeGraph();
}

int main() {
  std::shared_ptr<Buffer> ptr(new Buffer());
  std::thread readInputThread(readInput, ptr);
  std::thread plotThread(plotting, ptr);
  plotThread.join();
  readInputThread.join();
}