#include "min_amount_of_coins.hpp"
#include <stdexcept>

unsigned MinAmountOfCoins(std::vector<unsigned>& coins, unsigned amount) {
  std::vector<unsigned> amounts(amount + 1, amount + 1);
  amounts[0] = 0;

  for (size_t i = 1; i <= amount; ++i)
    for (auto& coin : coins)
      if (coin <= i) amounts[i] = std::min(amounts[i], amounts[i - coin] + 1);
  
  if (amounts[amount] > amount) throw std::logic_error("Impossible to collect amount from this set of coins!");
  return amounts[amount];
}