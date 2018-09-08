#ifndef CSTE_MATH_TRIGNOMETRY_TANGENT_H_INCLUDED
#define CSTE_MATH_TRIGNOMETRY_TANGENT_H_INCLUDED

#include "cste_math/config.h"

#include "cste_math/trigonometry/cosine.h"
#include "cste_math/trigonometry/sine.h"


namespace CSTE_MATH_NAMESPACE {

//
template <typename T>
constexpr T cosine(const T& rad) {
  return since(rad) / cosine(rad);
}
}  // namespace CSTE_MATH_NAMESPACE

#endif