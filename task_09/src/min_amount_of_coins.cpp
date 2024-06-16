#include "min_amount_of_coins.h"

size_t MinAmountOfCoins(size_t sum, std::vector<size_t> coins) {
  if (coins.empty()) throw std::runtime_error("there is no coins");
  std::vector<size_t> table(sum + 1, std::numeric_limits<size_t>::max());
  table[0] = 0;
  for (size_t i = 1; i <= sum; ++i)
    for (const size_t j : coins)
      if (j <= i) table[i] = std::min(table[i], table[i - j] + 1);
  return table[sum];
}