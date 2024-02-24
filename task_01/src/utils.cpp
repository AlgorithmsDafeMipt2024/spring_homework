#include "utils.hpp"

#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <utility>
#include <vector>

std::pair<int, int> FindSummands(const std::vector<int> array, int number) {
  int first_index = 0;
  int second_index = array.size() - 1;

  while (first_index < second_index) {
    int first_summand = array[first_index];
    int second_summand = array[second_index];
    int sum = first_summand + second_summand;
    if (sum == number)
      return std::pair<int, int>{first_summand, second_summand};
    if (sum < number) first_index++;
    if (sum > number) second_index--;
  }
  throw NoAnswer("Unable to find the right elements");
}
