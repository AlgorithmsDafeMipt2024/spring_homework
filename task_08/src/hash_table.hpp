// #pragma once
// #include <functional>
// #include <iostream>
// #include <list>
// #include <vector>

// template <typename K, typename V> class HashTable {
// public:
//   void Insert(K key, V value);
//   void Delete(K key);
//   bool Contains(K key);

// private:
//   size_t size;
//   std::vector<std::list<K, V>> H_Table(auto size);
//   void ReHash();
// };

// template <typename K, typename V> void HashTable<K, V>::Insert(K key, V value) {
//   size_t hash = std::hash(key) % size;
//   H_Table[hash].push_back(key, value);
// }