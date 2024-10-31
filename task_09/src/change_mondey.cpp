#include <vector>

#include "change_money.hpp"

int CoinExchange(int sum, std::vector<int> coins) {
  std::vector<int> money(sum + 1, 1e9);
  money[0] = 0;
  for (int m = 1; m <= sum; m++) {
    for (auto coin : coins) {
      if (coin <= m) {
        money[m] = std::min(money[m], money[m - coin] + 1);
      }
    }
  }
  if (money[sum] == 1e9) return -1;

  return money[sum];
}