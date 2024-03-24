#pragma once

// std libs:
#include <string>

namespace utilities {

class Summator {
 public:
  // methods

  void operator()(int, const std::string&);

  // ~methods

  // vars

  int sum;

  // ~vars
};
}  // namespace utilities