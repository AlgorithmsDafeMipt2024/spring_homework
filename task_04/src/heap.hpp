#ifndef HEAP_HPP
#define HEAP_HPP
#include <cstddef>
#include <initializer_list>
#include <iterator>
#include <stdexcept>
#include <vector>

template <class T>
class Heap {
 public:
  Heap() : data_{} {}

  Heap(Heap<T> const& other) : data_{other.data_} {}

  Heap(std::initializer_list<T> data) : data_{data} {
    for (size_t i = data_.size() / 2; i; i--) siftDown(i);
    siftDown(0);
  }

  Heap(std::vector<T> data) : data_{data} {
    for (size_t i = data_.size() / 2; i; i--) siftDown(i);
    siftDown(0);
  }

  Heap const& operator=(Heap const& other) {
    data_ = other.data_;
    return *(this);
  }

  T popMin() {
    if (data_.empty()) throw std::runtime_error("can't pop min: heap is empty");
    T result = data_[0];
    data_[0] = data_.back();
    data_.pop_back();
    siftDown(0);
    return result;
  }
  void push(T value) {
    data_.push_back(value);
    siftUp(data_.size() - 1);
  }

 private:
  void siftUp(size_t i) {
    while (i && data_[i] < data_[(i - 1) / 2]) {
      std::swap(data_[i], data_[(i - 1) / 2]);
      i = (i - 1) / 2;
    }
  }
  void siftDown(size_t i) {
    while ((2 * i + 1) < data_.size()) {
      size_t left = 2 * i + 1;
      size_t right = 2 * i + 2;
      size_t j = left;
      if ((right < data_.size()) && (data_[right] < data_[left])) j = right;
      if (data_[i] <= data_[j]) break;
      std::swap(data_[i], data_[j]);
      i = j;
    }
  }
  std::vector<T> data_;
};

#endif