#include "catch.hpp"

#ifdef CSTE_MATH_TEST_SINGLE_HEADER
#include "cste_math/cste_math_single.h"
#else
#include "cste_math/cste_math.h"
#endif

#include <cmath>

using Catch::Matchers::WithinULP;

TEST_CASE("basic floor usage", "[floor][basic]") {
  REQUIRE(cste::floor(0.0) == 0.0);
  REQUIRE_THAT(cste::floor(1.0), WithinULP(1.0, 1));
  REQUIRE_THAT(cste::floor(2.0), WithinULP(2.0, 1));
  REQUIRE_THAT(cste::floor(-1.0), WithinULP(-1.0, 1));
  REQUIRE_THAT(cste::floor(-2.0), WithinULP(-2.0, 1));

  // Barely above and below
  REQUIRE_THAT(cste::floor(std::nextafter(1.0, 2.0)), WithinULP(1.0, 1));
  REQUIRE_THAT(cste::floor(std::nextafter(1.0, 0.0)), WithinULP(0.0, 1));
}

TEST_CASE("very large constexpr floor", "[floor]") {
  REQUIRE(cste::floor(10.0e20f) == 10.0e20f);
  REQUIRE(cste::floor(-10.0e20f) == -10.0e20f);
}

TEST_CASE("floor degenerate values", "[floor]") {
  auto inf = std::numeric_limits<float>::infinity();
  auto nan = std::numeric_limits<float>::quiet_NaN();

  REQUIRE(cste::floor(inf) == inf);
  REQUIRE(cste::floor(-inf) == -inf);
  REQUIRE(std::isnan(cste::floor(nan)));
}