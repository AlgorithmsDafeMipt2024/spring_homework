#pragma once

// std libs:
#include <iostream>
#include <string>
#include <vector>

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

/**
 * @brief функция, которая обрезает незнач. нули float при преобр. в строку
 * @param number: число типа float
 * @return std::string: итоговое число, записанное в строку
 */
std::string ErasedZerosStr(float number) {
  std::string str = std::to_string(number);

  // удаляем незначащие нули
  str.erase(str.find_last_not_of('0') + 1, std::string::npos);

  // если последний символ - десятичная точка, удаляем
  if (str.back() == '.') str.pop_back();

  return str;
}