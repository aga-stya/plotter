#ifndef INPUTCONTEXT_HPP
#define INPUTCONTEXT_HPP

#include <string>
#include <iostream>
#include <memory>
#include "Input.hpp"
#include "FileInput/FileInput.hpp"
#include "ComInput/ComInput.hpp"
#include "../Buffer/Buffer.hpp"

class InputContext {
  private: 
    std::unique_ptr<Input> input;
    std::shared_ptr<Buffer> ptrBuffer;

  public:
    /**
     * Determines which channel is used by checking for the key words.
     * If "dev" or "com" is in the string inputChannel then its a com port.
     * If "txt" is in the string inputChannel then its from a text file.
     * If the given channel contains ip address then its a TCP/IP channel
     * Therefore its necessary to provide a text file with .txt extension.
     */
    InputContext(std::string inputChannel, std::shared_ptr<Buffer> ptr):ptrBuffer(ptr) {
      //ptrBuffer = ptr;
      if (inputChannel.find("dev") != std::string::npos ||
          inputChannel.find("com") != std::string::npos) {
        //inputChannel is a com port
        std::cout << "Input channel chosen is a com port\n";
        input = std::make_unique<ComInput>(inputChannel);
      } else if (inputChannel.find("txt") != std::string::npos) {
        std::cout << "Input channel chosen is a text file\n";
        input = std::make_unique<FileInput>(inputChannel);
      }
    }

    bool openInput() {
      return input->openInput();
    }

    int  readDataIntoBuffer() {
      while(1) {
        double inputData;
        int returnVal = input->getInputData(inputData);
        if (returnVal == 0) {
          std::cout << inputData << "\n";
          ptrBuffer->insertBufferQueue(inputData);
          break;
        } else if (returnVal == 2) {
          std::cout << "invalid input\n";
        } else {
          std::cout << inputData << "\n";
          ptrBuffer->insertBufferQueue(inputData);
        }
      }
      return ptrBuffer->getBufferSize();
    }

    bool closeInput() {
      return input->closeInput();
    }
};

#endif