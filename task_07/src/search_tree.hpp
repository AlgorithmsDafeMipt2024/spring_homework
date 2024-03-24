#pragma once
#include <memory>

struct Node {
  int value;
  std::shared_ptr<Node> left;
  std::shared_ptr<Node> right;
  std::shared_ptr<Node> parent;

  Node(int v, std::shared_ptr<Node> l, std::shared_ptr<Node> r,
       std::shared_ptr<Node> p) {
    value = v;
    left = std::move(l);
    right = std::move(r);
    parent = std::move(p);
  }
};

class BinarySearchTree {
 public:
  std::shared_ptr<Node> Find(int value) const;

  void Remove(int value);
  void Insert(int value);

 private:
  std::shared_ptr<Node> root;
};
