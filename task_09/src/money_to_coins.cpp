#include "money_to_coins.hpp"

size_t MoneyToCoins(size_t money, std::vector<size_t> coins) {
  if (coins.empty()) throw std::runtime_error("there is no coins");
  std::vector<size_t> table(money + 1, std::numeric_limits<size_t>::max());
  table[0] = 0;
  for (size_t i = 1; i <= money; ++i)
    for (size_t j : coins)
      if (j <= i) table[i] = std::min(table[i], table[i - j] + 1);
  return table[money];
}