#include <algorithm>
#include <cstddef>
#include <vector>

template <typename T>
class MaxHeap {
 public:
  MaxHeap() = default;

  MaxHeap(const std::vector<T>& data) {
    for (auto& elem : data) Add(elem);
  }

  MaxHeap(const std::initializer_list<T>& data) {
    for (const auto& elem : data) Add(elem);
  }

  T ExtractMax() {
    if (Empty()) throw std::out_of_range("Empty heap!");

    T max = data_[0];
    std::swap(data_[0], data_[Size() - 1]);
    data_.pop_back();
    SiftDown(0);
    return max;
  }

  void Add(T elem) {
    data_.push_back(elem);
    SiftUp();
  }

  size_t Size() const { return data_.size(); }

  bool Empty() const { return Size() == 0; }

 private:
  std::vector<T> data_;

  size_t IndexParent(size_t index) const { return (index - 1) / 2; }

  size_t IndexLeftChild(size_t index) const { return (2 * index + 1); }

  size_t IndexRightChild(size_t index) const { return (2 * index + 2); }

  void SiftDown(size_t index) {
    while (IndexLeftChild(index) < Size()) {
      size_t max = IndexLeftChild(index);
      if (IndexRightChild(index) < Size() &&
          data_[IndexRightChild(index)] > data_[max])
        max = IndexRightChild(index);
      if (data_[index] > data_[max]) break;
      std::swap(data_[index], data_[max]);
      index = max;
    }
  }

  void SiftUp() {
    size_t index = Size() - 1;
    while (index > 0 && data_[index] > data_[IndexParent(index)]) {
      std::swap(data_[index], data_[IndexParent(index)]);
      index = IndexParent(index);
    }
  }
};
