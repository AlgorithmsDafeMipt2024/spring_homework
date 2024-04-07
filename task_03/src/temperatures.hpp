#pragma once

// std libs:
#include <iostream>
#include <stdexcept>
#include <vector>

// @brief значение температуры в градусах цельсия
class Temperature {
 public:
  Temperature(float value) : value_{value} {
    if (value < -273.15)
      throw std::logic_error("temperature cannot be less than absolute zero");
  }

  Temperature(const Temperature& p) = default;

  Temperature& operator=(const Temperature& p) = default;

  Temperature& operator=(float p) {
    *this = Temperature(p);
    return *this;
  }

  friend Temperature& operator+=(Temperature& a, const Temperature& b);
  friend Temperature& operator-=(Temperature& a, const Temperature& b);

  auto operator<=>(const Temperature& b) const = default;
  auto operator<=>(float b) const { return value_ <=> b; }

  friend std::ostream& operator<<(std::ostream& os, const Temperature& par);
  friend std::istream& operator>>(std::istream& is, Temperature& vec);

  explicit operator float() const { return value_; }

 private:
  // температура не должна быть слишком большой
  // (поэтому здесь float, а не double)
  float value_{0};
};

inline Temperature& operator+=(Temperature& a, const Temperature& b) {
  a.value_ += b.value_;
  return a;
}

inline Temperature& operator-=(Temperature& a, const Temperature& b) {
  a.value_ -= b.value_;
  return a;
}

inline Temperature operator+(Temperature a, Temperature b) { return a += b; }
inline Temperature operator-(Temperature a, Temperature b) { return a -= b; }

inline std::ostream& operator<<(std::ostream& os, const Temperature& t) {
  return os << t.value_ << " °C";
}

inline std::istream& operator>>(std::istream& is, Temperature& t) {
  return is >> t.value_;
}
