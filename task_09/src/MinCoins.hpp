#include <iostream>
#include <vector>

int MinCoins(std::vector<int> coins, int amount) {
  std::vector<int> dp(amount + 1, amount + 1);
  dp[0] = 0;

  for (int i = 1; i <= amount; ++i) {
    for (int coin : coins) {
      if (i - coin >= 0) {
        dp[i] = std::min(dp[i], dp[i - coin] + 1);
      }
    }
  }

  if (dp[amount] == amount + 1)
    return -1;
  else
    return dp[amount];
}