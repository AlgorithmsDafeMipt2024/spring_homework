

#include <cstddef>
#include <vector>
class HashTable {
 public:
  HashTable()
      : buffer_size_(default_buffer_size),
        size_(0),
        used_cell_(0),
        container_(buffer_size_),
        cell_conditions_(buffer_size_, Condition::Empty) {}
  void Insert(int value);
  void Remove(int value);
  bool Contains(int value);

  void Clear();
  size_t Size();

 private:
  enum class Condition { Fill, Deleted, Empty };
  constexpr static const double rehash_coefficient = 0.75;
  constexpr static const double default_buffer_size = 8;
  constexpr static const double hash_coeficent = 0.86724813;
  size_t buffer_size_;
  size_t size_;
  size_t used_cell_;
  std::vector<int> container_;
  std::vector<Condition> cell_conditions_;

  size_t FirstHashFunction(int key);
  size_t SecondHashFunction(int key);

  void Resize();
  void Rehash();
};