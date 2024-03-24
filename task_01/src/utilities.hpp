#pragma once

// std libs:
#include <iostream>
#include <utility>
#include <vector>

// (написал шаблонизированные функции, так как они крутые)
// (а так же потому, что не знаю, какой тип нужно использовать под целые числа)

// MEANS: перегрузка, которая выводит все элементы вектора в поток
// ARGS: [ostream&]: ссылка на поток, в который надо вывести (мод.)
// ARGS: [const vector<Type>&]: вектор элементов произвольного типа
// RETURNS: [ostream&]: ссылка на поток, в который вывели
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

// MEANS: перегрузка, которая выводит элементы пары в поток (в формате суммы)
// ARGS: [ostream&]: ссылка на поток, в который надо вывести (мод.)
// ARGS: [const pair<Type,Type>&]: пара элементов произвольного типа
// RETURNS: [ostream&]: ссылка на поток, в который вывели
template <typename Type>
inline std::ostream& operator<<(std::ostream& os,
                                const std::pair<Type, Type>& par) {
  return os << par.first << " + " << par.second;
}

// MEANS: перегрузка, которая вводит все элементы вектора из потока
// (работает исключительно с консолью, так как
// (вывод о текущем состоянии происходит туда)
// ARGS: [istream&]: ссылка на поток, из которого надо ввести (мод.)
// ARGS: [vector<Type>&]: вектор элементов произвольного типа (мод.)
// RETURNS: [istream&]: ссылка на поток, из которого ввели
template <typename Type>
inline std::istream& operator>>(std::istream& is, std::vector<Type>& vec) {
  // MEANS: размер вектора
  long size = 0;

  std::cout << "Enter array size: ";
  while (size <= 0) {
    is >> size;
    if (!is) {
      std::cerr << "Invalid size input." << std::endl;
      return is;
    }
    if (size <= 0) std::cout << "Invalid size input. Try again: ";
  }

  // MEANS: текущий элемент
  Type curr;

  vec.clear();  // (для перезаписи нужна отчистка)
  std::cout << "Enter array elements: ";
  for (size_t i = 0; i < size_t(size); i++) {
    is >> curr;
    if (!is) {
      std::cerr << "Invalid array input. The entry is incorrect." << std::endl;
      return is;
    }
    vec.push_back(curr);
  }

  return is;
}

// (и да, я не хочу париться с проверкой на то,)
// (определен ли вывод в поток для этого типа :)