#pragma once
#include <concepts>

template <typename CustomClass>
concept comparable = requires(CustomClass a, CustomClass b) {
  a < b;
  a <= b;
  a == b;
  a >= b;
  a > b;
  a != b;
};