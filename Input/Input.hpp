#ifndef INPUT_HPP
#define INPUT_HPP

#include <string>

class Input {
  public:
    virtual bool openInput() = 0;
    virtual int  getInputData(double&) = 0;
    virtual bool closeInput() = 0;
    virtual ~Input(){}
};

#endif