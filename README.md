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
VecPP is a header-only library. As such, all you need to do is make the 
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
```

## Floating point precision

For v1, We aim to provide as much precision as achievable when employing the 
library with `float` or `double`, in both normal and `-ffast-math` compilation 
mode.

## Origin

cste_math was spun off from [VecPP](https://github.com/VecPP/vecpp). The
distinction between compile-time and runtime algorithms was getting messy, so
isolating the constexpr algorithms was needed. We decided we might as well make 
it a distinct repository.
