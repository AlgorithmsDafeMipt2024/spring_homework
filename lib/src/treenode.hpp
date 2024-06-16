#pragma once
#include "concepts/constructable.hpp"

template <constructable CustomClass>
struct TreeNode {
  TreeNode()
      : left_child{nullptr}, parent{nullptr}, right_child{nullptr}, value{} {}
  TreeNode(CustomClass value_)
      : left_child{nullptr},
        parent{nullptr},
        right_child{nullptr},
        value{value_} {}
  TreeNode(TreeNode* parent_)
      : left_child{nullptr}, parent{parent_}, right_child{nullptr}, value{} {}
  TreeNode(CustomClass value_, TreeNode& parent_)
      : left_child{nullptr},
        parent{parent_},
        right_child{nullptr},
        value{value_} {}
  TreeNode(TreeNode* left_child_, CustomClass value_, TreeNode* right_child_)
      : left_child{left_child_}, value{value_}, right_child{right_child_} {
    if (left_child_ != nullptr) left_child_->parent = this;
    if (right_child_ != nullptr) right_child_->parent = this;
  }

  void add_left(CustomClass value_);
  void add_right(CustomClass value_);
  bool is_root() { return this->parent == nullptr; }

  TreeNode* left_child;
  TreeNode* parent;
  TreeNode* right_child;
  CustomClass value;
};

template <constructable CustomClass>
void TreeNode<CustomClass>::add_left(CustomClass value_) {
  left_child = new TreeNode(value_, *this);
}

template <constructable CustomClass>
void TreeNode<CustomClass>::add_right(CustomClass value_) {
  right_child = new TreeNode(value_, *this);
}