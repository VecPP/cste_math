//  Copyright 2018 Francois Chabot
//  (francois.chabot.dev@gmail.com)
//
//  Distributed under the Boost Software License, Version 1.0.
//  (See accompanying file LICENSE or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

#ifndef CSTE_FUNCTIONS_H_INCLUDED
#define CSTE_FUNCTIONS_H_INCLUDED

#include "cste_math/config.h"

namespace CSTE_MATH_NAMESPACE {

// ************************** Misc Functions ************************** //
template <typename T>
constexpr T sign(const T& v);
template <typename T>
constexpr bool is_nan(const T& v);
template <typename T>
constexpr bool is_inf(const T& v);

// ************************** Rounding Functions ************************** //
template <typename T>
constexpr T absolute(const T& v);
template <typename T>
constexpr T round(const T& v);
template <typename T>
constexpr T round_down(const T& v);
template <typename T>
constexpr T round_up(const T& v);
template <typename T>
constexpr T truncate(const T& v);

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