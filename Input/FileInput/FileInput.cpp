
#include <iostream>
#include "FileInput.hpp"

bool FileInput::openInput(){
  if (fileStream.is_open()) {
    std::cout << "Input(File) opened successfully\n";
    return true;
  } else {
    std::cerr << "Input(File) cannot be found\n";
    return false;
  }
}

int FileInput::getInputData(double& inputValue) {
  fileStream >> inputValue;
  if (fileStream.fail()) {
    std::cerr << "Invalid input, non-number present in the Input(file), ";
    //clear the error bits 
    fileStream.clear();
    //read the character from the stream which is causing the error
    std::string s;
    fileStream >> s;
    std::cerr << "the element which is causing the problem is \"" << s << "\"\n";
    return 2;
  } else if (fileStream.eof()){
    std::cout << "End of Input(File) " << fileName <<  " is reached\n";
    return 0;
  } else if (fileStream.bad()) {
    std::cout << "Bad stream while reading Input(file)\n";
    return 0;
  } else {
    return 1;
  } 
}

bool FileInput::closeInput() {
  if (fileStream.is_open()) {  
    fileStream.close();
  }
  return true;
}



