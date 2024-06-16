#pragma once
#include <algorithm>
#include <concepts>

template <typename CustomClass>
concept fullfilled = requires(CustomClass a, CustomClass b) {
  a = CustomClass{};
  b = CustomClass{a};
  b = std::move(a);
  b = a;
  ~b();
};