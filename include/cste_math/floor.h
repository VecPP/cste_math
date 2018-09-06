#ifndef CSTE_MATH_FLOOR_H_INCLUDED
#define CSTE_MATH_FLOOR_H_INCLUDED

#include "cste_math/config.h"

namespace CSTE_MATH_NAMESPACE {

template<typename T>
constexpr T floor(const T& val) {
  constexpr long long int range_max = 1LL << std::numeric_limits<T>::digits;
  constexpr long long int range_min = -range_max;

  if (v >= range_max || v <= range_min) {
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