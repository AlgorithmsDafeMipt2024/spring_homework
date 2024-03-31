#include <vector>

template <typename T>
void InsertionSort(std::vector<T> &array, int begin, int end) {
  for (int i = begin + 1; i <= end; i++) {
    for (int j = i; j > 0; --j) {
      if (array[j - 1] > array[j])
        std::swap(array[j], array[j - 1]);
      else
        break;
    }
  }
}

template <typename T>
int Partition(std::vector<T> &array, int begin, int end) {
  int pivot_index = (rand() % (end - begin) + 1) + begin;
  std::swap(array[pivot_index], array[end]);
  T pivot = array[end];
  while (true) {
    while (array[begin] < pivot) begin++;
    while (array[end] > pivot) end--;
    if (begin >= end) {
      return end;
    }
    std::swap(array[begin++], array[end--]);
  }
}

template <typename T>
void QuickSort(std::vector<T> &array, int begin, int end) {
  const int InsertionSortThreshold = 25;
  while (begin < end) {
    if (end - begin <= 25) {
      InsertionSort(array, begin, end);
      return;
    }
    int pivot_index = Partition(array, begin, end);
    if (pivot_index - begin < end - pivot_index) {
      QuickSort(array, begin, pivot_index);
      begin = pivot_index + 1;
    } else {
      QuickSort(array, pivot_index + 1, end);
      end = pivot_index;
    }
  }
}