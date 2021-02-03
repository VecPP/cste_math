# cste_math

constexpr scalar math.

```cpp
#include "cste_math/cste_math.h"

namespace cm = cste_math;

constexpr float val = cm::sine(cm::pi<float> / 3.0f);
constexpr double val_2 = cm::square_root(3.0);
```

## Quick Start

### Prerequisites

All you need is a compiler that implements c++20's `std::is_is_constant_evaluated`.

### Installation

#### include
cste_math is a header-only library. As such, all you need to do is make the 
contents of the `include` directory available to your compiler.

#### CMake
While the cmake project is primarily used to manage tests and 
deployment, it's still set up as a proper target-exporting project. So you can 
use either `add_subdirectory(path/to/cste_math_source)` or `find_package(cste_math)` 
and use `target_link_libraries(my_target cste_math::cste_math)`.

### Usage

```cpp
#include "cste_math/cste_math.h"

void foo() {
	constexpr float sq_2 = cste::square_root(2.0f);
}
```

### Compile-time vs runtime

When you use functions defined in the root `cste` namespace, the library will 
choose wether to use a `constexpr` or an efficient runtime implementation based on context.
This is important because some `constexpr` implementations are substantially slower than their
runtime equivalent.

At first glance, that doesn't sound liek a major issue. However, because of this, the library cannot
guarantee that the result will always be the same. 

If you find yourself in a situation where you need that guarantee for whatever reason, you can force
the use of the compile-time algorithm by using the `cste::ct` namespace, at the cost of some performance.

```cpp
#include "cste_math/cste_math.h"

void foo() {
  constexpr float v_a = cste::exponential(0.1234f);
  float v_b = cste::exponential(0.1234f);

  assert(v_a == v_b); // WATCH OUT! Not necessarily the case!
}

void bar() {
  constexpr float v_a = cste::exponential(0.1234f);
  float v_b = cste::ct::exponential(0.1234f);

  assert(v_a == v_b); // Guaranteed.
}
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

## Preemptive FAQs

### f(x) is not in the library!

File a bug! Or even better, add it yourself and send us a pull request. The 
library is currently being developped on a as-needed basis.

### Why are functions not named consistently with established conventions?

`cste_math` is not guaranteed to return values that are going to 100% 
match their standard library equivalent on all platforms. Having different functions names 
helps in preventing people from assuming that could be the case.
