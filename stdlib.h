//  Copyright 2018 Francois Chabot
//  (francois.chabot.dev@gmail.com)
//
//  Distributed under the Boost Software License, Version 1.0.
//  (See accompanying file LICENSE or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

#ifndef CSTE_STDLIB_H_INCLUDED
#define CSTE_STDLIB_H_INCLUDED

#include "cste_math/config.h"

// This file provides an api matching the C++ stdlib as much as possible, so 
// that cste_math can be used as a drop-in replacement.

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
  constexpr T round(const T& arg) {
    return round_nearest(arg);
  }
}

// ************************** Rounding Functions ************************** //
template <typename T>
constexpr T absolute(const T& v);
template <typename T>
constexpr T round(const T& v);
template <typename T>
constexpr T round_down(const T& v);
template <typename T>
constexpr T round_up(const T& v);

// ************************ Trigonometry Functions ************************ //
template <typename T>
constexpr T sine(const T&);
template <typename T>
constexpr T cosine(const T&);

// ************************** Calculus Functions ************************** //
template <typename T>
constexpr T exponential(const T& v);
template <typename T>
constexpr T modulo(const T& val, const T& div);
template <typename T, typename U>
constexpr T power(const T& v, const U& p);
template <typename T>
constexpr T square_root(const T& v);
}  // namespace CSTE_MATH_NAMESPACE
#endif