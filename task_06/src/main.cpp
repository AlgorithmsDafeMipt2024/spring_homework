#include <iostream>

#include "find_n_order_statistic.hpp"

int main() {
  std::vector<size_t> arr = {5, 2, 8, 1, 9, 3, 7, 4, 6};
  size_t n = 5;
  size_t result = FindNOrderStatistic(arr, n);
  std::cout << "The " << n << "-th order statistic is: " << result << std::endl;

  std::vector<std::string> arr_2 = {"apple", "banana", "cherry", "date",
                                    "elderberry"};
  size_t k = 3;
  std::string result_2 = FindNOrderStatistic(arr_2, k);
  std::cout << "The " << k << "-th order statistic is: " << result_2
            << std::endl;

  return 0;
}
