#include "temperature.hpp"

vector<size_t> DaysBeforeWarming(vector<short> temperatures) {
  vector<size_t> days(temperatures.size());

  if (temperatures.empty()) return days;

  for (size_t i = 0; i < temperatures.size() - 1; i++) {
    // Если у предыдущего дня температура больше и кол-во дней до потепления
    // больше 1, то для текущего дня можно не считать кол-во дней
    if (i > 0 && temperatures[i - 1] > temperatures[i] && days[i - 1] > 1)
      days[i] = temperatures[i - 1] - 1;
    // Иначе считаем кол-во дней по-честному
    else {
      for (size_t j = i; j < temperatures.size(); j++) {
        if (temperatures[j] > temperatures[i]) break;
        days[i]++;
      }
      // Если мы вышли из цикла без break, значит потепления не было на
      // протяжении всех дней
      if (days[i] == temperatures.size() - i) days[i] = 0;
    }
  }
  return days;
}