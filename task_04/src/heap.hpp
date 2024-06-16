#include <initializer_list>
#include <iostream>
#include <stdexcept>
#include <vector>

template <class T>
class BinaryHeap {
 public:
  BinaryHeap() : data_() {}
  BinaryHeap(std::initializer_list<T> _data) : data_(_data) {
    for (int i = data_.size() - 1; i >= 0; i--) heapify(i);
  }
  void Insert(T new_elem);

  int ExtractMin();

  void DecreaseKey(int i, T newKey);

 private:
  std::vector<T> data_;
  int GetParentIndex(int i) { return (i - 1) / 2; }
  int GetLefrChildIndex(int i) { return 2 * i + 1; }
  int GetRightChildIndex(int i) { return 2 * i + 2; }

  void heapify(int i);
};

template <class T>
void BinaryHeap<T>::Insert(T new_elem) {
  data_.push_back(new_elem);
  int i = data_.size() - 1;
  while (i != 0 && data_[GetParentIndex(i)] > data_[i]) {
    std::swap(data_[i], data_[GetParentIndex(i)]);
    i = GetParentIndex(i);
  }
}

template <class T>
void BinaryHeap<T>::DecreaseKey(int i, T new_key) {
  if (new_key > data_[i]) {
    throw std::logic_error("New element is greater");
  }
  data_[i] = new_key;
  while (i != 0 && data_[GetParentIndex(i)] > data_[i]) {
    swap(data_[i], data_[GetParentIndex(i)]);
    i = GetParentIndex(i);
  }
}

template <class T>
int BinaryHeap<T>::ExtractMin() {
  if (data_.size() == 0) {
    throw std::underflow_error("Heap is empty");
  }
  if (data_.size() == 1) {
    T returning_value = data_[0];
    data_.pop_back();
    return returning_value;
  }
  int root = data_[0];
  data_[0] = data_[data_.size() - 1];
  data_.pop_back();
  heapify(0);
  return root;
}

template <class T>
void BinaryHeap<T>::heapify(int i) {
  int l = GetLefrChildIndex(i);
  int r = GetRightChildIndex(i);
  int smallest = i;
  if (l < data_.size() && data_[l] < data_[i]) {
    smallest = l;
  }
  if (r < data_.size() && data_[r] < data_[smallest]) {
    smallest = r;
  }
  if (smallest != i) {
    std::swap(data_[i], data_[smallest]);
    heapify(smallest);
  }
}