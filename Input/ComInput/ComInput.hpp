#ifndef COMINPUT_HPP
#define COMINPUT_HPP

#include "../Input.hpp"
#include <fstream>
#include <string>

class ComInput : public Input {
  private:
    std::string fileName;
    std::ifstream fileStream;

  public:
    ComInput(std::string filePath): fileName(filePath), fileStream(filePath){
    }
    bool openInput()           override;
    int  getInputData(double&) override;
    bool closeInput()          override;
    ~ComInput(){}
};

#endif