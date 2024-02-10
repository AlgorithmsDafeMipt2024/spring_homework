#include "utils.hpp"

#include <cstddef>
#include <utility>

std::pair<int, int> FindSummands(const std::vector<int> array, int number) {
  int ptr_1 = 0;
  int ptr_2 = array.size() - 1;

  while (ptr_1 < ptr_2) {
    int summand_1 = array[ptr_1];
    int summand_2 = array[ptr_2];
    int sum = summand_1 + summand_2;
    if (sum == number) return std::pair<int, int>{summand_1, summand_2};
    if (sum < number) ptr_1++;
    if (sum > number) ptr_2--;
  }
  return std::pair<int, int>{NULL, NULL};
}