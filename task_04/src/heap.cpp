#include "heap.hpp"

void Heap::SiftUp(int i) {
  int half_i = i/2;
  while (elements[i] < elements[half_i]) {
    std::swap(elements[i], elements[half_i]);
    i /= 2;
    half_i /= 2;
  }
}

void Heap::SiftDown(int i) {
  int leftChildIndex = 2 * i;
  int rightChildIndex = 2 * i + 1;
  while (leftChildIndex < n) {
    int j = -1;
    if (elements[leftChildIndex] < elements[i]) {
      j = leftChildIndex;
    }
    if (rightChildIndex < n && elements[rightChildIndex] < elements[i] &&
        (j == -1 || elements[leftChildIndex] > elements[rightChildIndex])) {
      j = rightChildIndex;
    }
    if (j == -1)
      break;
    else {
      std::swap(elements[i], elements[j]);
      leftChildIndex = 2 * j;
      rightChildIndex = 2 * j + 1;
    }
  }
}

int Heap::Size() { return elements.size(); }

int Heap::GetMin() {
  if (elements.size() == 0) {
    throw std::out_of_range("Heap is empty");
  }
  return elements[0];
}

void Heap::Insert(int x) {
  elements.push_back(x);
  n++;
  SiftUp(n - 1);
}

void Heap::ExtractMin() {
  if (elements.size() == 0) {
    throw std::out_of_range("Heap is empty");
  }
  elements[0] = elements[n - 1];
  elements.erase(elements.begin() + n - 1);
  n--;
  SiftDown(0);
}
