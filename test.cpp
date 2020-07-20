#include <iostream>
#include <memory>
#include "Input/Input.hpp"
#include "Input/InputContext.hpp"
#include "Plot/Plot.hpp"
#include "Buffer/Buffer.hpp"

int main() {
  //std::unique_ptr<InputContext> input(new InputContext("/home/pavan/Documents/plotter/Input/sample.txt"));
  std::unique_ptr<InputContext> input(new InputContext("/dev/"));
  if (input->openInput()) {
    /*while(1) {
      double inputData;
      int returnVal = input->getInputData(inputData);
      if (returnVal == 0) {
        std::cout << inputData << "\n";
        break;
      } else if (returnVal == 2) {
        std::cout << "invalid input\n";
      } else {
        std::cout << inputData << "\n";
      }
    }*/
    input->closeInput();
  }
  plot();
  Buffer buffer;
  std::cout << buffer.isBufferQueueEmpty() << std::endl;
  buffer.insertBufferQueue(5.6);
  std::cout << buffer.isBufferQueueEmpty() << std::endl;
  std::cout << buffer.getValueFromBufferQueue() << std::endl;
  std::cout << buffer.isBufferQueueEmpty() << std::endl;
}