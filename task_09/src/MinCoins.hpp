#include <algorithm>
#include <iostream>
#include <vector>

int minCoins(int amount, const std::vector<int>& coins) {
  std::vector<int> dp(amount + 1, amount + 1);
  dp[0] = 0;

  for (int i = 1; i <= amount; i++) {
    for (int coin : coins) {
      if (coin <= i) {
        dp[i] = std::min(dp[i], dp[i - coin] + 1);
      }
    }
  }

  return (dp[amount] > amount) ? -1 : dp[amount];
}
