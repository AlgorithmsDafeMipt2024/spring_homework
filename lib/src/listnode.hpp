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
  next->next = next_reserved;
}

template <constructable CustomClass>
void ListNode<CustomClass>::AddNodeBack(CustomClass data_) {
  ListNode* prev_reserved = prev;
  prev = new ListNode(data_);
  next->next = this;
  prev->prev = prev_reserved;
}