#pragma once
#include <concepts>

template <typename CustomClass>
concept constructable = requires(CustomClass a, CustomClass b) {
  a = CustomClass{};
  b = CustomClass{a};
};