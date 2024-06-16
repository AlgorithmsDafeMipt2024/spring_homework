#pragma once
#include <vector>

class HashTable {
 public:
  HashTable() : size{0}, cells{0}, buf_size{8} {
    data = std::vector<std::size_t>(buf_size);
    cell_states = std::vector<State>(buf_size, State::Vacant);
  }

  /// @brief Проверяет наличие значение в хэш-таблице
  /// @param value: Значение
  /// @return Результат проверки
  bool Contains(std::size_t value);

  /// @brief Добавляет значение в хэш-таблицу
  /// @param value: Значение
  void Insert(std::size_t value);

  /// @brief Удаляет значение из хэш-таблицы
  /// @param value: Значение
  void Remove(std::size_t value);

  /// @brief Очищает хэш-таблицу
  void Clear();

  std::size_t Size() { return size; }

 private:
  constexpr static const double hash_coef = 0.618033989;
  constexpr static const double rehash_coef = 0.7;

  enum class State { Occupied, Deleted, Vacant };

  std::size_t buf_size;
  std::size_t size;
  std::size_t cells;

  std::vector<std::size_t> data;
  std::vector<State> cell_states;

  std::size_t FirstHashFunc(std::size_t key);
  std::size_t SecondHashFunc(std::size_t key);

  /// @brief Меняет размер
  void Resize();

  /// @brief Рехэш
  void Rehash();
};