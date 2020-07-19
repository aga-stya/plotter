#include <iostream>
#include "ComInput.hpp"

bool ComInput::openInput(){
  std::cout << "Open ComInput channel\n";
  return true;
}

int ComInput::getInputData(double& inputValue) {
  std::cout << "getInputData\n";
  return 1;
}

bool ComInput::closeInput() {
  std::cout << "Close ComInput channel\n";
  return true;
}



