#include "catch.hpp"

#ifdef CSTE_MATH_TEST_SINGLE_HEADER
#include "cste_math/cste_math_single.h"
#else
#include "cste_math/cste_math.h"
#endif

#include <cmath>

TEST_CASE("decompose_real is constexpr", "[decomp_real][constexpr]") {
  constexpr auto x = cste::decompose_real(0.0f);
  constexpr auto y = cste::exponential(1.0);
  constexpr auto z = cste::exponential(2.0L);

  (void)x;
  (void)y;
  (void)z;
}

TEST_CASE("basic decompose_real usage", "[decomp_real][basic]") {
  {
    auto [fract, exp] = cste::decompose_real(0.0f);
    REQUIRE(fract == 0.0f);
    REQUIRE(exp == 0);
  }
  {
    auto [fract, exp] = cste::decompose_real(5.0f);
    REQUIRE(fract == 0.5f);
    REQUIRE(exp == 1);
  }

  {
    auto [fract, exp] = cste::decompose_real(0.5f);
    REQUIRE(fract == 0.5f);
    REQUIRE(exp == 0);
  }


}