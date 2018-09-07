#ifndef CSTE_MATH_CALC_POW_H_INCLUDED
#define CSTE_MATH_CALC_POW_H_INCLUDED

#include "cste_math/config.h"

#include <limits>
#include <cmath>
#include <cassert>

namespace CSTE_MATH_NAMESPACE {

template <typename T> 
constexpr T sqrt(const T& v) {
  assert(v >= T(0));

  if (v == T(0)) {
    return v;
  }

  T r = v;
  // A simple newton-rhapson for now.
  while (1) {
    T tmp = (r + v / r) / T(2);
    if (tmp == r) {
      break;
    }
    r = tmp;
  }

  return r;
}
}

#endif

