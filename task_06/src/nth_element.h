#include <vector>

template <class T>
std::size_t Division(std::vector<T> data, std::size_t left, std::size_t right) {
  std::size_t half = (left + right - 1) / 2;  // середина списка

  if (data[left] < data[half]) {
    if (data[right] < data[left])
      return left;
    else if (data[right] < data[half])
      return right;
    return half;
  } else {
    if (data[right] < data[half])
      return half;
    else if (data[right] < data[left])
      return right;
    return left;
  }
}

template <class T>
std::size_t Partition(std::vector<T>& data, std::size_t left,
                      std::size_t right) {
  std::size_t pivotPos = Division(data, left, right);

  if (pivotPos != right - 1) {  // меняем местами опорный элемент с последним
    std::swap(data[right - 1], data[pivotPos]);
  }

  std::size_t i = left;
  std::size_t j = left;
  T pivot = data[right - 1];
  while (j < right - 1) {
    if (data[j] <= pivot) {
      // текущий элемент не больше опорного
      // меняем его с первым из больших
      std::swap(data[i++], data[j]);
    }
    ++j;
  }
  if (i != right - 1) {  // ставим опорный элемент на место
    std::swap(data[i], data[right - 1]);
  }
  return i;
}

// поиск к-ой порядковой статистики
template <class T>
T NthElement(std::vector<T>& data, std::size_t k) {
  std::size_t lastPivotPos = 0;
  std::size_t left = 0;
  std::size_t right = data.size();

  while (left < right) {
    if ((lastPivotPos = Partition(data, left, right)) == k)
      return data[lastPivotPos];
    else if (lastPivotPos > k) {
      // опорный элемент оказался правее искомого
      right = lastPivotPos;
    } else {
      // опорный элемент не дошел до искомого
      left = lastPivotPos + 1;
    }
  }
  return data[lastPivotPos];
}