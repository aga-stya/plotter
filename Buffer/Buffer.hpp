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

    bool getValueFromBufferQueue(double& value) {
      if (bufferQueue.empty()) {
        return false;
      }
      value = bufferQueue.front();
      bufferQueue.pop();
      return true;
    }

    bool isBufferQueueEmpty() {
      return bufferQueue.empty();
    }

    int getBufferSize() {
      return bufferQueue.size();
    }
};
#endif