#ifndef CSTE_MATH_CALC_EXP_H_INCLUDED
#define CSTE_MATH_CALC_EXP_H_INCLUDED

#include "cste_math/config.h"

#include "cste_math/constants.h"
#include "cste_math/rounding/round_down.h"

#include <cassert>
#include <cmath>
#include <limits>

namespace CSTE_MATH_NAMESPACE {

namespace exp_details {
// e^x = 1 + x + x^2/2! + x^3/3! + ...

// But! we add the terms from the smallest to the largest in order
// to maximize precision
constexpr long double recur_helper(long double x, long double num,
                                   long double fact, std::size_t i) {
  fact *= i;
  num *= x;
  long double factor = num / fact;

  if (factor == 0.0L) {
    return 0.0L;
  }

  return factor + recur_helper(x, num, fact, i + 1);
}
}  // namespace exp_details
// Raises e by the operand
template <typename T>
constexpr T exponential(const T& v) {
  long double v_p = v;
  bool neg = v < 0;
  if (neg) {
    v_p = -v_p;
  }

  // separate integral and fractional components
  uint32_t integral = uint32_t(round_down(v));
  long double fract = v_p - integral;

  long double int_val = 1;
  long double e_fact = e<long double>;
  while (integral != 0) {
    if (integral & 1) {
      int_val *= e_fact;
    }

    integral >>= 1;
    e_fact *= e<long double>;
  }

  long double fract_val = exp_details::recur_helper(fract, 1, 1, 1) + 1.0L;

  long double result = fract_val * int_val;
  return T(neg ? 1.0L / result : result);
}

}  // namespace CSTE_MATH_NAMESPACE

#endif
