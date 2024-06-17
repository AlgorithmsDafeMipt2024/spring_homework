#include <vector>

template <typename V>
struct HashNode {
  HashNode(const size_t& key, const V& value)
      : key(key), value(value), next(nullptr) {}

  size_t key;
  V value;
  HashNode* next;
};

template <typename V>
class HashTable {
 public:
  HashTable(size_t size) { table.resize(size, nullptr); }

  ~HashTable() {
    for (const auto& elem : table) delete elem;
  }

  // https://en.wikipedia.org/wiki/Fowler%E2%80%93Noll%E2%80%93Vo_hash_function?useskin=vector
  size_t HashFunction(const size_t& key, size_t table_size) {
    size_t hash = 2166136261;  // Начальное значение FNV-1a хеша
    const size_t fnv_prime = 16777619;

    for (char c : std::to_string(key)) {
      hash ^= static_cast<size_t>(c);
      hash *= fnv_prime;
    }

    return hash % table_size;
  }

  void Insert(const size_t& key, const V& value) {
    size_t index = HashFunction(key, table.size());
    HashNode<V>* newNode = new HashNode<V>(key, value);

    if (table[index] == nullptr)
      table[index] = newNode;

    else {
      HashNode<V>* current = table[index];

      while (current->next != nullptr) current = current->next;

      current->next = newNode;
    }
  }

  V GetValue(const size_t& key) {
    size_t index = HashFunction(key, table.size());
    HashNode<V>* current = table[index];

    while (current != nullptr) {
      if (current->key == key) return current->value;

      current = current->next;
    }

    throw std::out_of_range("Key not found.");
  }

  void RemoveByKey(const size_t& key) {
    size_t index = HashFunction(key, table.size());
    HashNode<V>* current = table[index];
    HashNode<V>* prev = nullptr;

    while (current != nullptr) {
      if (current->key == key) {
        if (prev == nullptr)
          table[index] = current->next;

        else
          prev->next = current->next;

        delete current;
        return;
      }

      prev = current;
      current = current->next;
    }

    throw std::out_of_range("Key not found.");
  }

 private:
  std::vector<HashNode<V>*> table;
};
