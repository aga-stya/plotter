#include <iostream>
#include <memory>
#include <chrono>
#include <thread>
#include <string>

#include "Input/Input.hpp"
#include "Input/InputContext.hpp"
#include "Plot/Plot.hpp"
#include "Buffer/Buffer.hpp"
#include "realTimePlot/realTimePlot.h"

#include <QApplication>


void readDataIntoBuffer(std::string filePath, std::shared_ptr<Buffer> ptr) {
  std::unique_ptr<InputContext> input(new InputContext(filePath, ptr));
  if (input->openInput()) {
    input->readDataIntoBuffer();
  } else {
    std::cerr << "Input cannot be opened\n";
    return;
  }
}

void readDataFromBuffer( const std::shared_ptr<Buffer> ptr) {
  while(1) {
    double val;
    if (ptr->getValueFromBufferQueue(val)) {
      std::cout << "data from buffer: " << val << "\n";
    } else {
      std::cout << "Empty buffer \n";
      std::this_thread::sleep_for(std::chrono::seconds(1));
    }
  }
}

void writeDataToFile(std::string filePath) {
  std::ofstream outFile;
  if (outFile) {
    while(1) {
      for (auto i = 0; i < 8; i++) {
        outFile.open(filePath, std::ios_base::app);
        outFile << i << "\n";
        outFile.close();
        std::this_thread::sleep_for(std::chrono::seconds(1));
      }
    }
  }
}
//int qtSample(int argc, char *argv[])
int qtSample(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setStyleSheet("* {font-family:arial;font-size:11px}");
    RealtimeDemo demo;
    demo.show();
    return app.exec();
    return 0;
}

int main(int argc, char *argv[]) {
  //Sample data file
  std::string filePath = "/home/pavan/Documents/plotter/Input/sample.txt";
  //Pointer to the buffer object, the same instance must be used for both writing and reading
  std::shared_ptr<Buffer> ptr(new Buffer());
  //various threads
  /*std::thread writeToFileThread(writeDataToFile, filePath);
  std::thread readIntoBufferThread(readDataIntoBuffer, filePath, ptr);
  std::thread readFromBufferThread(readDataFromBuffer, ptr);
  writeToFileThread.join();
  readIntoBufferThread.join();
  readFromBufferThread.join();*/
  std::thread qtThread(qtSample, argc, argv);
  qtThread.join();
}