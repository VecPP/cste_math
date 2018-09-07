#ifndef CSTE_MATH_TRIGNOMETRY_SINE_PI4_H_INCLUDED
#define CSTE_MATH_TRIGNOMETRY_SINE_PI4_H_INCLUDED

#include "cste_math/config.h"

#include "cste_math/constants.h"

#include <cassert>
#include <iomanip>
#include <iostream>

namespace CSTE_MATH_NAMESPACE {

namespace sine_detail {

// We have to do this recursively, because we want to collapse from the end
// to the start.
constexpr long double recur_helper(long double r_2, long double num,
                                        double fact, std::size_t i) {
  fact *= (i - 1);
  fact *= (i);
  num *= r_2;

  long double factor = num / fact;
  if (factor == 0.0L) {
    return 0.0;
  }
  return factor + recur_helper(r_2, num, fact, i + 2);
}
}

// Evaluates sin(x) in the [-PI/4, PI/4] range
template <typename T>
constexpr T sine_pi4(const T& rad) {
  assert(rad >= -quarter_pi<T> && rad <= quarter_pi<T>);

  // Promote to long double
  long double r = rad;

  return sine_detail::recur_helper(r * r * -1.0L, r, 1.0L, 3) + r;
}
}

#endif