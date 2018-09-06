#ifndef CSTE_MATH_FACTORIAL_H_INCLUDED
#define CSTE_MATH_FACTORIAL_H_INCLUDED

#include "cste_math/config.h"

namespace CSTE_MATH_NAMESPACE {

template<typename T>
constexpr T factorial(std::size_t N) {
  T result = 1;
  for (T i = 1; i <= T(N); ++i) {
    result *= i;
  }
  return result;
}
}

#endif