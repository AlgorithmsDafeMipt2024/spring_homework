#ifndef HASH_TABLE_HPP
#define HASH_TABLE_HPP
#include <string>

int HashFunctionHorner(const std::string& s, int table_size, const int key) {
  int hash_result = 0;
  for (int i = 0; s[i] != s.size(); ++i)
    hash_result = (key * hash_result + s[i]) % table_size;
  hash_result = (hash_result * 2 + 1) % table_size;
  return hash_result;
}
struct HashFunction1 {
  int operator()(const std::string& s, int table_size) const {
    return HashFunctionHorner(s, table_size, table_size - 1);
  }
};
struct HashFunction2 {
  int operator()(const std::string& s, int table_size) const {
    return HashFunctionHorner(s, table_size, table_size + 1);
  }
};

template <class T, class THash1 = HashFunction1, class THash2 = HashFunction2>
class HashTable {
 public:
  HashTable() {
    buffer_size = default_size;
    size = 0;
    size_all_non_nullptr = 0;
    arr = new Node*[buffer_size];
    for (int i = 0; i < buffer_size; ++i) arr[i] = nullptr;
  }
  ~HashTable() {
    for (int i = 0; i < buffer_size; ++i)
      if (arr[i]) delete arr[i];
    delete[] arr;
  }
  void resize() {
    int past_buffer_size = buffer_size;
    buffer_size *= 2;
    size_all_non_nullptr = 0;
    size = 0;
    Node** arr2 = new Node*[buffer_size];
    for (int i = 0; i < buffer_size; ++i) arr2[i] = nullptr;
    std::swap(arr, arr2);
    for (int i = 0; i < past_buffer_size; ++i) {
      if (arr2[i] && arr2[i]->state) add(arr2[i]->value);
    }
    for (int i = 0; i < past_buffer_size; ++i)
      if (arr2[i]) delete arr2[i];
    delete[] arr2;
  }
  void rehash() {
    size_all_non_nullptr = 0;
    size = 0;
    Node** arr2 = new Node*[buffer_size];
    for (int i = 0; i < buffer_size; ++i) arr2[i] = nullptr;
    std::swap(arr, arr2);
    for (int i = 0; i < buffer_size; ++i) {
      if (arr2[i] && arr2[i]->state) add(arr2[i]->value);
    }
    for (int i = 0; i < buffer_size; ++i)
      if (arr2[i]) delete arr2[i];
    delete[] arr2;
  }
  bool find(const T& value, const THash1& hash1 = THash1(),
            const THash2& hash2 = THash2()) {
    int h1 = hash1(value, buffer_size);
    int h2 = hash2(value, buffer_size);
    int i = 0;
    while (arr[h1] != nullptr && i < buffer_size) {
      if (arr[h1]->value == value && arr[h1]->state) return true;
      h1 = (h1 + h2) % buffer_size;
      ++i;
    }
    return false;
  }
  bool remove(const T& value, const THash1& hash1 = THash1(),
              const THash2& hash2 = THash2()) {
    int h1 = hash1(value, buffer_size);
    int h2 = hash2(value, buffer_size);
    int i = 0;
    while (arr[h1] != nullptr && i < buffer_size) {
      if (arr[h1]->value == value && arr[h1]->state) {
        arr[h1]->state = false;
        --size;
        return true;
      }
      h1 = (h1 + h2) % buffer_size;
      ++i;
    }
    return false;
  }
  bool add(const T& value, const THash1& hash1 = THash1(),
           const THash2& hash2 = THash2()) {
    if (size + 1 > int(rehash_size * buffer_size))
      resize();
    else if (size_all_non_nullptr > 2 * size)
      rehash();
    int h1 = hash1(value, buffer_size);
    int h2 = hash2(value, buffer_size);
    int i = 0;
    int first_deleted = -1;
    while (arr[h1] != nullptr && i < buffer_size) {
      if (arr[h1]->value == value && arr[h1]->state) return false;
      if (!arr[h1]->state && first_deleted == -1) first_deleted = h1;
      h1 = (h1 + h2) % buffer_size;
      ++i;
    }
    if (first_deleted == -1) {
      arr[h1] = new Node(value);
      ++size_all_non_nullptr;
    } else {
      arr[first_deleted]->value = value;
      arr[first_deleted]->state = true;
    }
    ++size;
    return true;
  }

 private:
  static const int default_size = 8;
  constexpr static const double rehash_size = 0.75;
  struct Node {
    T value;
    bool state;
    Node(const T& value_) : value(value_), state(true) {}
  };
  Node** arr;
  int size;
  int buffer_size;
  int size_all_non_nullptr;
};

#endif