#pragma once

// std libs:
#include <iostream>
#include <utility>
#include <vector>

// (написал шаблонизированные функции, так как они крутые)
// (а так же потому, что не знаю, какой тип нужно использовать под целые числа)

// DOES: выводит все элементы вектора в консоль
// ARGS: [const vector<Type>&]: вектор элементов произвольного типа
template <typename Type>
inline void PrintToConsole(const std::vector<Type>& vec) {
  std::cout << "[";
  for (size_t i = 0; i < vec.size(); i++) {
    std::cout << "'" << vec[i] << "'";
    if (i != vec.size() - 1) std::cout << ", ";
  }
  std::cout << "]" << std::endl;
}

// DOES: выводит элементы пары в консоль (в формате суммы)
// ARGS: [const pair<Type,Type>&]: пара элементов произвольного типа
template <typename Type>
inline void PrintToConsole(const std::pair<Type, Type>& par) {
  std::cout << par.first << " + " << par.second << std::endl;
}

// DOES: перезаписывает целое число из консоли (модифицируя его)
// ARGS: [Type& numb]: целое число произвольного типа
// (несколько типов могут описать целое число: short, int, long и т.д.)
template <typename Type>
inline void ReadNumberFromConsole(Type& numb) {
  std::cout << "Enter number: ";
  std::cin >> numb;
  if (!std::cin) {
    std::cerr << "Invalid number input." << std::endl;
    return;
  }
}

// DOES: перезаписывает элементы вектора из консоли (модифицируя его)
// ARGS: [vector<Type>&]: вектор элементов произвольного типа
template <typename Type>
inline void ReadFromConsole(std::vector<Type>& vec) {
  // MEANS: размер вектора
  long size = 0;

  std::cout << "Enter array size: ";
  while (size <= 0) {
    std::cin >> size;
    if (!std::cin) {
      std::cerr << "Invalid size input." << std::endl;
      return;
    }
    if (size <= 0) std::cout << "Invalid size input. Try again: ";
  }

  // MEANS: текущий элемент
  Type curr;

  vec.clear();  // (для перезаписи нужна отчистка)
  std::cout << "Enter array elements: ";
  for (size_t i = 0; i < size_t(size); i++) {
    std::cin >> curr;
    if (!std::cin) {
      std::cerr << "Invalid array input. The entry is incorrect." << std::endl;
      return;
    }
    vec.push_back(curr);
  }
}

// (и да, я не хочу париться с проверкой на то,)
// (определен ли вывод в поток для этого типа :)