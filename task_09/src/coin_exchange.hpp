#pragma once
#include <climits>
#include <vector>

int ChangeCoins(int money_amount, const std::vector<int>& coin_denominations) {
  std::vector<int> minimal_exchanges(money_amount + 1, INT_MAX);
  minimal_exchanges[0] = 0;
  for (int cur_money_amount = 1; cur_money_amount <= money_amount;
       ++cur_money_amount) {
    for (auto coin : coin_denominations)
      if (cur_money_amount >= coin &&
          minimal_exchanges[cur_money_amount - coin] != INT_MAX)
        minimal_exchanges[cur_money_amount] =
            std::min(minimal_exchanges[cur_money_amount],
                     minimal_exchanges[cur_money_amount - coin] + 1);
  }
  return minimal_exchanges[money_amount] == INT_MAX
             ? -1
             : minimal_exchanges[money_amount];
}