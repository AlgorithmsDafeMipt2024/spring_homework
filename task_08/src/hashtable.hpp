#include <cmath>
#include <initializer_list>
#include <stdexcept>

#include "linkedlist.hpp"

template <typename K, typename T>
class hash_table {
 public:
  hash_table()
      : array_length{base_length},
        hash_vector{base_length},
        number_of_elements{0},
        fillness_ratio{0},
        default_value{} {}
  explicit hash_table(T default_value_)
      : array_length{base_length},
        hash_vector{base_length},
        number_of_elements{0},
        fillness_ratio{0},
        default_value{default_value_} {}
  hash_table(std::initializer_list<std::pair<K, T>> initializer_list);

  // hash_table(const hash_table& ht);
  // hash_table& operator=(const hash_table& ht);
  void set_default(T default_value_);

  std::vector<std::pair<K, T>> items();
  std::vector<K> keys();
  std::vector<T> values();

  T& operator[](K key);
  T& pop(K key);
  bool has_key(K key);

  void clear();
  void print();

 private:
  enum rehash_type { up = 1, down = 2 };
  void rehash(rehash_type type);

  std::vector<LinkedList<std::pair<K, T>>> hash_vector{base_length};
  std::hash<K> hasher;
  size_t array_length;
  size_t number_of_elements;
  double fillness_ratio;
  T default_value{};

  constexpr static double critical_ratio = 0.95;
  constexpr static size_t base_length = 8;
};

template <typename K, typename T>
hash_table<K, T>::hash_table(
    std::initializer_list<std::pair<K, T>> initializer_list) {
  double relative_length = initializer_list.size() / (double)base_length;
  number_of_elements = 0;
  if (initializer_list.size() <= 8)
    array_length = base_length;
  else
    array_length =
        base_length * std::pow(2, std::ceil(std::log2(relative_length)));

  hash_vector = {};
  hash_vector.resize(array_length);
  default_value = {};

  for (const std::pair<K, T>* i = initializer_list.begin();
       i < initializer_list.end(); i++) {
    std::pair<K, T>* key_value = const_cast<std::pair<K, T>*>(i);
    K& key = key_value->first;
    T& value = key_value->second;
    LinkedList<std::pair<K, T>>& key_list =
        hash_vector[hasher(key) % array_length];

    bool exist_flag = false;
    for (size_t i = 0; i < key_list.size(); i++) {
      if (key_list[i].first == key) {
        exist_flag = true;
        break;
      }
    }

    if (!exist_flag) {
      key_list.push_back({key, value});
      number_of_elements++;
    } else
      throw std::runtime_error("inserted two pairs with the same key");
  }
  fillness_ratio = number_of_elements / (double)array_length;
}

/*
template <typename K, typename T>
hash_table<K, T>::hash_table(const hash_table& ht) {
  array_length = ht.array_length;
  number_of_elements = ht.number_of_elements;
  fillness_ratio = ht.fillness_ratio;
  hasher = ht.hasher;
  hash_vector = ht.hash_vector;
  // for (int i = 0; i < int(ht.hash_vector.size()); i++) {
  //  hash_vector.push_back(ht.hash_vector[i]);
  //}
}
*/

/*
template <typename K, typename T>
hash_table<K, T>& hash_table<K, T>::operator=(const hash_table& ht) {
  array_length = ht.array_length;
  number_of_elements = ht.number_of_elements;
  fillness_ratio = ht.fillness_ratio;
  hasher = ht.hasher;
  hash_vector = ht.hash_vector;
  return *this;
}
*/

template <typename K, typename T>
void hash_table<K, T>::set_default(T default_value_) {
  default_value = default_value_;
}

// totally can be more effective
template <typename K, typename T>
T& hash_table<K, T>::operator[](K key) {
  LinkedList<std::pair<K, T>>& key_list =
      hash_vector[(hasher(key)) % array_length];

  if (key_list.empty()) {
    key_list.push_back({key, default_value});

    number_of_elements++;
    fillness_ratio = number_of_elements / (double)array_length;

    if (fillness_ratio > critical_ratio) {
      rehash(rehash_type::up);
      return (*this)[key];
    }

    return key_list[0].second;
  } else {
    for (size_t i = 0; i < key_list.size(); i++) {
      if (key_list[i].first == key) return key_list[i].second;
    }

    key_list.push_back({key, default_value});

    number_of_elements++;
    fillness_ratio = number_of_elements / (double)array_length;

    if (fillness_ratio > critical_ratio) {
      rehash(rehash_type::up);
      return (*this)[key];
    }

    return key_list.back().second;
  }
}

// could be more effective
template <typename K, typename T>
T& hash_table<K, T>::pop(K key) {
  LinkedList<std::pair<K, T>>& key_list =
      hash_vector[(hasher(key)) % array_length];
  for (size_t i = 0; i < key_list.size(); i++) {
    if (key_list[i].first == key) {
      T& value = key_list.pop(i).second;
      number_of_elements--;
      fillness_ratio = number_of_elements / (double)array_length;
      if (fillness_ratio < critical_ratio / 4) rehash(rehash_type::down);
      return value;
    }
  }
  throw std::runtime_error("deleting a key that doesn't exist");
}

template <typename K, typename T>
bool hash_table<K, T>::has_key(K key) {
  LinkedList<std::pair<K, T>>& key_list =
      hash_vector[hasher(key) % array_length];
  for (size_t i = 0; i < key_list.size(); i++)
    if (key_list[i].first == key) return true;
  return false;
}

// could be more effective
template <typename K, typename T>
void hash_table<K, T>::print() {
  for (size_t i = 0; i < hash_vector.size(); i++) {
    for (size_t j = 0; j < hash_vector[i].size(); j++) {
      std::cout << hash_vector[i][j].second << ' ';
    }
    std::cout << '\n';
  }
}

// could be more effective
template <typename K, typename T>
std::vector<std::pair<K, T>> hash_table<K, T>::items() {
  std::vector<std::pair<K, T>> vector;

  for (size_t i = 0; i < hash_vector.size(); i++)
    for (size_t j = 0; j < hash_vector[i].size(); j++)
      vector.push_back(hash_vector[i][j]);

  return vector;
}

// could be more effective
template <typename K, typename T>
std::vector<K> hash_table<K, T>::keys() {
  std::vector<K> vector;

  for (size_t i = 0; i < hash_vector.size(); i++)
    for (size_t j = 0; j < hash_vector[i].size(); j++)
      vector.push_back(hash_vector[i][j].first);

  return vector;
}

// could be more effective
template <typename K, typename T>
std::vector<T> hash_table<K, T>::values() {
  std::vector<T> vector;

  for (size_t i = 0; i < hash_vector.size(); i++)
    for (size_t j = 0; j < hash_vector[i].size(); j++)
      vector.push_back(hash_vector[i][j].second);

  return vector;
}

template <typename K, typename T>
void hash_table<K, T>::clear() {
  hash_vector.clear();
  hash_vector.resize(base_length);
  array_length = base_length;

  number_of_elements = 0;
  fillness_ratio = 0;
}

template <typename K, typename T>
void hash_table<K, T>::rehash(rehash_type type) {
  std::vector<std::pair<K, T>> vector = items();

  hash_vector.clear();
  array_length =
      (type == rehash_type::up) ? array_length * 2 : array_length / 4;
  hash_vector.resize(array_length);

  for (size_t i = 0; i < vector.size(); i++) {
    K& key = vector[i].first;
    T& value = vector[i].second;
    LinkedList<std::pair<K, T>>& key_list =
        hash_vector[hasher(key) % array_length];

    key_list.push_back({key, value});
  }
  fillness_ratio = number_of_elements / (double)array_length;
}
