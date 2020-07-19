#ifndef FILEINPUT_HPP
#define FILEINPUT_HPP

#include "../Input.hpp"
#include <fstream>

class FileInput : public Input {
  private:
    std::string fileName;
    std::ifstream fileStream;

  public:
    FileInput(std::string filePath): fileName(filePath), fileStream(filePath){
    }
    bool openInput()           override;
    int  getInputData(double&) override;
    bool closeInput()          override;
    ~FileInput(){}
};

#endif