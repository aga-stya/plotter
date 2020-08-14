#ifndef BUFFER_HPP
#define BUFFER_HPP

#include <iostream>
#include <queue>
#include <mutex>

class Buffer {
  private:
    std::queue<double> bufferQueue;
    std::mutex mtx;
  
  public:
    void insertBufferQueue(double value) {
      std::lock_guard<std::mutex> lockGuard(this->mtx);
      bufferQueue.push(value);
    }
    bool getValueFromBufferQueue(double& value) {
      std::lock_guard<std::mutex> lockGuard(this->mtx);
      if (bufferQueue.empty()) {
        return false;
      }
      value = bufferQueue.front();
      bufferQueue.pop();
      return true;
    }
    bool isBufferQueueEmpty() {
      std::lock_guard<std::mutex> lockGuard(this->mtx);
      return bufferQueue.empty();
    }
    int getBufferSize() {
      std::lock_guard<std::mutex> lockGuard(this->mtx);
      return bufferQueue.size();
    }
};
#endif