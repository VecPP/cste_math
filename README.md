# cste_math

constexpr scalar math.

[![Build Status](https://travis-ci.com/VecPP/cste_math.svg?branch=master)](https://travis-ci.com/VecPP/cste_math)
[![CircleCI](https://circleci.com/gh/VecPP/cste_math.svg?style=svg)](https://circleci.com/gh/VecPP/cste_math)
[![Build status](https://ci.appveyor.com/api/projects/status/hfidx2nn06jc480k/branch/master?svg=true)](https://ci.appveyor.com/project/FrancoisChabot/cste-math/branch/master)

```cpp
#include "cste_math/cste_math.h"

namespace cm = cste_math;

constexpr float val = cm::sine(cm::pi<float> * 0.5f);
constexpr float val_2 = cm::square_root(3.0f);
```

## Quick Start

### Prerequisites

All you need is a standard compliant C++17 compiler. The library is 
sytematically tested on the following compilers, but that does not mean that 
earlier versions will not work.

Compiler | Version
---------|--------
GCC      | 7.3.0
clang    | 6.0.0
MSVC     | 14.15.26726

### Installation

#### include
cste_math is a header-only library. As such, all you need to do is make the 
contents of the `include` directory available to your compiler.

#### single-include
Alternatively, you can simply copy "cste_math_single.h" into your project and use 
that single freestanding header. (if you are cloning the raw source, you will
need to generate it using `-DCSTE_MATH_BUILD_SINGLE_HEADER`).

#### CMake
Finally, while the cmake project is primarily used to manage tests and 
deployment, it's still set up as a proper target-exporting project. So you can 
use either `add_subdirectory(path/to/cste_math_source)` or `find_package(cste_math)` 
and use `target_link_libraries(my_target cste_math::cste_math)`.

### Usage

```cpp
#include "cste_math/cste_math.h"

constexpr float sq_2 = cste::square_root(2.0f);
```

## Quick Reference

### Constants

How                 | What
--------------------|--------------------
`e<T>`              | e
`pi<T>`             | π
`two_pi<T>`         | 2π
`half_pi<T>`        | π/2
`quarter_pi<T>`     | π/4
`two_pi<T>`         | 2π

### Calculus

How                                       | What
------------------------------------------|-------------------
`T absolute(const T& x);`                 | \|x\|
`T exponential(const T& x);`              | e<sup>x</sup>
`T modulo(const T& x, const T& y);`       | remainder of x/y
`T power(const T& x, const T& y);`        | x<sup>y</sup>
`T square_root(const T& x);`              | √x

### Number identification

How                                       | What
------------------------------------------|-------------------
`bool is_inf(const T& x);`                | Checks for infinity
`bool is_nan(const T& x);`                | Checks for nan
`T sign(const T& x);`                     | negative: -1, positive: 1, zero: 0

### Rounding

How                                       | What
------------------------------------------|-------------------
`T round_up(const T& x);`                 | round number up
`T round_down(const T& x);`               | round number down
`T round(const T& x);`                    | round number to closest integer
`T truncate(const T& x);`                 | round number towards 0
`T fractional(const T& x);`               | The fractional part of the number

### Trigonometry functions

How                                       | What
------------------------------------------|-------------------
`T sine(const T& rad);`                   | sin(rad)
`T cosine(const T& rad);`                 | cos(rad)
`T tangent(const T& rad);`                | tan(rad)
