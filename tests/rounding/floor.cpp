#include "catch.hpp"

#ifdef CSTE_MATH_TEST_SINGLE_HEADER
#include "cste_math/cste_math_single.h"
#else
#include "cste_math/cste_math.h"
#endif

#include <cmath>

using Catch::Matchers::WithinULP;

TEST_CASE("floor is constexpr", "[floor][constexpr]") {
  constexpr float x = cste::floor(0.0f);
  constexpr double y = cste::floor(0.0);
  constexpr long double z = cste::floor(0.0L);

  (void)x;
  (void)y;
  (void)z;
}

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

TEST_CASE("floor with values close to the range limit", "[floor]") {
  REQUIRE(cste::floor(10.0e20f) == 10.0e20f);
  REQUIRE(cste::floor(-10.0e20f) == -10.0e20f);

  auto inf = std::numeric_limits<float>::infinity();

  double r_max = cste::pow(2.0, (std::numeric_limits<double>::digits-1));
  double r_min = cste::pow(2.0, (std::numeric_limits<double>::digits-1));

  double p_max = std::nextafter(r_max, r_min);
  double n_max = std::nextafter(r_max, inf);

  double p_min = std::nextafter(r_max, -inf);
  double n_min = std::nextafter(r_max, r_max);

  REQUIRE(cste::floor(r_max) == std::floor(r_max));
  REQUIRE(cste::floor(p_max) == std::floor(p_max));
  REQUIRE(cste::floor(n_max) == std::floor(n_max));

  REQUIRE(cste::floor(r_min) == std::floor(r_min));
  REQUIRE(cste::floor(p_min) == std::floor(p_min));
  REQUIRE(cste::floor(n_min) == std::floor(n_min));
}

TEST_CASE("very large constexpr floor", "[floor][large]") {
  REQUIRE(cste::floor(10.0e20f) == 10.0e20f);
  REQUIRE(cste::floor(-10.0e20f) == -10.0e20f);
}

TEST_CASE("floor degenerate values", "[floor][degen]") {
  auto inf = std::numeric_limits<float>::infinity();
  auto nan = std::numeric_limits<float>::quiet_NaN();

  REQUIRE(cste::floor(inf) == inf);
  REQUIRE(cste::floor(-inf) == -inf);
  REQUIRE(std::isnan(cste::floor(nan)));
}