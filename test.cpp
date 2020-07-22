#include <iostream>
#include <memory>
#include "Input/Input.hpp"
#include "Input/InputContext.hpp"
#include "Plot/Plot.hpp"
#include "Buffer/Buffer.hpp"

int main() {
  std::string filePath = "/home/ppa/Documents/plotter/plotter/Input/sample.txt";
  std::shared_ptr<Buffer> ptr(new Buffer());
  std::unique_ptr<InputContext> input(new InputContext(filePath, ptr));
  if (input->openInput()) {
    input->readDataIntoBuffer();
  }
  double val;
  while (ptr->getValueFromBufferQueue(val)) {
    std::cout << val << " ";
  }
  std::cout << std::endl;
}