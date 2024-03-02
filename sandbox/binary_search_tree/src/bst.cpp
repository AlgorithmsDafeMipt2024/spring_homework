#include "bst.hpp"

// std libs:
#include <iostream>

// std usings:
// using std::cout, std::cin, std::endl;
using std::string, std::optional;

// class Node

Node::Node(Node *parent, Node *left_child, Node *right_child)
    : parent_{parent}, left_child_{left_child}, right_child_{right_child} {}

// class BinarySearchTree

BinarySearchTree::BinarySearchTree(Node *parent) : main_parent_{parent} {}

bool BinarySearchTree::Add(int key, const string &s) { return false; }

optional<string> BinarySearchTree::Find(int key) const {
  return optional<string>();
}

optional<string> BinarySearchTree::Remove(int key) {
  return optional<string>();
}

void BinarySearchTree::ForEach(
    std::function<void(int key, const std::string &s)>) {}
