#include "catch.hpp"

#ifdef CSTE_MATH_TEST_SINGLE_HEADER
#include "cste_math/cste_math_single.h"
#else
#include "cste_math/cste_math.h"
#endif

#include <cmath>

using Catch::Matchers::WithinULP;

TEST_CASE("basic ceil usage", "[ceil][basic]") {
  REQUIRE(cste::ceil(0.0) == 0.0);
  REQUIRE_THAT(cste::ceil(1.0), WithinULP(1.0, 1));
  REQUIRE_THAT(cste::ceil(2.0), WithinULP(2.0, 1));
  REQUIRE_THAT(cste::ceil(-1.0), WithinULP(-1.0, 1));
  REQUIRE_THAT(cste::ceil(-2.0), WithinULP(-2.0, 1));

  // Barely above and below
  REQUIRE_THAT(cste::ceil(std::nextafter(1.0, 2.0)), WithinULP(2.0, 1));
  REQUIRE_THAT(cste::ceil(std::nextafter(1.0, 0.0)), WithinULP(1.0, 1));
}

TEST_CASE("very large constexpr ceil", "[ceil]") {
  REQUIRE(cste::ceil(10.0e20f) == 10.0e20f);
  REQUIRE(cste::ceil(-10.0e20f) == -10.0e20f);
}

TEST_CASE("ceil degenerate values", "[ceil]") {
  auto inf = std::numeric_limits<float>::infinity();
  auto nan = std::numeric_limits<float>::quiet_NaN();

  REQUIRE(cste::ceil(inf) == inf);
  REQUIRE(cste::ceil(-inf) == -inf);
  REQUIRE(std::isnan(cste::ceil(nan)));
}