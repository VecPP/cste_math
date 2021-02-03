include_directories(.)

add_library(doctest_main doctest_main.cpp)

SET( CSTE_MATH_TESTS
  calc/exponential.cpp

  rounding/round_up.cpp
  rounding/round_down.cpp

  trigonometry/cosine.cpp
  trigonometry/sine.cpp
)

add_executable(cste_math_tests ${CSTE_MATH_TESTS})
target_link_libraries(cste_math_tests doctest_main cste_math::cste_math)
add_test(cste_math_tests cste_math_tests)

if(MSVC)
    target_compile_options(cste_math_tests PRIVATE /W4 /WX)
else(MSVC)
    target_compile_options(cste_math_tests PRIVATE -Wall -Wextra -pedantic -Werror)
endif(MSVC)