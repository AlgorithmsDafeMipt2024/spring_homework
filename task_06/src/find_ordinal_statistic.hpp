#include <stdexcept>
#include <vector>
using namespace std;

template <typename T>
T FindOrdinalStatistic(vector<T> data, size_t n) {
  if (data.empty()) throw logic_error("An array is empty!");
  if (n > data.size() || n <= 0)
    throw logic_error("Incorrect ordinal statistic!");

  if (data.size() == 1) return data[0];

  size_t p = rand() % data.size();
  T pivot = data[p];
  data.erase(data.begin() + p);
  // Левая часть содержит элементы, которые меньше pivot'а, а правая -
  // которые больше
  vector<T> left_part{pivot}, right_part;

  for (auto elem : data) {
    if (elem < pivot)
      left_part.push_back(elem);
    else if (elem > pivot)
      right_part.push_back(elem);
    // Мы не добавляем дубликаты, а просто уменьшаем порядковую статистику
    else if (n != 1)
      n--;
  }

  if (n <= left_part.size())
    return FindOrdinalStatistic(left_part, n);
  else
    return FindOrdinalStatistic(right_part, n - left_part.size());
}