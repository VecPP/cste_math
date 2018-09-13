//  Copyright 2018 Francois Chabot
//  (francois.chabot.dev@gmail.com)
//
//  Distributed under the Boost Software License, Version 1.0.
//  (See accompanying file LICENSE or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

#ifndef VECPP_CSTE_MATH_CONFIG_H_INCLUDED
#define VECPP_CSTE_MATH_CONFIG_H_INCLUDED

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

#endif