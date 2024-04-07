// std libs:
#include <iostream>

// std usings:
using std::cout, std::cin, std::endl;

#include "temperatures.hpp"

/**
 * @brief перегрузка, которая выводит все элементы вектора в поток
 * @tparam Type: тип, возможный к выводу в консоль
 * @param os: ссылка на поток, в который надо вывести (мод.)
 * @param vec: вектор элементов произвольного типа
 * @return std::ostream&: ссылка на поток, в который вывели
 */
template <typename Type>
inline std::ostream& operator<<(std::ostream& os,
                                const std::vector<Type>& vec) {
  os << "[";
  for (size_t i = 0; i < vec.size(); i++) {
    os << "'" << vec[i] << "'";
    if (i != vec.size() - 1) os << ", ";
  }
  return os << "]";
}

int main() {
  std::vector<Temperature> vec{1,  2,  3, 4,  4,  3,  2,  1, 0,
                               -1, -5, 8, 31, -9, 58, 36, 5};
  cout << vec << endl;
  cout << DaysUntilWarmingSillyLooping(vec) << endl;
}
