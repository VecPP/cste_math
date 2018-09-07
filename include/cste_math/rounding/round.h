#ifndef CSTE_MATH_FLOOR_H_INCLUDED
#define CSTE_MATH_FLOOR_H_INCLUDED

#include "cste_math/config.h"

#include "cste_math/rounding/round_down.h"

namespace CSTE_MATH_NAMESPACE {

template <typename T>
constexpr T round(const T& v) {

  constexpr T range_max = power(T(2), (std::numeric_limits<T>::digits - 1));
  constexpr T range_min = -range_max;

  if (v >= range_max || v <= range_min || is_nan(v)) {
    return v;
  }

  return round_down(v + T(0.5));

}
}

#endif