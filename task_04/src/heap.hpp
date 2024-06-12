#include <initializer_list>
#include <iostream>
#include <stdexcept>
#include <vector>

template <class T>
class BinaryHeap {
 public:
  BinaryHeap() : data() {}
  BinaryHeap(std::initializer_list<T> _data) : data(_data) {
    for (int i = data.size() - 1; i >= 0; i--) heapify(i);
  }
  void insert(T newElem);

  int extractMin();

  void decreaseKey(int i, T newKey);

 private:
  std::vector<T> data;
  int getParentIdx(int i) { return (i - 1) / 2; }
  int getLefrChildIdx(int i) { return 2 * i + 1; }
  int getRightChildIdx(int i) { return 2 * i + 2; }

  void heapify(int i);
};

template <class T>
void BinaryHeap<T>::insert(T newElem) {
  data.push_back(newElem);
  int i = data.size() - 1;
  while (i != 0 && data[getParentIdx(i)] > data[i]) {
    std::swap(data[i], data[getParentIdx(i)]);
    i = getParentIdx(i);
  }
}

template <class T>
void BinaryHeap<T>::decreaseKey(int i, T newKey) {
  if (newKey > data[i]) {
    throw std::logic_error("New element is greater");
  }
  data[i] = newKey;
  while (i != 0 && data[getParentIdx(i)] > data[i]) {
    swap(data[i], data[getParentIdx(i)]);
    i = getParentIdx(i);
  }
}

template <class T>
int BinaryHeap<T>::extractMin() {
  if (data.size() == 0) {
    throw std::underflow_error("Heap is empty");
  }
  if (data.size() == 1) {
    T returningValue = data[0];
    data.pop_back();
    return returningValue;
  }
  int root = data[0];
  data[0] = data[data.size() - 1];
  data.pop_back();
  heapify(0);
  return root;
}

template <class T>
void BinaryHeap<T>::heapify(int i) {
  int l = getLefrChildIdx(i);
  int r = getRightChildIdx(i);
  int smallest = i;
  if (l < data.size() && data[l] < data[i]) {
    smallest = l;
  }
  if (r < data.size() && data[r] < data[smallest]) {
    smallest = r;
  }
  if (smallest != i) {
    std::swap(data[i], data[smallest]);
    heapify(smallest);
  }
}