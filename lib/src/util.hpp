#include <concepts>
#include <iostream>

// check if type comparasion operators are defined for a class
template <typename CustomType>
concept comparable = requires(CustomType a, CustomType b) {
  a < b;
  a <= b;
  a == b;
  a >= b;
  a > b;
  a != b;
};

// concept to check if the type has basic and copy constructor
template <typename CustomType>
concept constructable = requires(CustomType a, CustomType b) {
  a = CustomType{};
  b = CustomType{a};
};

// concept to check if the type is comparable with a concrete function
template <typename Function, typename CustomType>
concept comparing = requires(CustomType a, CustomType b, Function f) {
  f(a, b);
};

// concept to check if the type is printable
template <typename CustomType>
concept printable = requires(CustomType a) {
  std::cout << a;
};

// concept to check if the type has a hash function tied to it
template <typename K>
concept hashable = requires(K a) {
  { std::hash<K>{}(a) } -> std::convertible_to<std::size_t>;
};