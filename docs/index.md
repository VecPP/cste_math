# cste_math

## Installation

### Prerequisites

All you need is a standard compliant C++17 compiler.

### include
cste_math is a header-only library. As such, all you need to do is make the 
contents of the `include` directory available to your compiler.

### single-include
Alternatively, you can simply copy "cste_math_single.h" into your project and use 
that single freestanding header.

## Reference

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
