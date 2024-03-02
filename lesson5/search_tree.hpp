#include <functional>
#include <optional>
#include <stdexcept>
#include <string>

class Summator {
  int sum;
  void operator()(int, std::string);
};

struct Node {
  Node()
      : parent{nullptr},
        left_child{nullptr},
        right_child{nullptr},
        data{""},
        key{0} {}
  Node(std::string data_, int key_)
      : parent{nullptr},
        left_child{nullptr},
        right_child{nullptr},
        data{data_},
        key{key_} {}
  Node(std::string data_, int key_, Node* parent_)
      : parent{parent_},
        left_child{nullptr},
        right_child{nullptr},
        data{data_},
        key{key_} {}
  void add_left_node(std::string data_, int key_);
  void add_right_node(std::string data_, int key_);
  Node* parent;
  Node* left_child;
  Node* right_child;
  int key;
  std::string data;
};

class Tree {
 public:
  Tree() : head{nullptr} {}

  bool Add(int key, std::string data_);
  // could be replaced with "std::optional<std::string>"
  std::string& Find(Node* current_node, int key);
  std::string& Remove(int key);
  void ForEach(std::function<void(int, std::string)>);

 private:
  std::pair<std::string, Node*> Find_Node(Node* current_node, int key);

 private:
  Node* head;
};