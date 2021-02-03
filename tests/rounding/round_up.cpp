#include "doctest.h"

#include "vecpp/cste_math/cste_math.h"

#include <cmath>
#include <vector>


using cste::ct::round_up;

TEST_CASE("ceil is constexpr") {
  constexpr float x = round_up(std::numeric_limits<float>::infinity());
  constexpr double y = std::numeric_limits<double>::quiet_NaN();
  constexpr long double z = round_up(0.0L);

  (void)x;
  (void)y;
  (void)z;
}

TEST_CASE("basic ceil usage") {
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
    CHECK(round_up(v) == std::ceil(v));
  }
}

TEST_CASE("very large ceil") {
  CHECK(round_up(10.0e20f) == 10.0e20f);
  CHECK(round_up(-10.0e20f) == -10.0e20f);
}

TEST_CASE("ceil with values close to the range limit") {
  CHECK(round_up(10.0e20f) == 10.0e20f);
  CHECK(round_up(-10.0e20f) == -10.0e20f);

  auto inf = std::numeric_limits<float>::infinity();

  double r_max = cste::power(2.0, (std::numeric_limits<double>::digits-1));
  double r_min = cste::power(2.0, (std::numeric_limits<double>::digits-1));

  double p_max = std::nextafter(r_max, r_min);
  double n_max = std::nextafter(r_max, inf);

  double p_min = std::nextafter(r_max, -inf);
  double n_min = std::nextafter(r_max, r_max);

  CHECK(round_up(r_max) == std::ceil(r_max));
  CHECK(round_up(p_max) == std::ceil(p_max));
  CHECK(round_up(n_max) == std::ceil(n_max));

  CHECK(round_up(r_min) == std::ceil(r_min));
  CHECK(round_up(p_min) == std::ceil(p_min));
  CHECK(round_up(n_min) == std::ceil(n_min));
}

TEST_CASE("ceil degenerate values") {
  auto inf = std::numeric_limits<float>::infinity();
  auto nan = std::numeric_limits<float>::quiet_NaN();

  CHECK(round_up(inf) == inf);
  CHECK(round_up(-inf) == -inf);
  CHECK(std::isnan(round_up(nan)));
}