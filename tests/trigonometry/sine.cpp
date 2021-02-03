#include "doctest.h"

#include "vecpp/cste_math/cste_math.h"

#include <cmath>

using cste::ct::sine;


TEST_CASE("sine is constexpr") {
  constexpr float x = sine(0.0f);
  constexpr double y = sine(0.0);
  constexpr long double z = sine(0.0L);

  (void)x;
  (void)y;
  (void)z;
}

TEST_CASE("basic sine usage") {
  CHECK(sine(0.0) == std::sin(0.0));

  // past 0
  CHECK(sine(0.2) == doctest::Approx(std::sin(0.2)));
  CHECK(sine(-0.2) == doctest::Approx(std::sin(-0.2)));

  // Past pi/4
  CHECK(sine(1.14) == doctest::Approx(std::sin(1.14)));
  CHECK(sine(-1.14) == doctest::Approx(std::sin(-1.14)));
}

TEST_CASE("sine(x), x > pi/2") {
  CHECK(sine(2.5) == doctest::Approx(std::sin(2.5)));
  CHECK(sine(-2.5) == doctest::Approx(std::sin(-2.5)));
}

TEST_CASE("sine(x), x > pi") {
  for(int i = 1 ; i < 100000; i ++) {
    double v = cste::pi<double> * i;

    // This is not great, but the idea is that we try to roughly account
    // for the error in i*pi
    CHECK(sine(v) == doctest::Approx(std::sin(v)));
  }

}
