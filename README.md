# cste_math

constexpr scalar math

## Floating point precision

For v1, We aim to provide as much precision as acheivable when employing the library with `float` or `double`, in both normal and `-ffast-math` compilation mode.

## Origin

cste_math was spun off from [VecPP](https://github.com/VecPP/vecpp). The
distinction between compile-time and runtime algorithms was getting messy, so
isolating the constexpr algorithms was needed. We decided we might as well make 
it a distinct repository.
