#include <iostream>
#include <memory>
#include "Input/Input.hpp"
#include "Input/SetInput.hpp"
#include "Plot/Plot.hpp"

int main() {
  //std::unique_ptr<SetInput> input(new SetInput("/home/pavan/Documents/plotter/Input/sample.txt"));
  std::unique_ptr<SetInput> input(new SetInput("/dev/"));
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

}