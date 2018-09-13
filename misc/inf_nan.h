#ifndef CSTE_MATH_MISC_NAN_H_INCLUDED
#define CSTE_MATH_MISC_NAN_H_INCLUDED

#include "vecpp/cste_math/config.h"

namespace CSTE_MATH_NAMESPACE {
template <typename T>
constexpr bool is_nan(const T& v) {
  return !(v == v);
}

template <typename T>
constexpr bool is_inf(const T& v) {
  constexpr T inf = std::numeric_limits<T>::infinity();
  return v == inf || v == -inf;
}
}  // namespace CSTE_MATH_NAMESPACE

#endif