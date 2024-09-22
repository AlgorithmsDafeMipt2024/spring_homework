#ifndef NODE_H
#define NODE_H

// #include <concepts>
#include <memory>
#include <optional>
#include <stdexcept>
#include <type_traits>

namespace s21 {

// template <typename T>
// concept Comparable = requires(T a, T b) {
//   { a < b } -> std::convertible_to<bool>;
//   { a <= b } -> std::convertible_to<bool>;
//   { a > b } -> std::convertible_to<bool>;
//   { a >= b } -> std::convertible_to<bool>;
//   { a == b } -> std::convertible_to<bool>;
// };

template <typename T>
struct Is_comparable {
  static constexpr bool is_less =
      decltype(std::declval<T>() < std::declval<T>(), std::true_type{})::value;
  static constexpr bool is_equal =
      decltype(std::declval<T>() == std::declval<T>(), std::true_type{})::value;
  static constexpr bool value = is_less && is_equal;
};

template <class V, class K, K const (*get_key)(V)>
class Node : public std::enable_shared_from_this<Node<V, K, get_key>> {
 private:
  // static_assert(Comparable<Key>::value, "K must be a comparable type");
  static_assert(Is_comparable<K>::value, "K must be a comparable type");
  using node_class = Node<V, K, get_key>;
  V value;
  std::weak_ptr<node_class> parent;
  std::shared_ptr<node_class> left_child;
  std::shared_ptr<node_class> right_child;

 public:
  class NodeIterator;
  class ConstNodeIterator;

  Node(V const &value, std::weak_ptr<node_class> const &parent) {
    this->value = value;
    this->parent = parent;
    left_child = nullptr;
    right_child = nullptr;
    if (!parent.expired() && parent.lock() && value < parent.lock()->value)
      parent.lock()->left_child = this->shared_from_this();
    else if (!parent.expired() && parent.lock())
      parent.lock()->right_child = this->shared_from_this();
  }

  Node(V const &value_) : value{value_} {
    parent.reset();
    left_child = nullptr;
    right_child = nullptr;
  }

  Node() {
    parent.reset();
    left_child = nullptr;
    right_child = nullptr;
  }

  static NodeIterator begin(std::shared_ptr<node_class> &root, void *tree) {
    auto begin_node = root;
    if (begin_node)
      while (begin_node->left_child) begin_node = begin_node->left_child;
    return NodeIterator(begin_node, tree);
  }

  static NodeIterator end(std::shared_ptr<node_class> &, void *tree) {
    return NodeIterator(tree);
  }

  static ConstNodeIterator cbegin(std::shared_ptr<node_class> const &root,
                                  void const *tree) {
    auto begin_node = root;
    if (begin_node)
      while (begin_node->left_child) begin_node = begin_node->left_child;
    return ConstNodeIterator(begin_node, tree);
  }

  static ConstNodeIterator cend(std::shared_ptr<node_class> const &,
                                void const *tree) {
    return ConstNodeIterator(tree);
  }

  static std::pair<NodeIterator, bool> add(std::shared_ptr<node_class> &root,
                                           V const &value, void *tree) {
    bool added = push_to_root(root, value);
    NodeIterator pos;
    if (!added) {
      auto parent_pair = parent_for_new_leaf(root, get_key(value));
      auto new_Node_parent = parent_pair.first;
      if (parent_pair.second) {
        auto leaf = std::shared_ptr<node_class>(new node_class(value));
        leaf->setParent(new_Node_parent);
        added = true;
        leaf->balance_up(root);
        pos = NodeIterator(leaf, tree);
      } else
        pos = NodeIterator(new_Node_parent, tree);
    } else
      pos = NodeIterator(root, tree);
    return {pos, added};
  }

  static void add(std::shared_ptr<node_class> &root, V const &value) {
    bool added = push_to_root(root, value);
    if (!added) {
      auto parent_pair = parent_for_new_leaf(root, get_key(value));
      auto new_Node_parent = parent_pair.first;
      if (parent_pair.second) {
        auto leaf = std::shared_ptr<node_class>(new node_class(value));
        leaf->setParent(new_Node_parent);
        added = true;
        leaf->balance_up(root);
      }
    }
  }

  static bool exists(std::shared_ptr<node_class> const &root, K const &value) {
    return root ? bool(root->findNode(value)) : false;
  }

  static NodeIterator find(std::shared_ptr<node_class> const &root,
                           K const &key, void *tree) {
    NodeIterator pos;
    if (root) pos = NodeIterator(root->findNode(key), tree);
    return pos;
  }

  static std::optional<std::reference_wrapper<V>> remove(
      std::shared_ptr<node_class> &root, V const &value) {
    std::optional<std::reference_wrapper<V>> result = std::nullopt;
    if (root) {
      auto removing_node = root->findNode(get_key(value));
      if (removing_node) {
        result = removing_node->value;
        removing_node->delete_node(root);
      }
    }
    return result;
  }

  static std::optional<std::reference_wrapper<V>> remove(
      std::shared_ptr<node_class> &root, NodeIterator const &pos,
      void const *tree) {
    std::optional<std::reference_wrapper<V>> result = std::nullopt;
    if (tree == pos.__M_tree) {
      auto removing_node = pos.node;
      if (root && !removing_node.expired()) {
        result = removing_node.lock()->value;
        removing_node.lock()->delete_node(root);
      }
    }
    return result;
  }

  static std::optional<std::reference_wrapper<V>> remove(
      std::shared_ptr<node_class> &root, ConstNodeIterator const &pos,
      void const *tree) {
    std::optional<std::reference_wrapper<V>> result = std::nullopt;
    if (tree == pos.__M_tree) {
      auto removing_node = pos.node;
      if (root && !removing_node.expired()) {
        result = removing_node.lock()->value;
        removing_node.lock()->delete_node(root);
      }
    }
    return result;
  }

  static size_t size(std::shared_ptr<node_class> const &root) {
    size_t result = 0;
    if (root) result = root->size();
    return result;
  }

  static size_t height(std::shared_ptr<node_class> const &root) {
    size_t result = 0;
    if (root) result = root->height();
    return result;
  }

 private:
  size_t size() const {
    size_t result = 1;
    if (left_child) result += left_child->size();
    if (right_child) result += right_child->size();
    return result;
  }

  int height() const {
    int height_ = 0;
    if (left_child)
      height_ = left_child->height();
    else
      height_ = 0;
    if (right_child) height_ = std::max(height_, right_child->height());
    height_++;
    return height_;
  }

  static bool push_to_root(std::shared_ptr<node_class> &root, V const &value) {
    bool pushed = !root;
    if (pushed) root = std::shared_ptr<node_class>(new node_class(value));
    return pushed;
  }

  void balance_up(std::shared_ptr<node_class> &root) {
    std::shared_ptr<node_class> not_balanced_Node = this->shared_from_this();
    while (not_balanced_Node) {
      not_balanced_Node->balance_node(root);
      not_balanced_Node = not_balanced_Node->parent.expired()
                              ? nullptr
                              : not_balanced_Node->parent.lock();
    }
  }

  static std::pair<std::shared_ptr<node_class>, bool> parent_for_new_leaf(
      std::shared_ptr<node_class> const &root, K const &key) {
    std::shared_ptr<node_class> new_leaf_parent = nullptr;
    bool key_is_unique = true;
    if (root) {
      auto new_leaf_parent_finder = root;
      while (!new_leaf_parent && key_is_unique) {
        if (key < get_key(new_leaf_parent_finder->value)) {
          if (new_leaf_parent_finder->left_child)
            new_leaf_parent_finder = new_leaf_parent_finder->left_child;
          else
            new_leaf_parent = new_leaf_parent_finder;
        } else if (get_key(new_leaf_parent_finder->value) < key) {
          if (new_leaf_parent_finder->right_child)
            new_leaf_parent_finder = new_leaf_parent_finder->right_child;
          else
            new_leaf_parent = new_leaf_parent_finder;
        } else {
          new_leaf_parent = new_leaf_parent_finder;
          key_is_unique = false;
        }
      }
    }
    return {new_leaf_parent, key_is_unique};
  }

  void setParent(std::shared_ptr<node_class> const &node_parent) {
    if (node_parent && get_key(value) < get_key(node_parent->value))
      node_parent->left_child = this->shared_from_this();
    else if (node_parent)
      node_parent->right_child = this->shared_from_this();
    parent = node_parent;
  }

  std::shared_ptr<node_class> findNode(K const &key) {
    std::shared_ptr<node_class> node_finder = this->shared_from_this();
    bool found_node = false;
    while (node_finder && !found_node) {
      if (key < get_key(node_finder->value) && node_finder->left_child)
        node_finder = node_finder->left_child;
      else if (get_key(node_finder->value) < key && node_finder->right_child)
        node_finder = node_finder->right_child;
      else if (key == get_key(node_finder->value))
        found_node = true;
      else
        node_finder = nullptr;
    }
    return node_finder;
  }

  std::shared_ptr<node_class> tear_biggest_from_least_childs() {
    auto changing = this->biggest_from_least_childs();
    if (!changing->parent.expired() &&
        changing->parent.lock()->left_child == changing)
      changing->parent.lock()->left_child = changing->left_child;
    else if (!changing->parent.expired())
      changing->parent.lock()->right_child = changing->left_child;
    if (changing->left_child) changing->left_child->parent = changing->parent;
    return changing;
  }

  std::shared_ptr<node_class> biggest_from_least_childs() {
    auto biggest = this->left_child;
    while (biggest && biggest->right_child) biggest = biggest->right_child;
    return biggest;
  }

  std::shared_ptr<node_class> least_from_biggest_childs() {
    auto least = this->right_child;
    while (least && least->left_child) least = least->left_child;
    return least;
  }

  std::shared_ptr<node_class> tear_least_from_biggest_childs() {
    auto changing = this->least_from_biggest_childs();
    if (!changing->parent.expired() &&
        changing->parent.lock()->left_child == changing)
      changing->parent.lock()->left_child = changing->right_child;
    else if (!changing->parent.expired())
      changing->parent.lock()->right_child = changing->right_child;
    if (changing->right_child) changing->right_child->parent = changing->parent;
    return changing;
  }

  void replace_node(std::shared_ptr<node_class> const &replacing_node,
                    std::shared_ptr<node_class> &root) {
    auto node_to_replace = this->shared_from_this();
    if (!node_to_replace->parent.expired() && node_to_replace->parent.lock()) {
      if (node_to_replace->parent.lock()->left_child == node_to_replace)
        node_to_replace->parent.lock()->left_child = replacing_node;
      else if (!node_to_replace->parent.expired())
        node_to_replace->parent.lock()->right_child = replacing_node;
    } else
      root = replacing_node;
    replacing_node->parent = node_to_replace->parent;
    replacing_node->left_child = node_to_replace->left_child;
    replacing_node->right_child = node_to_replace->right_child;
    if (node_to_replace->left_child)
      node_to_replace->left_child->parent = replacing_node;
    if (node_to_replace->right_child)
      node_to_replace->right_child->parent = replacing_node;
  }

  void delete_node(std::shared_ptr<node_class> &root) {
    auto node = this->shared_from_this();
    if (node->left_child) {
      auto changing = node->tear_biggest_from_least_childs();
      auto unbalanced_node =
          changing->parent.lock() == node ? changing : changing->parent.lock();
      node->replace_node(changing, root);
      unbalanced_node->balance_up(root);
    } else if (node->right_child) {
      auto changing = node->tear_least_from_biggest_childs();
      auto unbalanced_node =
          changing->parent.lock() == node ? changing : changing->parent.lock();
      node->replace_node(changing, root);
      unbalanced_node->balance_up(root);
    } else if (!node->parent.expired()) {
      if (node->parent.lock()->left_child == node)
        node->parent.lock()->left_child =
            nullptr;  // node->parent.lock()->left_child.reset();
      else
        node->parent.lock()->right_child =
            nullptr;  // node->parent.lock()->right_child.reset();
      node->parent.lock()->balance_up(root);
    } else
      root = nullptr;
  }

  void balance_node(std::shared_ptr<node_class> &root) {
    int height_left = left_child ? left_child->height() : 0;
    int height_right = right_child ? right_child->height() : 0;
    if (height_left == height_right + 2)
      left_turn(root);
    else if (height_right == height_left + 2)
      right_turn(root);
  }

  void right_turn(std::shared_ptr<node_class> &root) {
    if (right_child->right_child &&
        (!right_child->left_child || right_child->right_child->height() ==
                                         1 + right_child->left_child->height()))
      right_small_turn(root);
    else
      right_big_turn(root);
  }

  void left_turn(std::shared_ptr<node_class> &root) {
    if (left_child->left_child &&
        (!left_child->right_child || left_child->left_child->height() ==
                                         1 + left_child->right_child->height()))
      left_small_turn(root);
    else
      left_big_turn(root);
  }

  void right_big_turn(std::shared_ptr<node_class> &root) {
    // to understand whats shared_A, shared_B, shared_C look up to png in
    // images folder
    auto shared_A = this->shared_from_this();
    auto shared_B = right_child;
    auto shared_C = shared_B->left_child;
    if (!shared_A->parent.expired() &&
        shared_A->parent.lock()->left_child == shared_A)
      shared_A->parent.lock()->left_child = shared_C;
    else if (shared_A->parent.expired())
      root = shared_C;
    else
      shared_A->parent.lock()->right_child = shared_C;
    shared_C->parent = shared_A->parent;
    shared_A->parent = shared_C;
    auto temp = shared_C->left_child;
    shared_C->left_child = shared_A;
    shared_A->parent = shared_C;
    shared_A->right_child = temp;
    if (temp) temp->parent = shared_A;
    temp = shared_C->right_child;
    shared_C->right_child = shared_B;
    shared_B->parent = shared_C;
    shared_B->left_child = temp;
    if (temp) temp->parent = shared_B;
  }

  void right_small_turn(std::shared_ptr<node_class> &root) {
    auto shared_A = this->shared_from_this();
    auto shared_B = right_child;
    if (!shared_A->parent.expired() &&
        shared_A->parent.lock()->left_child == shared_A)
      shared_A->parent.lock()->left_child = shared_B;
    else if (shared_A->parent.expired())
      root = shared_B;
    else
      shared_A->parent.lock()->right_child = shared_B;
    shared_B->parent = shared_A->parent;
    shared_A->parent = shared_B;
    auto temp = shared_B->left_child;
    shared_B->left_child = shared_A;
    shared_A->right_child = temp;
    if (temp) temp->parent = shared_A;
  }

  void left_big_turn(std::shared_ptr<node_class> &root) {
    auto shared_A = this->shared_from_this();
    auto shared_B = left_child;
    auto shared_C = shared_B->right_child;
    if (!shared_A->parent.expired() &&
        shared_A->parent.lock()->left_child == shared_A)
      shared_A->parent.lock()->left_child = shared_C;
    else if (shared_A->parent.expired())
      root = shared_C;
    else
      shared_A->parent.lock()->right_child = shared_C;
    shared_C->parent = shared_A->parent;
    shared_A->parent = shared_C;
    auto temp = shared_C->left_child;
    shared_C->left_child = shared_B;
    shared_B->parent = shared_C;
    shared_B->right_child = temp;
    if (temp) temp->parent = shared_B;
    temp = shared_C->right_child;
    shared_C->right_child = shared_A;
    shared_A->parent = shared_C;
    shared_A->left_child = temp;
    if (temp) temp->parent = shared_A;
  }

  void left_small_turn(std::shared_ptr<node_class> &root) {
    auto shared_A = this->shared_from_this();
    auto shared_B = left_child;
    if (!shared_A->parent.expired() &&
        shared_A->parent.lock()->left_child == shared_A)
      shared_A->parent.lock()->left_child = shared_B;
    else if (shared_A->parent.expired())
      root = shared_B;
    else
      shared_A->parent.lock()->right_child = shared_B;
    shared_B->parent = shared_A->parent;
    shared_A->parent = shared_B;
    auto temp = shared_B->right_child;
    shared_B->right_child = shared_A;
    shared_A->left_child = temp;
    if (temp) temp->parent = shared_A;
  }
};
template <class V, class K, K const (*get_key)(V)>
class Node<V, K, get_key>::NodeIterator {
 private:
  using node_class = Node<V, K, get_key>;

 public:
  std::weak_ptr<node_class> node;
  void *__M_tree;
  NodeIterator() {
    node.reset();
    __M_tree = nullptr;
  }

  NodeIterator(std::weak_ptr<node_class> node, void *__M_tree) {
    this->node = node;
    this->__M_tree = __M_tree;
  }

  NodeIterator(void *__M_tree) { this->__M_tree = __M_tree; }

  NodeIterator(NodeIterator const &other) {
    node = other.node;
    __M_tree = other.__M_tree;
  }

  NodeIterator const &operator=(NodeIterator const &other) {
    node = other.node;
    __M_tree = other.__M_tree;
    return *this;
  }

  V &operator*() {
    if (node.expired())
      throw std::runtime_error(
          "NodeIterator::operator*(): NodeIterator pointing to nullptr");
    return node.lock()->value;
  }
  V *operator->() {
    if (node.expired())
      throw std::runtime_error(
          "NodeIterator::operator->(): NodeIterator pointing to expired value");
    return &(node.lock()->value);
  }

  bool operator==(NodeIterator other) {
    return (__M_tree == other.__M_tree) &&
           ((node.expired() && other.node.expired()) ||
            ((!node.expired() && !other.node.expired()) &&
             (node.lock() == other.node.lock())));
  }

  bool operator!=(NodeIterator other) { return (!operator==(other)); }

  NodeIterator operator++() {
    if (!node.expired()) {
      auto node_shared = node.lock();
      if (node_shared->right_child)
        node = node_shared->least_from_biggest_childs();
      else {
        auto finder = node_shared->parent.expired()
                          ? nullptr
                          : node_shared->parent.lock();
        auto finder_child = node_shared;
        while (finder && finder->right_child == finder_child) {
          finder_child = finder;
          finder = finder->parent.expired() ? nullptr : finder->parent.lock();
        }
        node = finder;
      }
    }
    return *this;
  }

  NodeIterator operator--() {
    if (!node.expired()) {
      auto node_shared = node.lock();
      if (node_shared->left_child)
        node = node_shared->biggest_from_least_childs();
      else {
        auto finder = node_shared->parent.expired()
                          ? nullptr
                          : node_shared->parent.lock();
        auto finder_child = node_shared;
        while (finder && finder->left_child == finder_child) {
          finder_child = finder;
          finder = finder->parent.expired() ? nullptr : finder->parent.lock();
        }
        node = finder;
      }
    }

    return *this;
  }

  NodeIterator operator++(int) { return this->operator++(); }
  NodeIterator operator--(int) { return this->operator--(); }
};

template <class V, class K, K const (*get_key)(V)>
class Node<V, K, get_key>::ConstNodeIterator {
 private:
  using const_node_class = Node<V, K, get_key> const;

 public:
  std::weak_ptr<node_class> node;
  void const *__M_tree;
  ConstNodeIterator() {
    node.reset();
    __M_tree = nullptr;
  }

  ConstNodeIterator(std::weak_ptr<node_class> node, void const *__M_tree) {
    this->node = node;
    this->__M_tree = __M_tree;
  }

  ConstNodeIterator(void const *__M_tree) { this->__M_tree = __M_tree; }

  ConstNodeIterator(ConstNodeIterator const &other) {
    node = other.node;
    __M_tree = other.__M_tree;
  }

  ConstNodeIterator const &operator=(ConstNodeIterator const &other) {
    node = other.node;
    __M_tree = other.__M_tree;
    return *this;
  }

  V const &operator*() {
    if (node.expired())
      throw std::runtime_error(
          "ConstNodeIterator::operator*(): ConstNodeIterator pointing to "
          "nullptr");
    return node.lock()->value;
  }
  V const *operator->() {
    if (node.expired())
      throw std::runtime_error(
          "ConstNodeIterator::operator->(): ConstNodeIterator pointing to "
          "nullptr");
    return &(node.lock()->value);
  }

  bool operator==(ConstNodeIterator other) {
    return (__M_tree == other.__M_tree) &&
           ((node.expired() && other.node.expired()) ||
            ((!node.expired() && !other.node.expired()) &&
             (node.lock() == other.node.lock())));
  }

  bool operator!=(ConstNodeIterator other) { return !operator==(other); }

  ConstNodeIterator operator++() {
    if (!node.expired()) {
      auto node_shared = node.lock();
      if (node_shared->right_child)
        node = node_shared->least_from_biggest_childs();
      else {
        auto finder = node_shared->parent.expired()
                          ? nullptr
                          : node_shared->parent.lock();
        auto finder_child = node_shared;
        while (finder && finder->right_child == finder_child) {
          finder_child = finder;
          finder = finder->parent.expired() ? nullptr : finder->parent.lock();
        }
        node = finder;
      }
    }
    return *this;
  }

  ConstNodeIterator operator--() {
    if (node) {
      if (node.expired())
        node.reset();
      else {
        auto node_shared = node.lock();
        if (node_shared->left_child)
          node = node_shared->biggest_from_least_childs();
        else {
          auto finder = node_shared->parent.expired()
                            ? nullptr
                            : node_shared->parent.lock();
          auto finder_child = node_shared;
          while (finder && finder->left_child == finder_child) {
            finder_child = finder;
            finder = finder->parent.expired() ? nullptr : finder->parent.lock();
          }
          node = finder;
        }
      }
    }
    return *this;
  }

  ConstNodeIterator operator++(int) { return this->operator++(); }
  ConstNodeIterator operator--(int) { return this->operator--(); }
};

}  // namespace s21
#endif