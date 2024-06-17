#include <vector>
#include <random>

// Function to perform Insertion Sort on a subarray from index 'begin' to 'end'
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

// Function to partition the array and return the pivot index
template <typename T>
int Partition(std::vector<T> &array, int begin, int end) {
  int pivot_index = (rand() % (end - begin + 1)) + begin;
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

// Function to perform Quick Sort on a subarray from index 'begin' to 'end'
template <typename T>
void QuickSort(std::vector<T> &array, int begin, int end) {
  const int InsertionSortThreshold = 25;
  while (begin < end) {
    if (end - begin <= InsertionSortThreshold) {
      InsertionSort(array, begin,
                    end);  // Perform Insertion Sort if subarray size is small
      return;
    }
    int pivot_index = Partition(array, begin, end);
    if (pivot_index - begin < end - pivot_index) {
      QuickSort(array, begin,
                pivot_index);  // Recursively sort the left subarray
      begin = pivot_index + 1;
    } else {
      QuickSort(array, pivot_index + 1,
                end);  // Recursively sort the right subarray
      end = pivot_index;
    }
  }
}
