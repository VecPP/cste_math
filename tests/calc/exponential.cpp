#include "doctest.h"

#include "vecpp/cste_math/cste_math.h"

#include <cmath>

using cste::ct::exponential;


TEST_CASE("exponential is constexpr") {
  constexpr float x = exponential(0.0f);
  constexpr double y = exponential(1.0);
  constexpr long double z = exponential(2.0L);

  (void)x;
  (void)y;
  (void)z;
}

TEST_CASE("basic exponential usage") {
  CHECK(exponential(0.0) == 1.0);
  CHECK(exponential(1.0) == cste::e<double>);
  CHECK(exponential(2.5) == doctest::Approx(12.1824939607));

  CHECK(exponential(-0.32) == doctest::Approx(0.72614903707));
}