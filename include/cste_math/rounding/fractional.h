#ifndef CSTE_MATH_FRACTIONAL_H_INCLUDED
#define CSTE_MATH_FRACTIONAL_H_INCLUDED

#include "cste_math/config.h"

#include "cste_math/rounding/truncate.h"

#include <type_traits>

namespace CSTE_MATH_NAMESPACE {
template <typename T>
constexpr T fractional(const T& val) {
  return val - truncate(val);
}
}  // namespace CSTE_MATH_NAMESPACE

#endif