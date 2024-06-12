#pragma once

#include <vector>

class SORT {
 public:
  SORT(){};

  void heapsort(std::vector<int> &list);
  std::vector<int> heapsorted(std::vector<int> list);

  void quicksort(std::vector<int> &list);
  void quicksort(std::vector<int> &list, int start, int end);
  std::vector<int> quicksorted(std::vector<int> list);

  void mergesort(std::vector<int> &list);
  void mergesort(std::vector<int> &list, int start, int end);
  std::vector<int> mergesorted(std::vector<int> list);

 private:
  void swap(std::vector<int> &A, int i, int j);
  void heapify(std::vector<int> &A, int h_size, int i);
  int partition(std::vector<int> &A, int start, int end);
  void sort_and_merge(std::vector<int> &A, int start, int end);
};
