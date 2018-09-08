//  Copyright 2018 Francois Chabot
//  (francois.chabot.dev@gmail.com)
//
//  Distributed under the Boost Software License, Version 1.0.
//  (See accompanying file LICENSE or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
#ifndef CSTE_MATH_SINGLE_INCLUDE_H_
#define CSTE_MATH_SINGLE_INCLUDE_H_
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <type_traits>

#ifdef _MSVC_LANG
#if _MSVC_LANG < 201703L
#error C++17 support is required
#endif
#elif __cplusplus < 201703L
#error C++17 support is required
#endif
#ifndef CSTE_MATH_NAMESPACE
#define CSTE_MATH_NAMESPACE cste
#endif

namespace CSTE_MATH_NAMESPACE {
template <typename T>
constexpr T pi = T(3.14159265358979323846264338327950288419L);
template <typename T>
constexpr T half_pi = pi<T> / T(2);
template <typename T>
constexpr T quarter_pi = pi<T> / T(4);
template <typename T>
constexpr T two_pi = pi<T>* T(2);
template <typename T>
constexpr T e = T(2.71828182845904523536028747135266249775724709L);
}  // namespace CSTE_MATH_NAMESPACE

namespace CSTE_MATH_NAMESPACE {
template <typename T>
constexpr T sign(const T& v);
template <typename T>
constexpr bool is_nan(const T& v);
template <typename T>
constexpr bool is_inf(const T& v);
template <typename T>
constexpr T absolute(const T& v);
template <typename T>
constexpr T fractional(const T& v);
template <typename T>
constexpr T round(const T& v);
template <typename T>
constexpr T round_down(const T& v);
template <typename T>
constexpr T round_up(const T& v);
template <typename T>
constexpr T truncate(const T& v);
template <typename T>
constexpr T sine(const T&);
template <typename T>
constexpr T cosine(const T&);
template <typename T>
constexpr T exponential(const T& v);
template <typename T>
constexpr T modulo(const T& val, const T& div);
template <typename T, typename U>
constexpr T power(const T& v, const U& p);
template <typename T>
constexpr T square_root(const T& v);
}  // namespace CSTE_MATH_NAMESPACE

namespace CSTE_MATH_NAMESPACE {
template <typename T, typename U>
constexpr T power(const T& v, const U& p) {
  if constexpr (std::is_integral<U>()) {
    T result = 1;
    for (U i = 0; i < p; ++i) {
      result *= v;
    }
    return result;
  } else {
    assert(false);
    return v;
  }
}
}  // namespace CSTE_MATH_NAMESPACE

namespace CSTE_MATH_NAMESPACE {
template <typename T>
constexpr bool is_nan(const T& v) {
  return !(v == v);
}
template <typename T>
constexpr bool is_inf(const T& v) {
  constexpr T inf = std::numeric_limits<T>::infinity();
  return v == inf || v == -inf;
}
}  // namespace CSTE_MATH_NAMESPACE

namespace CSTE_MATH_NAMESPACE {
template <typename T>
constexpr T round_down(const T& v) {
  constexpr T range_max = power(T(2), (std::numeric_limits<T>::digits - 1));
  constexpr T range_min = -range_max;
  if (v >= range_max || v <= range_min || is_nan(v)) {
    return v;
  }
  long long int x = static_cast<long long int>(v);
  if (v == T(x) || v > T(0)) {
    return T(x);
  }
  return T(x - 1);
}
}  // namespace CSTE_MATH_NAMESPACE

namespace CSTE_MATH_NAMESPACE {
namespace exp_details {
constexpr long double recur_helper(long double x, long double num,
                                   long double fact, std::size_t i) {
  fact *= i;
  num *= x;
  long double factor = num / fact;
  if (factor == 0.0L) {
    return 0.0L;
  }
  return factor + recur_helper(x, num, fact, i + 1);
}
}  // namespace exp_details
template <typename T>
constexpr T exponential(const T& v) {
  long double v_p = v;
  bool neg = v < 0;
  if (neg) {
    v_p = -v_p;
  }
  // separate integral and fractional components
  uint32_t integral = uint32_t(round_down(v));
  long double fract = v_p - integral;
  long double int_val = 1;
  long double e_fact = e<long double>;
  while (integral != 0) {
    if (integral & 1) {
      int_val *= e_fact;
    }
    integral >>= 1;
    e_fact *= e<long double>;
  }
  long double fract_val = exp_details::recur_helper(fract, 1, 1, 1) + 1.0L;
  long double result = fract_val * int_val;
  return T(neg ? 1.0L / result : result);
}
}  // namespace CSTE_MATH_NAMESPACE

namespace CSTE_MATH_NAMESPACE {
template <typename T>
constexpr T sign(const T& v) {
  // https://stackoverflow.com/a/4609795/4442671
  return (T(0) < v) - (v < T(0));
}
}  // namespace CSTE_MATH_NAMESPACE

namespace CSTE_MATH_NAMESPACE {
template <typename T>
constexpr T absolute(const T& v) {
  return v < 0 ? -v : v;
}
}  // namespace CSTE_MATH_NAMESPACE

namespace CSTE_MATH_NAMESPACE {
template <typename T>
constexpr T truncate(const T& v) {
  constexpr T range_max = power(T(2), (std::numeric_limits<T>::digits - 1));
  constexpr T range_min = -range_max;
  if (v >= range_max || v <= range_min || is_nan(v)) {
    return v;
  }
  long long int x = static_cast<long long int>(v);
  if (v == T(x) || v > T(0)) {
    return T(x);
  }
  return T(x - 1);
}
}  // namespace CSTE_MATH_NAMESPACE

namespace CSTE_MATH_NAMESPACE {
template <typename T>
constexpr T fractional(const T& val) {
  return val - truncate(val);
}
}  // namespace CSTE_MATH_NAMESPACE

namespace CSTE_MATH_NAMESPACE {
template <typename T>
constexpr T round(const T& v) {
  return round_down(v + T(0.5));
}
}  // namespace CSTE_MATH_NAMESPACE

namespace CSTE_MATH_NAMESPACE {
template <typename T>
constexpr T round_up(const T& v) {
  constexpr T range_max = power(T(2), (std::numeric_limits<T>::digits - 1));
  constexpr T range_min = -range_max;
  if (v >= range_max || v <= range_min || is_nan(v)) {
    return v;
  }
  long long int x = static_cast<long long int>(v);
  if (v == T(x) || v < T(0)) {
    return T(x);
  }
  return T(x + 1);
}
}  // namespace CSTE_MATH_NAMESPACE

namespace CSTE_MATH_NAMESPACE {
template <typename T>
constexpr T modulo(const T& val, const T& div) {
  if constexpr (std::is_integral_v<T>) {
    return val % div;
  } else {
    return val - round_down(val / div) * div;
  }
}
}  // namespace CSTE_MATH_NAMESPACE

namespace CSTE_MATH_NAMESPACE {
namespace cosine_detail {
constexpr long double recur_helper(long double r_2, long double num,
                                   long double fact, std::size_t i) {
  fact *= (i - 1);
  fact *= (i);
  num *= r_2;
  long double factor = num / fact;
  if (factor == 0.0L) {
    return 0.0;
  }
  return factor + recur_helper(r_2, num, fact, i + 2);
}
}  // namespace cosine_detail
template <typename T>
constexpr T cosine_pi4(const T& rad) {
  assert(rad >= -quarter_pi<T> && rad <= quarter_pi<T>);
  // Promote to long double
  long double r = rad;
  long double r_2 = r * r * -1.0;
  return cosine_detail::recur_helper(r_2, 1, 1.0L, 2) + 1.0L;
}
}  // namespace CSTE_MATH_NAMESPACE

namespace CSTE_MATH_NAMESPACE {
namespace sine_detail {
constexpr long double recur_helper(long double r_2, long double num,
                                   double fact, std::size_t i) {
  fact *= (i - 1);
  fact *= (i);
  num *= r_2;
  long double factor = num / fact;
  if (factor == 0.0L) {
    return 0.0;
  }
  return factor + recur_helper(r_2, num, fact, i + 2);
}
}  // namespace sine_detail
template <typename T>
constexpr T sine_pi4(const T& rad) {
  assert(rad >= -quarter_pi<T> && rad <= quarter_pi<T>);
  // Promote to long double
  long double r = rad;
  return sine_detail::recur_helper(r * r * -1.0L, r, 1.0L, 3) + r;
}
}  // namespace CSTE_MATH_NAMESPACE

namespace CSTE_MATH_NAMESPACE {
template <typename T>
constexpr T cosine(const T& rad) {
  if (is_nan(rad)) {
    return rad;
  }
  if (is_inf(rad)) {
    return std::numeric_limits<T>::signaling_NaN();
  }
  long double r = rad;
  // Remap into the -PI->PI range.
  if (r > pi<T>) {
    r = modulo(rad, two_pi<T>);
  } else if (r < -pi<T>) {
    r = modulo(rad, -two_pi<T>);
  }
  if (r > pi<long double>) {
    r -= two_pi<long double>;
  } else if (r < -pi<long double>) {
    r += two_pi<long double>;
  }
  // Remap into the -PI/2->PI/2 range.
  long double neg = 1.0L;
  if (r > half_pi<long double>) {
    r -= pi<T>;
    neg = -1.0L;
  } else if (r < -half_pi<long double>) {
    r += pi<T>;
    neg = -1.0L;
  }
  if (r < -quarter_pi<long double>) {
    return T(neg * sine_pi4(r + half_pi<long double>));
  } else if (r > quarter_pi<long double>) {
    return T(neg * -sine_pi4(r - half_pi<long double>));
  }
  return T(neg * cosine_pi4(r));
}
}  // namespace CSTE_MATH_NAMESPACE

namespace CSTE_MATH_NAMESPACE {
template <typename T>
constexpr T sine(const T& rad) {
  if (is_nan(rad)) {
    return rad;
  }
  if (is_inf(rad)) {
    return std::numeric_limits<T>::signaling_NaN();
  }
  long double r = rad;
  // Remap into the -PI->PI range.
  if (r > pi<long double>) {
    r = modulo(r, two_pi<long double>);
  } else if (r < -pi<long double>) {
    r = modulo(r, -two_pi<long double>);
  }
  if (r > pi<long double>) {
    r -= two_pi<long double>;
  } else if (r < -pi<long double>) {
    r += two_pi<long double>;
  }
  // Remap into the -PI/2->PI/2 range.
  if (r > half_pi<long double>) {
    r = pi<T> - r;
  } else if (r < -half_pi<long double>) {
    r = -pi<T> - r;
  }
  if (r < -quarter_pi<long double>) {
    return T(-cosine_pi4(r + half_pi<long double>));
  } else if (r > quarter_pi<long double>) {
    return T(cosine_pi4(r - half_pi<long double>));
  }
  return T(sine_pi4(r));
}
}  // namespace CSTE_MATH_NAMESPACE

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
  constexpr T fmod(const T& arg) {
    return modulo(arg);
  }
  template<typename T>
  constexpr T fract(const T& arg) {
    return fractional(arg);
  }
  template<typename T>
  constexpr T round(const T& arg) {
    return round_nearest(arg);
  }
  template<typename T>
  constexpr T trunc(const T& arg) {
    return truncate(arg);
  }
  template<typename T>
  constexpr T sqrt(const T& arg) {
    return square_root(arg);
  }
}
}  // namespace CSTE_MATH_NAMESPACE


#endif
