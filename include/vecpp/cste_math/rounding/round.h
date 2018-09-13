#ifndef CSTE_MATH_ROUND_H_INCLUDED
#define CSTE_MATH_ROUND_H_INCLUDED

#include "vecpp/cste_math/config.h"

#include "vecpp/cste_math/rounding/round_down.h"

namespace CSTE_MATH_NAMESPACE {

template <typename T>
constexpr T round(const T& v) {
  return round_down(v + T(0.5));
}
}  // namespace CSTE_MATH_NAMESPACE

#endif