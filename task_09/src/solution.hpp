#include <algorithm>
#include <cstddef>
#include <stdexcept>
#include <vector>

long long coin_change(long long amount, std::vector<size_t> coins) {
  if (amount == 0) return 0;
  if (amount < 0) return -1;
  if (coins.empty()) return -1;
  std::sort(coins.begin(), coins.end());
  std::vector<int> dp(amount + 1);

  for (int i = 0; i < amount + 1; i++) dp[i] = 0;

  for (int i = 1; i < dp.size(); i++) {
    for (int j = coins.size() - 1; j >= 0; j--) {
      if (i - coins[j] == 0)
        dp[i] = 1;
      else if (i - coins[j] > 0 && dp[i - coins[j]] != 0) {
        if (dp[i] == 0)
          dp[i] = dp[i - coins[j]] + 1;
        else
          dp[i] = std::min(dp[i], dp[i - coins[j]] + 1);
      }
    }
  }
  // return -1 if it's impossible to get this amount with given coins
  return dp[amount] == 0 ? -1 : dp[amount];
}