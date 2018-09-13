#ifndef CSTE_MATH_TRUNCATE_H_INCLUDED
#define CSTE_MATH_TRUNCATE_H_INCLUDED

#include "vecpp/cste_math/config.h"

#include "vecpp/cste_math/calc/power.h"
#include "vecpp/cste_math/misc/inf_nan.h"

#include <cmath>
#include <limits>

namespace CSTE_MATH_NAMESPACE {

template <typename T>
constexpr T truncate(const T& v) {
  long long int x = static_cast<long long int>(v);
  return T(x);
}
}  // namespace CSTE_MATH_NAMESPACE

#endif