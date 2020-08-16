
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
  if (fileStream >> inputValue) {
    //TEST
    //inputValue *= 2;
    return 1;
  } else if (fileStream.eof()){
    fileStream.clear();
    std::cout << "End of Input(File) " << fileName <<  " is reached\n";
    return 0;
  } else if (fileStream.fail()) {
    std::cerr << "Invalid input, non-number present in the Input(file), ";
    //clear the error bits 
    fileStream.clear();
    //read the character from the stream which is causing the error
    std::string s;
    fileStream >> s;
    std::cerr << "invalid element in the stream\"" << s << "\"\n";
    return 2;
  } else if (fileStream.bad()) {
    //TODO: dont know what to do here yet (should i stop the execution or continue to take the input);
    std::cout << "Bad stream while reading Input(file)\n";
    return 0;
  } else {
    return 0;
  } 
}

bool FileInput::closeInput() {
  if (fileStream.is_open()) {  
    fileStream.close();
  }
  return true;
}



