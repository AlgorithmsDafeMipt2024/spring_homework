#include "MinimumCoinsAmount.hpp"

int MinimumCoinsAmount(int amount, std::vector<int>& coins) {
  std::vector<int> amounts(amount + 1, amount + 1);
  amounts[0] = 0;
  for (int i = 1; i <= amount; ++i)
    for (auto& coin : coins)
      if (coin <= i) amounts[i] = std::min(amounts[i], amounts[i - coin] + 1);
  return amounts[amount] > amount ? -1 : amounts[amount];
}