#pragma once

// std libs:
#include <iostream>
#include <stdexcept>
#include <utility>
#include <vector>

// (написал шаблонизированные функции, так как они крутые)
// (а так же потому, что не знаю, какой тип нужно использовать под целые числа)

// MEANS: функция, проверяющая вектор на отсортированность по возрастанию
// ARGS: [const vector<Type>&]: вектор элементов произвольного типа
// RETURNS: [bool]: факт отсортированности вектора
template <typename Type>
inline bool IsSorted(const std::vector<Type>& vec) {
  for (size_t i = 0; i < vec.size() - 1; i++) {
    if (vec[i + 1] < vec[i]) return false;
  }

  return true;
}

// MEANS: функция, находящая в отсорт. векторе 2 числа, в сумме дающие число
// (если такие числа найти не удаётся, возбуждает ошибку)
// (также возбуждает ошибку, если на вход подан неотсорт. вектор)
// ARGS: [const vector<Type>&]: отсорт. вектор элементов произвольного типа
// ARGS: [const Type&]: число, которое нужно представить суммой
// RETURNS: [pair<Type, Type>]: пара чисел, дающих в сумме число
template <typename Type>
inline std::pair<Type, Type> TwoElemsGivingSum(const std::vector<Type>& vec,
                                               const Type& sum) {
  if (!IsSorted(vec)) throw std::invalid_argument("Array is not sorted.");

  // MEANS: индекс, указывающий с начала вектора
  size_t fir = 0;
  // MEANS: индекс, указывающий с конца вектора
  size_t last = vec.size() - 1;

  while (fir != last) {
    if (vec[fir] + vec[last] == sum)
      return {vec[fir], vec[last]};
    else if (vec[fir] + vec[last] < sum)
      fir++;
    else if (vec[fir] + vec[last] > sum)
      last--;
  }

  // если индексы сошлись (fir == last), таких элементов в векторе нет
  throw std::logic_error("There are no two elements giving such sum.");
}

// (и да, я не хочу париться с проверкой на то,)
// (определено ли сравнение для этого типа :)
