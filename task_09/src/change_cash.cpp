#include "change_cash.hpp"

#include <algorithm>
#include <limits>

unsigned int min_change_count(std::vector<unsigned int> coins,
                              unsigned int amount) {
  unsigned int inf = std::numeric_limits<unsigned int>::max();

  std::vector<unsigned int> money(amount + 1, inf);
  money[0] = 0;

  for (unsigned int summ = 1; summ <= amount; summ++) {
    for (unsigned int coin : coins) {
      if (coin <= summ and money[summ - coin] != inf) {
        money[summ] = std::min(money[summ], money[summ - coin] + 1);
      }
    }
  }
  if (money[amount] == inf) {
    return -1;
  }
  return money[amount];
}