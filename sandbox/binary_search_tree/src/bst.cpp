#include "bst.hpp"

// std libs:
#include <iostream>

// std usings:
// using std::cout, std::cin, std::endl;
using std::string, std::optional;

// class Node

Node::Node() : parent{nullptr}, left_child{nullptr}, right_child{nullptr} {}

Node::Node(int key)
    : parent{nullptr},
      left_child{nullptr},
      right_child{nullptr},
      key{key},
      data{std::to_string(key)} {}

Node::Node(int key, const std::string &data)
    : parent{nullptr},
      left_child{nullptr},
      right_child{nullptr},
      key{key},
      data{data} {}

Node::Node(Node *parent, Node *left_child, Node *right_child)
    : parent{parent}, left_child{left_child}, right_child{right_child} {}

// class BinarySearchTree

BinarySearchTree::BinarySearchTree(Node *main_parent)
    : main_parent_{main_parent} {}

bool BinarySearchTree::Add(int key, const string &s) {
  return Insert(new Node(key, s));
}

optional<string> BinarySearchTree::Find(int key) const {
  return Search(main_parent_, key)->data;
}

optional<string> BinarySearchTree::Remove(int key) {
  return Delete(main_parent_, key)->data;
}

void BinarySearchTree::ForEach(
    std::function<void(int key, const std::string &s)>) {}

Node *BinarySearchTree::Search(Node *n, int key) const {
  if (n == nullptr || key == n->key) return n;
  if (key < n->key)
    return Search(n->left_child, key);
  else
    return Search(n->right_child, key);
}

bool BinarySearchTree::Insert(Node *n) {
  auto curr_parent = main_parent_;

  while (n != nullptr) {
    if (n->key > curr_parent->key) {
      if (curr_parent->right_child != nullptr)
        curr_parent = curr_parent->right_child;
      else {
        n->parent = curr_parent;
        curr_parent->right_child = n;
        return true;
      }

    } else if (n->key < curr_parent->key) {
      if (curr_parent->left_child != nullptr)
        curr_parent = curr_parent->left_child;
      else {
        n->parent = curr_parent;
        curr_parent->left_child = n;
        return true;
      }
    }
  }
  return false;
}

Node *BinarySearchTree::Delete(Node *n, int key) {
  if (n == nullptr) return n;

  if (key < n->key)
    n->left_child = Delete(n->left_child, key);

  else if (key > n->key)
    n->right_child = Delete(n->right_child, key);

  else if (n->left_child != nullptr and n->right_child != nullptr) {
    n->key = Minimum(n->right_child)->key;
    n->right_child = Delete(n->right_child, n->key);
  } else if (n->left_child != nullptr)
    n = n->left_child;

  else if (n->right_child != nullptr)
    n = n->right_child;

  else
    n = nullptr;

  return n;
}
