#ifndef CSTE_MATH_ROUND_DOWN_H_INCLUDED
#define CSTE_MATH_ROUND_DOWN_H_INCLUDED

#include "cste_math/config.h"

#include "cste_math/calc/power.h"
#include "cste_math/misc/inf_nan.h"

#include <cmath>
#include <limits>

namespace CSTE_MATH_NAMESPACE {

template <typename T>
constexpr T round_down(const T& v) {
  constexpr T range_max = power(T(2), (std::numeric_limits<T>::digits - 1));
  constexpr T range_min = -range_max;

  if (v >= range_max || v <= range_min || is_nan(v)) {
    return v;
  }

  long long int x = static_cast<long long int>(v);
  if (v == T(x) || v > T(0)) {
    return T(x);
  }
  return T(x - 1);
}
}  // namespace CSTE_MATH_NAMESPACE

#endif