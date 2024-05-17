#include <algorithm>
#include <cstddef>
#include <stdexcept>
#include <vector>

long long CoinChange(long long amount, std::vector<size_t> coins) {
  if (amount == 0) return 0;
  if (amount < 0) return -1;
  if (coins.empty()) return -1;
  std::sort(coins.begin(), coins.end());
  std::vector<int> dp(amount + 1);

  for (int current_amount = 0; current_amount < amount + 1; current_amount++)
    dp[current_amount] = 0;

  for (int current_amount = 1; current_amount < dp.size(); current_amount++) {
    for (int coin_index = coins.size() - 1; coin_index >= 0; coin_index--) {
      if (current_amount - coins[coin_index] == 0)
        dp[current_amount] = 1;
      else if (current_amount - coins[coin_index] > 0 &&
               dp[current_amount - coins[coin_index]] != 0) {
        if (dp[current_amount] == 0)
          dp[current_amount] = dp[current_amount - coins[coin_index]] + 1;
        else
          dp[current_amount] = std::min(
              dp[current_amount], dp[current_amount - coins[coin_index]] + 1);
      }
    }
  }
  // return -1 if it's impossible to get this amount with given coins
  return dp[amount] == 0 ? -1 : dp[amount];
}