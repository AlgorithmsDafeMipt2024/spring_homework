#pragma once

#include <limits>
#include <stdexcept>
#include <vector>

/// @brief Определяет наименьшее количество монет из coins, чтобы набрать sum
size_t MinAmountOfCoins(size_t sum, std::vector<size_t> coins);