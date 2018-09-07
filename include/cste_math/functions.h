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

// ************************** Rounding Functions ************************** //
template <typename T>
constexpr T ceil(const T& v);
template <typename T>
constexpr T floor(const T& v);

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
}  // namespace VECPP_NAMESPACE
#endif