#include "catch.hpp"

#ifdef CSTE_MATH_TEST_SINGLE_HEADER
#include "cste_math/cste_math_single.h"
#else
#include "cste_math/cste_math.h"
#endif

#include <cmath>

using Catch::Matchers::WithinULP;

TEST_CASE("ceil is constexpr", "[ceil][constexpr]") {
  constexpr float x = cste::ceil(std::numeric_limits<float>::infinity());
  constexpr double y = std::numeric_limits<double>::quiet_NaN();
  constexpr long double z = cste::ceil(0.0L);

  (void)x;
  (void)y;
  (void)z;
}

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

TEST_CASE("very large ceil", "[ceil]") {
  REQUIRE(cste::ceil(10.0e20f) == 10.0e20f);
  REQUIRE(cste::ceil(-10.0e20f) == -10.0e20f);
}

TEST_CASE("ceil with values close to the range limit", "[ceil]") {
  REQUIRE(cste::ceil(10.0e20f) == 10.0e20f);
  REQUIRE(cste::ceil(-10.0e20f) == -10.0e20f);

  auto inf = std::numeric_limits<float>::infinity();

  double r_max = cste::pow(2.0, (std::numeric_limits<double>::digits-1));
  double r_min = cste::pow(2.0, (std::numeric_limits<double>::digits-1));

  double p_max = std::nextafter(r_max, r_min);
  double n_max = std::nextafter(r_max, inf);

  double p_min = std::nextafter(r_max, -inf);
  double n_min = std::nextafter(r_max, r_max);

  REQUIRE(cste::ceil(r_max) == std::ceil(r_max));
  REQUIRE(cste::ceil(p_max) == std::ceil(p_max));
  REQUIRE(cste::ceil(n_max) == std::ceil(n_max));

  REQUIRE(cste::ceil(r_min) == std::ceil(r_min));
  REQUIRE(cste::ceil(p_min) == std::ceil(p_min));
  REQUIRE(cste::ceil(n_min) == std::ceil(n_min));
}

TEST_CASE("ceil degenerate values", "[ceil]") {
  auto inf = std::numeric_limits<float>::infinity();
  auto nan = std::numeric_limits<float>::quiet_NaN();

  REQUIRE(cste::ceil(inf) == inf);
  REQUIRE(cste::ceil(-inf) == -inf);
  REQUIRE(std::isnan(cste::ceil(nan)));
}