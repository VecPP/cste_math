#ifndef CSTE_MATH_CEIL_H_INCLUDED
#define CSTE_MATH_CEIL_H_INCLUDEDD

#include "cste_math/config.h"

#include <limits>
#include <cmath>

namespace CSTE_MATH_NAMESPACE {

template<typename T>
constexpr T ceil(const T& v) {
  constexpr long long int range_max = 1LL << std::numeric_limits<T>::digits;
  constexpr long long int range_min = -range_max;

  if (v >= range_max || v <= range_min || std::isnan(v)) {
    return v;
  }
  
  long long int x = static_cast<long long int>(v);

  if (v == T(x) || v < T(0)) {
    return T(x);
  }
  return T(x + 1);
}
}

#endif

