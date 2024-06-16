#include <vector>

template <class T>
std::size_t Division(std::vector<T> data, std::size_t left, std::size_t right) {
  std::size_t middle = (left + right - 1) / 2;

  if (data[left] < data[middle]) {
    if (data[right] < data[left])
      return left;
    else if (data[right] < data[middle])
      return right;
    return middle;
  } else {
    if (data[right] < data[middle])
      return middle;
    else if (data[right] < data[left])
      return right;
    return left;
  }
}

template <class T>
std::size_t Partition(std::vector<T>& data, std::size_t left,
                      std::size_t right) {
  std::size_t pivotPos = Division(data, left, right);

  if (pivotPos != right - 1) {
    std::swap(data[right - 1], data[pivotPos]);
  }

  std::size_t left_index = left;
  std::size_t right_index = left;
  T pivot = data[right - 1];
  while (right_index < right - 1) {
    if (data[right_index] <= pivot) {
      std::swap(data[left_index++], data[right_index]);
    }
    ++right_index;
  }
  if (left_index != right - 1) {
    std::swap(data[left_index], data[right - 1]);
  }
  return left_index;
}

template <class T>
T FindOrderStatistic(std::vector<T>& data, std::size_t k) {
  std::size_t lastPivotPos = 0;
  std::size_t left = 0;
  std::size_t right = data.size();

  while (left < right) {
    if ((lastPivotPos = Partition(data, left, right)) == k)
      return data[lastPivotPos];
    else if (lastPivotPos > k) {
      right = lastPivotPos;
    } else {
      left = lastPivotPos + 1;
    }
  }
  return data[lastPivotPos];
}