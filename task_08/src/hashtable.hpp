#include <stdexcept>

#include "linkedlist.hpp"

constexpr double critical_ratio = 0.95;

enum rehash_type { up = 1, down = 2 };

template <typename K, typename T>
class hash_table {
 public:
  hash_table()
      : array_length{8},
        hash_vector{8},
        number_of_elements{0},
        fillness_ratio{0} {}
  hash_table(int n)
      : array_length{n},
        hash_vector{n},
        number_of_elements{0},
        fillness_ratio{0} {}
  // hash_table(const hash_table& ht);
  // hash_table& operator=(const hash_table& ht);
  T& operator[](K key);
  T& pop(K key);
  void print();

 private:
  std::vector<std::pair<K, T>> transform();
  void rehash(rehash_type type);

  std::vector<LinkedList<std::pair<K, T>>> hash_vector;
  std::hash<K> hasher;
  int array_length;
  int number_of_elements;
  double fillness_ratio;
};

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
T& hash_table<K, T>::operator[](K key) {
  LinkedList<std::pair<K, T>>& key_list =
      hash_vector[(hasher(key)) % array_length];

  if (key_list.empty()) {
    key_list.push_back({key, {}});

    number_of_elements++;
    fillness_ratio = number_of_elements / (double)array_length;

    if (fillness_ratio > critical_ratio) {
      rehash(rehash_type::up);
      return (*this)[key];
    }

    return key_list[0].second;
  } else {
    for (int i = 0; i < key_list.size(); i++) {
      if (key_list[i].first == key) return key_list[i].second;
    }

    key_list.push_back({key, {}});

    number_of_elements++;
    fillness_ratio = number_of_elements / (double)array_length;

    if (fillness_ratio > critical_ratio) {
      rehash(rehash_type::up);
      return (*this)[key];
    }

    return key_list.back().second;
  }
}

template <typename K, typename T>
T& hash_table<K, T>::pop(K key) {
  LinkedList<std::pair<K, T>>& key_list =
      hash_vector[(hasher(key)) % array_length];
  if (key_list.empty())
    throw std::runtime_error("deleting a key that doesn't exist");
  for (int i = 0; i < key_list.size(); i++) {
    if (key_list[i].first == key) {
      T& value = key_list.pop(i).second;
      number_of_elements--;
      fillness_ratio = number_of_elements / (double)array_length;
      if (fillness_ratio < critical_ratio / 4) rehash(rehash_type::down);
      return value;
    }
  }
}

template <typename K, typename T>
void hash_table<K, T>::print() {
  for (int i = 0; i < int(hash_vector.size()); i++) {
    for (int j = 0; j < int(hash_vector[i].size()); j++) {
      std::cout << hash_vector[i][j].second << ' ';
    }
    std::cout << '\n';
  }
}

template <typename K, typename T>
std::vector<std::pair<K, T>> hash_table<K, T>::transform() {
  std::vector<std::pair<K, T>> vector{};

  for (int i = 0; i < int(hash_vector.size()); i++)
    for (int j = 0; j < hash_vector[i].size(); j++)
      vector.push_back(hash_vector[i][j]);

  return vector;
}

template <typename K, typename T>
void hash_table<K, T>::rehash(rehash_type type) {
  std::vector<std::pair<K, T>> vector = transform();

  hash_vector.clear();
  if (type == rehash_type::up)
    array_length *= 2;
  else
    array_length /= 4;
  hash_vector.resize(array_length);

  for (int i = 0; i < int(vector.size()); i++) {
    K& key = vector[i].first;
    T& value = vector[i].second;
    LinkedList<std::pair<K, T>>& key_list =
        hash_vector[hasher(key) % array_length];

    key_list.push_back({key, value});
  }
  fillness_ratio = number_of_elements / (double)array_length;
}
