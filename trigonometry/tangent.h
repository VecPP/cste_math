#ifndef CSTE_MATH_TRIGNOMETRY_TANGENT_H_INCLUDED
#define CSTE_MATH_TRIGNOMETRY_TANGENT_H_INCLUDED

#include "vecpp/cste_math/config.h"

#include "vecpp/cste_math/trigonometry/cosine.h"
#include "vecpp/cste_math/trigonometry/sine.h"


namespace CSTE_MATH_NAMESPACE {

//
template <typename T>
constexpr T tangent(const T& rad) {
  return since(rad) / cosine(rad);
}
}  // namespace CSTE_MATH_NAMESPACE

#endif