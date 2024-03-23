#include "searching_sum.hpp"

#include <utility>

std::pair<int, int> SearchingSum(std::vector<int> vec, int num) {
  int start = 0;
  int end = vec.size() - 1;
  while (start < end) {
    if (vec[start] + vec[end] > num)
      --end;
    else if (vec[start] + vec[end] < num)
      ++start;
    else
      return std::make_pair(start, end);
  }
  return std::make_pair(-1, -1);
}