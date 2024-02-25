#include "utils.hpp"
#include <iostream>
#include <utility>
#include <vector>

std::pair<int, int> Task1(int num, const std::vector<int> arr) {
  if (arr.size() < 2) {
    throw WrongVector("");
  }
  for (int i = 0, j = arr.size() - 1; i < j;) {
    auto sum = arr[i] + arr[j];
    if (sum < num)
      ++i;
    else if (sum > num)
      --j;
    else if (sum == num) {
      return std::pair<int, int>{arr[i], arr[j]};
    }
  }
  throw std::logic_error("");
}