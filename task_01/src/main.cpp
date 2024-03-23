#include <iostream>

#include "searching_sum.hpp"

/*
Формат ввода:
  В первой строке ввода через пробел подаётся 2 целых числа:
    sum - заданное число, n - длина массива чисел
  В следующей строке подаются n целых чисел - элемента массива

Формат вывода:
  В одной строке через пробел выводятся два числа - индексы элементов данного
  массива, дающие в сумме sum
*/
int main() {
  int sum = 0, n = 0;
  std::cin >> sum >> n;
  std::vector<int> arr(n);
  for (int i = 0; i < n; ++i) std::cin >> arr[i];
  std::pair<int, int> answer = SearchingSum(sum, arr);
  std::cout << answer.first << " " << answer.second << std::endl;
  return 0;
}
