#pragma once

#include <cmath>
#include <concepts>
#include <initializer_list>
#include <stdexcept>
#include <util.hpp>

#include "linkedlist.hpp"

template <hashable K, typename T>
class HashTable {
 public:
  HashTable()
      : array_length_{base_length_},
        hash_vector_{base_length_},
        number_of_elements_{0},
        fillness_ratio_{0},
        default_value_{} {}
  explicit HashTable(T default_value)
      : array_length_{base_length_},
        hash_vector_{base_length_},
        number_of_elements_{0},
        fillness_ratio_{0},
        default_value_{default_value} {}
  HashTable(std::initializer_list<std::pair<K, T>> initializer_list);

  void SetDefault(T default_value);

  std::vector<std::pair<K, T>> Items();
  std::vector<K> Keys();
  std::vector<T> Values();

  T& operator[](const K& key);
  T& Pop(K key);
  bool HasKey(K key);

  void Clear();
  void Print();

 private:
  enum rehash_type { up = 1, down = 2 };
  void Rehash(rehash_type type);

  std::vector<LinkedList<std::pair<K, T>>> hash_vector_{base_length_};
  std::hash<K> hasher_;
  size_t array_length_;
  size_t number_of_elements_;
  double fillness_ratio_;
  T default_value_{};

  constexpr static double critical_ratio_ = 0.95;
  constexpr static size_t base_length_ = 8;
};

template <hashable K, typename T>
HashTable<K, T>::HashTable(
    std::initializer_list<std::pair<K, T>> initializer_list) {
  double relative_length = initializer_list.size() / (double)base_length_;
  number_of_elements_ = 0;
  if (initializer_list.size() <= 8)
    array_length_ = base_length_;
  else
    array_length_ =
        base_length_ * std::pow(2, std::ceil(std::log2(relative_length)));

  hash_vector_ = {};
  hash_vector_.resize(array_length_);
  default_value_ = {};

  for (const std::pair<K, T>* i = initializer_list.begin();
       i < initializer_list.end(); i++) {
    std::pair<K, T>* key_value = const_cast<std::pair<K, T>*>(i);
    K& key = key_value->first;
    T& value = key_value->second;
    LinkedList<std::pair<K, T>>& key_list =
        hash_vector_[hasher_(key) % array_length_];

    bool exist_flag = false;
    for (size_t i = 0; i < key_list.size(); i++) {
      if (key_list[i].first == key) {
        exist_flag = true;
        break;
      }
    }

    if (!exist_flag) {
      key_list.push_back({key, value});
      number_of_elements_++;
    } else
      throw std::runtime_error("inserted two pairs with the same key");
  }
  fillness_ratio_ = number_of_elements_ / (double)array_length_;
}

template <hashable K, typename T>
void HashTable<K, T>::SetDefault(T default_value) {
  default_value_ = default_value;
}

template <hashable K, typename T>
T& HashTable<K, T>::operator[](const K& key) {
  LinkedList<std::pair<K, T>>& key_list =
      hash_vector_[(hasher_(key)) % array_length_];

  if (key_list.Empty()) {
    key_list.PushBack({key, default_value_});

    number_of_elements_++;
    fillness_ratio_ = number_of_elements_ / (double)array_length_;

    if (fillness_ratio_ > critical_ratio_) {
      Rehash(rehash_type::up);
      return (*this)[key];
    }

    return key_list[0].second;
  } else {
    for (size_t i = 0; i < key_list.Size(); i++) {
      if (key_list[i].first == key) return key_list[i].second;
    }

    key_list.PushBack({key, default_value_});

    number_of_elements_++;
    fillness_ratio_ = number_of_elements_ / (double)array_length_;

    if (fillness_ratio_ > critical_ratio_) {
      Rehash(rehash_type::up);
      return (*this)[key];
    }

    return key_list.Back().second;
  }
}

template <hashable K, typename T>
T& HashTable<K, T>::Pop(K key) {
  LinkedList<std::pair<K, T>>& key_list =
      hash_vector_[(hasher_(key)) % array_length_];
  for (size_t i = 0; i < key_list.Size(); i++) {
    if (key_list[i].first == key) {
      T& value = key_list.Pop(i).second;
      number_of_elements_--;
      fillness_ratio_ = number_of_elements_ / (double)array_length_;
      if (fillness_ratio_ < critical_ratio_ / 4) Rehash(rehash_type::down);
      return value;
    }
  }
  throw std::runtime_error("out_of_range");
}

template <hashable K, typename T>
bool HashTable<K, T>::HasKey(K key) {
  LinkedList<std::pair<K, T>>& key_list =
      hash_vector_[hasher_(key) % array_length_];
  for (size_t i = 0; i < key_list.Size(); i++)
    if (key_list[i].first == key) return true;
  return false;
}

template <hashable K, typename T>
void HashTable<K, T>::Print() {
  for (size_t i = 0; i < hash_vector_.size(); i++) {
    for (size_t j = 0; j < hash_vector_[i].Size(); j++) {
      std::cout << hash_vector_[i][j].second << ' ';
    }
    std::cout << '\n';
  }
}

template <hashable K, typename T>
std::vector<std::pair<K, T>> HashTable<K, T>::Items() {
  std::vector<std::pair<K, T>> vector;

  for (size_t i = 0; i < hash_vector_.size(); i++)
    for (size_t j = 0; j < hash_vector_[i].Size(); j++)
      vector.push_back(hash_vector_[i][j]);

  return vector;
}

template <hashable K, typename T>
std::vector<K> HashTable<K, T>::Keys() {
  std::vector<K> vector;

  for (size_t i = 0; i < hash_vector_.size(); i++)
    for (size_t j = 0; j < hash_vector_[i].Size(); j++)
      vector.push_back(hash_vector_[i][j].first);

  return vector;
}

template <hashable K, typename T>
std::vector<T> HashTable<K, T>::Values() {
  std::vector<T> vector;

  for (size_t i = 0; i < hash_vector_.size(); i++)
    for (size_t j = 0; j < hash_vector_[i].Size(); j++)
      vector.push_back(hash_vector_[i][j].second);

  return vector;
}

template <hashable K, typename T>
void HashTable<K, T>::Clear() {
  hash_vector_.clear();
  hash_vector_.resize(base_length_);
  array_length_ = base_length_;

  number_of_elements_ = 0;
  fillness_ratio_ = 0;
}

template <hashable K, typename T>
void HashTable<K, T>::Rehash(rehash_type type) {
  std::vector<std::pair<K, T>> vector = Items();

  hash_vector_.clear();
  array_length_ =
      (type == rehash_type::up) ? array_length_ * 2 : array_length_ / 4;
  hash_vector_.resize(array_length_);

  for (size_t i = 0; i < vector.size(); i++) {
    K& key = vector[i].first;
    T& value = vector[i].second;
    LinkedList<std::pair<K, T>>& key_list =
        hash_vector_[hasher_(key) % array_length_];

    key_list.PushBack({key, value});
  }
  fillness_ratio_ = number_of_elements_ / (double)array_length_;
}
