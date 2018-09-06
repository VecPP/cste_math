#ifndef CSTE_MATH_FLOOR_H_INCLUDED
#define CSTE_MATH_FLOOR_H_INCLUDED

#include "cste_math/config.h"

namespace CSTE_MATH_NAMESPACE {

template<typename T>
constexpr T floor(const T& v) {
  constexpr T range_max = std::ldexp(2, std::numeric_limits<T>::digits);
  constexpr T range_min = -range_max;

  if (v >= range_max || v <= range_min || std::isnan(v)) {
    return v;
  }
  
  long long int x = static_cast<long long int>(v);
  if (v == T(x) || v > T(0)) {
    return T(x);
  }
  return T(x - 1);
}
}

#endif