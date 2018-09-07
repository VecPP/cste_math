#include "catch.hpp"

#ifdef CSTE_MATH_TEST_SINGLE_HEADER
#include "cste_math/cste_math_single.h"
#else
#include "cste_math/cste_math.h"
#endif

#include <cmath>

using Catch::Matchers::WithinULP;

TEST_CASE("exp is constexpr", "[exp][constexpr]") {
  constexpr float x = cste::exp(0.0f);
  constexpr double y = cste::exp(1.0);
  constexpr long double z = cste::exp(2.0L);

  (void)x;
  (void)y;
  (void)z;
}

TEST_CASE("basic exp usage", "[exp][basic]") {
  REQUIRE(cste::exp(0.0) == 1.0);
  REQUIRE(cste::exp(1.0) == cste::e<double>);
}