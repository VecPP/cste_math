#ifndef CSTE_MATH_TRIGNOMETRY_COSINE_PI4_H_INCLUDED
#define CSTE_MATH_TRIGNOMETRY_COSINE_PI4_H_INCLUDED

#include "cste_math/config.h"

#include "cste_math/constants.h"
#include "cste_math/factorial.h"

#include <cassert>

namespace CSTE_MATH_NAMESPACE {

namespace cosine_detail {

// We have to do this recursively, because we want to collapse from the end
// to the start.
constexpr long double cosine_recur_helper(long double r_2, long double num,
                                          double fact, std::size_t i) {
  fact *= (i - 1);
  fact *= (i);
  num *= r_2;

  long double factor = num / fact;
  if(factor == 0.0L) {
    return 0.0;
  }
  
  return factor + cosine_recur_helper(r_2, num, fact, i + 2);
}
}



  // Evaluates sin(x) in the [-PI/4, PI/4] range
  template<typename T>
  constexpr T cosine_pi4(const T& rad) {
    assert(rad >= -quarter_pi<T> && rad <= quarter_pi<T>);
    // Promote to long double
    long double r = rad;
    long double r_2 = r * r * -1.0;

    return cosine_detail::cosine_recur_helper(r_2, 1, 1.0L, 2) + 1.0L;

    // A simple Taylor series expansion for now
    // A simple Taylor series expansion for now

    long double num = 1;
    long double result = 1;
    for (std::size_t i = 2; i < 18; i += 2) {
      num *= r_2;
      result += num / factorial<long long>(i);
    }

    return T(result);
  }
}

#endif