#include "doctest.h"

#include "vecpp/cste_math/cste_math.h"

#include <cmath>
#include <vector>

using cste::ct::round_down;


TEST_CASE("floor is constexpr") {
  constexpr float x = round_down(0.0f);
  constexpr double y = round_down(0.0);
  constexpr long double z = round_down(0.0L);

  (void)x;
  (void)y;
  (void)z;
}


TEST_CASE("basic floor usage") {
  std::vector<double> values = {-12.5,
                                -1.0,
                                -0.8,
                                -0.5,
                                -0.1,
                                0.0,
                                0.1,
                                0.5,
                                0.8,
                                1.0,
                                12.5,
                                std::nextafter(1.0, 2.0),
                                std::nextafter(1.0, 2.0),
                                std::nextafter(1.0, 0.0),
                                std::nextafter(-1.0, -2.0),
                                std::nextafter(-1.0, 0.0)};

  for (auto v : values) {
    CHECK(round_down(v) == std::floor(v));
  }
}

TEST_CASE("floor with values close to the range limit") {
  CHECK(round_down(10.0e20f) == 10.0e20f);
  CHECK(round_down(-10.0e20f) == -10.0e20f);

  auto inf = std::numeric_limits<float>::infinity();

  double r_max = cste::power(2.0, (std::numeric_limits<double>::digits-1));
  double r_min = cste::power(2.0, (std::numeric_limits<double>::digits-1));

  double p_max = std::nextafter(r_max, r_min);
  double n_max = std::nextafter(r_max, inf);

  double p_min = std::nextafter(r_max, -inf);
  double n_min = std::nextafter(r_max, r_max);

  CHECK(round_down(r_max) == std::floor(r_max));
  CHECK(round_down(p_max) == std::floor(p_max));
  CHECK(round_down(n_max) == std::floor(n_max));

  CHECK(round_down(r_min) == std::floor(r_min));
  CHECK(round_down(p_min) == std::floor(p_min));
  CHECK(round_down(n_min) == std::floor(n_min));
}

TEST_CASE("very large constexpr floor") {
  CHECK(round_down(10.0e20f) == 10.0e20f);
  CHECK(round_down(-10.0e20f) == -10.0e20f);
}

TEST_CASE("floor degenerate values") {
  auto inf = std::numeric_limits<float>::infinity();
  auto nan = std::numeric_limits<float>::quiet_NaN();

  CHECK(round_down(inf) == inf);
  CHECK(round_down(-inf) == -inf);
  CHECK(std::isnan(round_down(nan)));
}
