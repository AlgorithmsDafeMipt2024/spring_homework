#include "money.hpp"

#include <vector>

std::size_t CoinExchange(std::size_t sum, std::vector<std::size_t> coins) {
  std::vector<std::size_t> money(sum + 1, 1e9);
  money[0] = 0;
  for (std::size_t i = 1; i <= sum; i++)
    for (std::size_t j : coins)
      if (j <= i) money[i] = std::min(money[i], money[i - j] + 1);
  return money[sum];
}