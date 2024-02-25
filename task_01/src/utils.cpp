#include "utils.hpp"
#include <iostream>
#include <stdexcept>
#include <vector>

std::pair<int, int> FindSum(int number, const std::vector<int> array) {
  if (array.size() < 2){
    throw SmallVector("");
  }
  int left_index = 0;
  int right_index = array.size() - 1;
  while (left_index < right_index) {
    int sum = array[left_index] + array[right_index];
    if (sum == number) {
      return std::pair<int, int>{array[left_index], array[right_index]};
    }
    if (sum < number) {
      left_index++;
    } 
    else {
      right_index--;
    }
  }
  if (array[left_index] + array[right_index] != number) {
    throw std::logic_error("");
  }
}