#include "utils.hpp"
#include <iostream>
#include <stdexcept>
#include <vector>

std::pair<int, int> Func(int number, const std::vector<int> array) {
  int left_ind = 0, right_ind = array.size() - 1;
  while (left_ind < right_ind) {
    int sum = array[left_ind] + array[right_ind];
    if (sum == number) {
      return std::pair<int, int>{array[left_ind], array[right_ind]};
    }
    if (sum < number) {
      left_ind++;
    } 
    else {
      right_ind--;
    }
  }
  if (array[left_ind] + array[right_ind] != number) {
    throw std::logic_error("");
  }
}