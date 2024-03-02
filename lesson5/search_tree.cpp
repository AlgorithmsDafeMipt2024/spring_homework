#include "search_tree.hpp"

#include <stdexcept>

void Node::add_left_node(std::string data_, int key_) {
  left_child = new Node(data_, key_, this);
}

void Node::add_right_node(std::string data_, int key_) {
  right_child = new Node(data_, key_, this);
}

void Node_swap(Node* node1, Node* node2) {
  std::swap(node1->data, node2->data);
  std::swap(node1->key, node2->key);
}

std::string& Tree::Find(Node* current_node, int key) {
  if (current_node == nullptr) throw std::runtime_error("No such key");
  if (current_node->key == key)
    return current_node->data;
  else if (key < current_node->key)
    return Find(current_node->left_child, key);
  else
    return Find(current_node->right_child, key);
}

std::pair<std::string, Node*> Tree::Find_Node(Node* current_node, int key) {
  if (current_node == nullptr) return {"no head", current_node};
  if (current_node->key == key)
    return {"repeat", current_node};
  else if (key < current_node->key) {
    if (current_node->left_child == nullptr) return {"left", current_node};
    return Find_Node(current_node->left_child, key);
  } else {
    if (current_node->right_child == nullptr) return {"right", current_node};
    return Find_Node(current_node->right_child, key);
  }
}

bool Tree::Add(int key, std::string data_) {
  std::pair<std::string, Node*> needed_node_pair = Find_Node(head, key);
  if (needed_node_pair.first == "no head") {
    head = new Node(data_, key);
    return true;
  } else if (needed_node_pair.first == "repeat")
    return false;
  else if (needed_node_pair.first == "left") {
    needed_node_pair.second->left_child =
        new Node(data_, key, needed_node_pair.second);
    return true;
  } else if (needed_node_pair.first == "right") {
    needed_node_pair.second->left_child =
        new Node(data_, key, needed_node_pair.second);
    return true;
  }
  throw std::runtime_error(
      "Tree::Add(...) function reaches the end without returning a value, fix "
      "this");
}

std::string& Tree::Remove(int key) {}