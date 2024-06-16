#include "utils.h"

std::pair<int, int> Task1(int number, std::vector<int> array_of_numbers) {
  int i = 0;
  int j = array_of_numbers.size() - 1;
  while (array_of_numbers[i] + array_of_numbers[j] != number) {
    if (array_of_numbers[i] + array_of_numbers[j] < number) i++;
    if (array_of_numbers[i] + array_of_numbers[j] > number) j--;
  }
  return {array_of_numbers[i], array_of_numbers[j]};
}