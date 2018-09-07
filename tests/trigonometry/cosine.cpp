#include "catch.hpp"

#ifdef CSTE_MATH_TEST_SINGLE_HEADER
#include "cste_math/cste_math_single.h"
#else
#include "cste_math/cste_math.h"
#endif

#include <cmath>
#include <cstring>
#include <iostream>
#include <iomanip>

using Catch::Matchers::WithinULP;
using Catch::Matchers::WithinAbs;

TEST_CASE("cosine is constexpr", "[cosine][constexpr]") {
  constexpr float x = cste::cosine(0.0f);
  constexpr double y = cste::cosine(0.0);
  constexpr long double z = cste::cosine(0.0L);

  (void)x;
  (void)y;
  (void)z;
}

TEST_CASE("basic cosine usage", "[cosine][basic]") {
  REQUIRE_THAT(cste::cosine(0.0), WithinULP(std::cos(0.0), 1));

  // past 0
  REQUIRE_THAT(cste::cosine(0.2), WithinULP(std::cos(0.2), 1));
  REQUIRE_THAT(cste::cosine(-0.2), WithinULP(std::cos(-0.2), 1));

  // Past pi/4
  REQUIRE_THAT(cste::cosine(1.14), WithinULP(std::cos(1.14), 1));  
  REQUIRE_THAT(cste::cosine(-1.14), WithinULP(std::cos(-1.14), 1));
}

TEST_CASE("cosine(x), x > pi/2", "[cosine]") {
  REQUIRE_THAT(cste::cosine(2.5), WithinULP(std::cos(2.5), 1));
  REQUIRE_THAT(cste::cosine(-2.5), WithinULP(std::cos(-2.5), 1));  
}

TEST_CASE("cosine(x), x > pi", "[cosine]") {
  for(int i = 1 ; i < 100000; i ++) {
    double v = cste::pi<double> * i;
    // This is not great, but the idea is that we try to roughly account
    // for the error in i*pi
    if(i % 2) {
      REQUIRE_THAT(cste::cosine(v), WithinAbs(-1.0, 1.e-15 * (double)i));
    }
    else {
      REQUIRE_THAT(cste::cosine(v), WithinAbs(1.0, 1.e-15 * (double)i));
    }
  }

}
