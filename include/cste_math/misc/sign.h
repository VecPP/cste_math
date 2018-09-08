#ifndef CSTE_MATH_MISC_SIGN_H_INCLUDED
#define CSTE_MATH_MISC_SIGN_H_INCLUDED

#include "cste_math/config.h"

namespace CSTE_MATH_NAMESPACE {

template <typename T>
constexpr T sign(const T& v) {
  // https://stackoverflow.com/a/4609795/4442671
  return (T(0) < v) - (v < T(0));
}

}  // namespace CSTE_MATH_NAMESPACE

#endif