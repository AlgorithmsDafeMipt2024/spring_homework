#include <stdexcept>

#include "concepts/constructable.hpp"

// simple structure, helps to form a doubly-linked list
template <constructable CustomClass>
struct ListNode {
  ListNode() : prev{nullptr}, data{}, next{nullptr} {}
  ListNode(CustomClass data_) : prev{nullptr}, data{data_}, next{nullptr} {}
  void AddNodeFront(CustomClass data_);
  void AddNodeBack(CustomClass data_);
  ListNode* next;
  ListNode* prev;
  CustomClass data;
};

template <constructable CustomClass>
void ListNode<CustomClass>::AddNodeFront(CustomClass data_) {
  ListNode* next_reserved = next;
  next = new ListNode(data_);
  next->prev = this;
  if (next_reserved != nullptr) {
    if (next_reserved->prev != this)
      throw std::logic_error("nodes aren't correctly connected\n");
    next_reserved->prev = next;
    next->next = next_reserved;
  }
}

template <constructable CustomClass>
void ListNode<CustomClass>::AddNodeBack(CustomClass data_) {
  ListNode* prev_reserved = prev;
  prev = new ListNode(data_);
  next->next = this;
  if (prev_reserved != nullptr) {
    if (prev_reserved->next != this)
      throw std::logic_error("nodes aren't correctly connected\n");
    prev_reserved->next = prev;
    prev->prev = prev_reserved;
  }
}