#ifndef CSTE_MATH_MODULO_H_INCLUDED
#define CSTE_MATH_MODULO_H_INCLUDED

#include "cste_math/config.h"

#include "cste_math/rounding/round_down.h"

#include <type_traits>

namespace CSTE_MATH_NAMESPACE {
template <typename T>
constexpr T modulo(const T& val, const T& div) {
  if constexpr (std::is_integral_v<T>) {
    return val % div;
  } else {
    return val - round_down(val / div) * div;
  }
}
}  // namespace CSTE_MATH_NAMESPACE

#endif