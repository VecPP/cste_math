#ifndef CSTE_MATH_BOUNDING_ABSOLUTE_H_INCLUDED
#define CSTE_MATH_BOUNDING_ABSOLUTE_H_INCLUDED

#include "cste_math/config.h"

namespace CSTE_MATH_NAMESPACE {

template <typename T>
constexpr T absolute(const T& v) {
  return v < 0 ? -v : v;
}

}  // namespace CSTE_MATH_NAMESPACE

#endif
