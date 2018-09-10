#ifndef CSTE_MATH_DECOMPOSE_REAL_H_INCLUDED
#define CSTE_MATH_DECOMPOSE_REAL_H_INCLUDED

#include "cste_math/config.h"

#include "cste_math/calc/modulo.h"

#include <tuple>
namespace CSTE_MATH_NAMESPACE {

// This decomposes a real number into mantissa-exponent representation.
template <typename T>
constexpr std::tuple<T, int> decompose_real(const T& v) {
  if(v == T(0)) {
    return std::make_tuple(T(0), 0);
  }

  bool neg = v < T(0);
  T v_norm = absolute(v);
  int count = 0;

  // Putting a lot of faith in the compiler here.
  // TODO: this isn't exactly great... it can loop up to 300 times for a double...
  while(v_norm > T(2)) {
    ++count;
    v_norm /= T(2);
  }

  while(v_norm < T(1)) {
    --count;
    v_norm *= T(2);
  }

  return std::make_tuple(neg ? v_norm* T(-1) : v_norm, count);
}

}  // namespace CSTE_MATH_NAMESPACE

#endif