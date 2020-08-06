#ifndef INPUTCONTEXT_HPP
#define INPUTCONTEXT_HPP

#include <string>
#include <iostream>
#include <memory>
#include <chrono>
#include <thread>

#include "Input.hpp"
#include "FileInput/FileInput.hpp"
#include "ComInput/ComInput.hpp"
#include "../Buffer/Buffer.hpp"

class InputContext {
  private: 
    std::unique_ptr<Input> input;
    std::shared_ptr<Buffer> ptrBuffer;

  private:


  public:
    /**
     * Determines which channel is used by checking for the key words.
     * If "dev" or "com" is in the string inputChannel then its a com port.
     * If "txt" is in the string inputChannel then its from a text file.
     * If the given channel contains ip address then its a TCP/IP channel
     * Therefore its necessary to provide a text file with .txt extension.
     */
    InputContext(const std::string inputChannel, std::shared_ptr<Buffer> ptr):ptrBuffer(ptr) {
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

    int readDataIntoBuffer() const {
      while(1) {
        double inputData;
        int returnVal = input->getInputData(inputData);
        if (returnVal == 0) {
          //EOF sleep for some time and then read again
          std::this_thread::sleep_for(std::chrono::seconds(1));
        } else {
          std::cout << "data read:" << inputData;
          ptrBuffer->insertBufferQueue(inputData);
          std::cout << ", buffer size:" << ptrBuffer->getBufferSize() << "\n";
        }
      }
      return ptrBuffer->getBufferSize();
    }

    bool closeInput() {
      return input->closeInput();
    }
};

#endif