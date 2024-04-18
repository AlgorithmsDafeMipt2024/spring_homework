#pragma once

template <typename CustomType>
concept constructable = requires(CustomType a, CustomType b) {
  a = CustomType{};
  b = CustomType{a};
};

template <constructable CustomType>
struct TreeNode {
  TreeNode()
      : left_child{nullptr}, parent{nullptr}, right_child{nullptr}, value{} {}
  TreeNode(CustomType value_)
      : left_child{nullptr},
        parent{nullptr},
        right_child{nullptr},
        value{value_} {}
  TreeNode(TreeNode* parent_)
      : left_child{nullptr}, parent{parent_}, right_child{nullptr}, value{} {}
  TreeNode(CustomType value_, TreeNode& parent_)
      : left_child{nullptr},
        parent{parent_},
        right_child{nullptr},
        value{value_} {}
  TreeNode(TreeNode* left_child_, CustomType value_, TreeNode* right_child_)
      : left_child{left_child_}, value{value_}, right_child{right_child_} {
    if (left_child_ != nullptr) left_child_->parent = this;
    if (right_child_ != nullptr) right_child_->parent = this;
  }

  void add_left(CustomType value_);
  void add_right(CustomType value_);
  bool is_root() { return this->parent == nullptr; }

  TreeNode* left_child;
  TreeNode* parent;
  TreeNode* right_child;
  CustomType value;
};

template <constructable CustomType>
void TreeNode<CustomType>::add_left(CustomType value_) {
  left_child = new TreeNode(value_, *this);
}

template <constructable CustomType>
void TreeNode<CustomType>::add_right(CustomType value_) {
  right_child = new TreeNode(value_, *this);
}