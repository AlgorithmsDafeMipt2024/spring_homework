#include "searching_sum.hpp"

/*
Алгоритм для нахождения в массиве чисел, дающих в сумме заданное число
Ассимптотика алгоритма - O(n), затраты по памяти - O(n)
*/
std::pair<int, int> SearchingSum(int sum, std::vector<int> arr) {
  std::pair<int, int> ans = {0, arr.size() - 1};
  while (ans.first < ans.second) {
    if (arr[ans.first] + arr[ans.second] == sum) return ans;
    if (arr[ans.first] + arr[ans.second] < sum) ++ans.first;
    if (arr[ans.first] + arr[ans.second] > sum) --ans.second;
  }
  return {-1, -1};
}