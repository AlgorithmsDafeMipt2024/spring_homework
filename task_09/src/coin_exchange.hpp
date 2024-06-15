#include <algorithm>
#include <cstddef>
#include <stdexcept>
#include <vector>

long long CoinExchange(long long coin_sum, std::vector<size_t> nominals) {
  if (coin_sum == 0) return 0;
  if (coin_sum < 0) return -1;
  if (nominals.empty()) return -1;
  std::sort(nominals.begin(), nominals.end());
  std::vector<int> dp(coin_sum + 1);

  for (int current_coin_sum = 0; current_coin_sum < coin_sum + 1;
       current_coin_sum++)
    dp[current_coin_sum] = 0;

  for (int current_coin_sum = 1; current_coin_sum < dp.size();
       current_coin_sum++) {
    for (int coin_index = nominals.size() - 1; coin_index >= 0; coin_index--) {
      if (current_coin_sum - nominals[coin_index] == 0)
        dp[current_coin_sum] = 1;
      else if (current_coin_sum - nominals[coin_index] > 0 &&
               dp[current_coin_sum - nominals[coin_index]] != 0) {
        if (dp[current_coin_sum] == 0)
          dp[current_coin_sum] =
              dp[current_coin_sum - nominals[coin_index]] + 1;
        else
          dp[current_coin_sum] =
              std::min(dp[current_coin_sum],
                       dp[current_coin_sum - nominals[coin_index]] + 1);
      }
    }
  }
  // return -1 if there is no solution
  return dp[coin_sum] == 0 ? -1 : dp[coin_sum];
}