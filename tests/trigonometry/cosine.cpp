#include "doctest.h"

#include "vecpp/cste_math/cste_math.h"

#include <cmath>

using cste::ct::cosine;

TEST_CASE("sine is constexpr") {
  constexpr float x = cosine(0.0f);
  constexpr double y = cosine(0.0);
  constexpr long double z = cosine(0.0L);

  (void)x;
  (void)y;
  (void)z;
}

TEST_CASE("basic sine usage") {
  CHECK(cosine(0.0) == std::cos(0.0));

  // past 0
  CHECK(cosine(0.2) == doctest::Approx(std::cos(0.2)));
  CHECK(cosine(-0.2) == doctest::Approx(std::cos(-0.2)));

  // Past pi/4
  CHECK(cosine(1.14) == doctest::Approx(std::cos(1.14)));
  CHECK(cosine(-1.14) == doctest::Approx(std::cos(-1.14)));
}

TEST_CASE("sine(x), x > pi/2") {
  CHECK(cosine(2.5) == doctest::Approx(std::cos(2.5)));
  CHECK(cosine(-2.5) == doctest::Approx(std::cos(-2.5)));
}

TEST_CASE("sine(x), x > pi") {
  for (int i = 1; i < 100000; i++) {
    double v = cste::pi<double> * i;

    // This is not great, but the idea is that we try to roughly account
    // for the error in i*pi
    CHECK(cosine(v) == doctest::Approx(std::cos(v)));
  }
}

TEST_CASE("cosine(LARGE) can lead to an inf during constexpr eval") {
  constexpr long double x = cosine(cste::half_pi<long double>);
  constexpr long double y = cosine(-cste::half_pi<long double>);
  (void)x;
  (void)y;
}