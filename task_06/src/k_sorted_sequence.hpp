#include <cstddef>
#include <stdexcept>
#include <vector>

// Function to find the k-th smallest element in a sorted sequence using
// Quickselect algorithm
template <typename T>
T FindSortedSequence(std::vector<T> array, int k) {
  int begin = 0, end = array.size() - 1;

  // Check if k is within the bounds of the array
  if (k > end)
    throw std::out_of_range("k should be less than the size of the array");

  // Loop until the k-th element is found
  while (true) {
    int first = begin;
    int pivot =
        (rand() % (end - begin + 1)) + begin;  // Randomly select a pivot
    std::swap(array[pivot], array[end]);       // Move pivot element to the end

    // Partition the array based on the pivot element
    while (array[begin] <= array[end] && begin < end) ++begin;

    for (int start = begin + 1; start < end; ++start)
      if (array[start] <= array[end]) std::swap(array[start], array[begin++]);
    std::swap(array[begin], array[end]);

    // Check if the k-th element is found at the current partition
    if (k == begin)
      return array[begin];
    else if (k < begin) {
      end = begin - 1;
      if (end == first) return array[begin - 1];
      begin = 0;
    } else if (k > begin) {
      ++begin;
      if (begin == end) return array[begin];
    }
  }
}
