#ifndef CSTE_MATH_CALC_POW_H_INCLUDED
#define CSTE_MATH_CALC_POW_H_INCLUDED

#include "cste_math/config.h"

#include "cste_math/rounding/absolute.h"
#include "cste_math/calc/exponential.h"
#include "cste_math/calc/natural_logarithm.h"

#include <type_traits>

namespace CSTE_MATH_NAMESPACE {

// Raises v by the operand p
template <typename T, typename U>
constexpr T power(const T& v, const U& p) {
  if constexpr (std::is_integral<U>()) {
    U raise = absolute(p);
    T factor = v;

    T result = T(1);
    while(raise > 0) {
      if(raise & 1) {
        result *= factor;
      }
      factor *= factor;
      raise >>=1;
    }
    return result;
  } else {
    //probably a fair bit of precision being lost here...
    return natural_logarithm(exponential(v) * p);
   }
}
}  // namespace CSTE_MATH_NAMESPACE

#endif
