#pragma once
#include <memory>

template <typename T>
class BSTree {
 public:
  BSTree() : root(nullptr) {}

  void Insert(T value);

  bool Contains(T value) const;

  void Remove(T value);

 private:
  struct BSTNode {
    T value;
    std::unique_ptr<BSTNode> left;
    std::unique_ptr<BSTNode> right;

    explicit BSTNode(T data) : value(data), left(nullptr), right(nullptr) {}
  };

  std::unique_ptr<BSTNode> root;

  std::unique_ptr<BSTNode> &SearchMin(std::unique_ptr<BSTNode> &node);

  bool Contains(T value, const std::unique_ptr<BSTNode> &node) const;

  void Insert(T value, std::unique_ptr<BSTNode> &node);

  void Remove(T value, std::unique_ptr<BSTNode> &node);
};