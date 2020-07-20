#ifndef BUFFER_HPP
#define BUFFER_HPP

#include <iostream>
#include <queue>

class Buffer {
  private:
    std::queue<double> bufferQueue;
  
  public:
    void insertBufferQueue(double value) {
        bufferQueue.push(value);
    }
    double getValueFromBufferQueue() {
        double result = bufferQueue.front();
        bufferQueue.pop();
        return result;
    }
    bool isBufferQueueEmpty() {
      return bufferQueue.empty();
    }
};
#endif