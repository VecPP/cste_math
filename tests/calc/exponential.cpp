#include "catch.hpp"

#ifdef CSTE_MATH_TEST_SINGLE_HEADER
#include "cste_math/cste_math_single.h"
#else
#include "cste_math/cste_math.h"
#endif

#include <cmath>

using Catch::Matchers::WithinULP;

TEST_CASE("exponential is constexpr", "[exp][constexpr]") {
  constexpr float x = cste::exponential(0.0f);
  constexpr double y = cste::exponential(1.0);
  constexpr long double z = cste::exponential(2.0L);

  (void)x;
  (void)y;
  (void)z;
}

TEST_CASE("basic exponential usage", "[exp][basic]") {
  REQUIRE(cste::exponential(0.0) == 1.0);
  REQUIRE(cste::exponential(1.0) == cste::e<double>);
}