//  Copyright 2018 Francois Chabot
//  (francois.chabot.dev@gmail.com)
//
//  Distributed under the Boost Software License, Version 1.0.
//  (See accompanying file LICENSE or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

#ifndef CSTE_STDLIB_H_INCLUDED
#define CSTE_STDLIB_H_INCLUDED

#include "vecpp/cste_math/config.h"

#include "vecpp/cste_math/functions.h"

// This file provides an api matching the C++ stdlib as much as possible, so 
// that cste_math can be used as a drop-in replacement.

// IMPORTANT: `cste_math` is not guaranteed to return values that are going to 100% 
// match their stdlib equivalent on all platforms.
//
// void foo() {
//   constexpr float val = cste::stdlib::sin(2.0f);
//   assert(val == std::sin(val)); // Maybe, and not consistent! 
// }

//
//
// Note that only functions that are not guaranteed to be constexpr will be
// overloaded here. For functions like std::min() and std::max(), which are
// already constexpr, the stdlib version should be used instead.


namespace CSTE_MATH_NAMESPACE {

namespace stdlib {
  template<typename T>
  constexpr T abs(const T& arg) {
    return absolute(arg);
  }

  template<typename T>
  constexpr T ceil(const T& arg) {
    return round_up(arg);
  }

  template<typename T>
  constexpr T exp(const T& arg) {
    return exponential(arg);
  }

  template<typename T>
  constexpr T floor(const T& arg) {
    return round_down(arg);
  }

  template<typename T>
  constexpr T fmod(const T& v, const T& d) {
    return modulo(v, d);
  }

  template<typename T>
  constexpr T fract(const T& arg) {
    return fractional(arg);
  }

  template<typename T>
  constexpr T pow(const T& v, const T& p) {
    return power(v, p);
  }

  template<typename T>
  constexpr T round(const T& arg) {
    return ::CSTE_MATH_NAMESPACE::round(arg);
  }

  template<typename T>
  constexpr T trunc(const T& arg) {
    return truncate(arg);
  }

  template<typename T>
  constexpr T sqrt(const T& arg) {
    return square_root(arg);
  }

  template<typename T>
  constexpr T sin(const T& arg) {
    return sine(arg);
  }

  template<typename T>
  constexpr T cos(const T& arg) {
    return cosine(arg);
  }

  template<typename T>
  constexpr T tan(const T& arg) {
    return tangent(arg);
  }
  
}

}  // namespace CSTE_MATH_NAMESPACE
#endif