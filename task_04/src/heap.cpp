#include "heap.hpp"

void Heap::SiftUp(int i) {
  while (a[i] < a[i / 2]) {
    std::swap(a[i], a[i / 2]);
    i /= 2;
  }
}

void Heap::SiftDown(int i) {
  while (2 * i < n) {
    int j = -1;
    if (a[2 * i] < a[i]) {
      j = 2 * i;
    }
    if (2 * i + 1 < n && a[2 * i + 1] < a[i] &&
        (j == -1 || a[2 * i] > a[2 * i + 1])) {
      j = 2 * i + 1;
    }
    if (j == -1)
      break;
    else {
      std::swap(a[i], a[j]);
      i = j;
    }
  }
}

int Heap::Size() { return a.size(); }

int Heap::GetMin() {
  if (a.size() == 0) {
    throw std::out_of_range("Heap is empty");
  }
  return a[0];
}

void Heap::Insert(int x) {
  a.push_back(x);
  n++;
  SiftUp(n - 1);
}

void Heap::ExtractMin() {
  if (a.size() == 0) {
    throw std::out_of_range("Heap is empty");
  }
  a[0] = a[n - 1];
  a.erase(a.begin() + n - 1);
  n--;
  SiftDown(0);
}
