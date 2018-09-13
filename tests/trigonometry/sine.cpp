#include "catch.hpp"

#ifdef CSTE_MATH_TEST_SINGLE_HEADER
#include "vecpp/cste_math/cste_math_single.h"
#else
#include "vecpp/cste_math/cste_math.h"
#endif

#include <cmath>
#include <cstring>
#include <iostream>
#include <iomanip>

using Catch::Matchers::WithinULP;
using Catch::Matchers::WithinAbs;

TEST_CASE("sine is constexpr", "[sine][constexpr]") {
  constexpr float x = cste::sine(0.0f);
  constexpr double y = cste::sine(0.0);
  constexpr long double z = cste::sine(0.0L);

  (void)x;
  (void)y;
  (void)z;
}

TEST_CASE("basic sine usage", "[sine][basic]") {
  REQUIRE_THAT(cste::sine(0.0), WithinULP(std::sin(0.0), 1));

  // past 0
  REQUIRE_THAT(cste::sine(0.2), WithinULP(std::sin(0.2), 1));
  REQUIRE_THAT(cste::sine(-0.2), WithinULP(std::sin(-0.2), 1));

  // Past pi/4
  REQUIRE_THAT(cste::sine(1.14), WithinULP(std::sin(1.14), 1));  
  REQUIRE_THAT(cste::sine(-1.14), WithinULP(std::sin(-1.14), 1));
}

TEST_CASE("sine(x), x > pi/2", "[sine]") {
  REQUIRE_THAT(cste::sine(2.5), WithinULP(std::sin(2.5), 1));
  REQUIRE_THAT(cste::sine(-2.5), WithinULP(std::sin(-2.5), 1));  
}

TEST_CASE("sine(x), x > pi", "[sine]") {
  for(int i = 1 ; i < 100000; i ++) {
    double v = cste::pi<double> * i;

    // This is not great, but the idea is that we try to roughly account
    // for the error in i*pi
    REQUIRE_THAT(cste::sine(v), WithinAbs(0.0, 1.e-15 * (double)i));
  }

}
