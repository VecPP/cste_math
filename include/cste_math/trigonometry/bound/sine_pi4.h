#ifndef CSTE_MATH_TRIGNOMETRY_SINE_PI4_H_INCLUDED
#define CSTE_MATH_TRIGNOMETRY_SINE_PI4_H_INCLUDED

#include "cste_math/config.h"

#include "cste_math/constants.h"
#include "cste_math/factorial.h"

#include <cassert>

namespace CSTE_MATH_NAMESPACE {

  // Evaluates sin(x) in the [-PI/4, PI/4] range
  template<typename T>
  constexpr T sine_pi4(const T& rad) {
    assert(rad >= -quarter_pi<T> && rad <= quarter_pi<T>);
    // Promote to long double
    long double r = rad;
    
    // A simple Taylor series expansion for now
    long double r_2 = r * r * -1.0;
    long double num = r;
    long double result = r;
    for (std::size_t i = 3; i < 19; i += 2) {
      num *= r_2;
      result += num / factorial<long long>(i);
    }

    return T(result);
  }
}

#endif