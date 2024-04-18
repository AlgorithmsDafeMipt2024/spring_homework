#include "minimum_moneys.hpp"

int MinMoney(std::vector<int> vec, int money) {
  std::vector<int> table(money + 1, int(1e10));
  table[0] = 0;
  int mon = table[money];

  for (int i = 1; i <= money; ++i) {
    for (int j : vec) {
      if (j <= i) {
        table[i] = std::min(table[i], 1 + table[i - j]);
      }
    }
  }
  if (abs(table[money]) == abs(mon)) {
    return 0;
  }
  return table[money];
}