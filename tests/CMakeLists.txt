include_directories(.)

add_library(catch_main catch_main.cpp)
set_target_properties(catch_main PROPERTIES FOLDER "tests")

SET( CSTE_MATH_TESTS
  calc/exp.cpp

  rounding/ceil.cpp
  rounding/floor.cpp

  trigonometry/cosine.cpp
  trigonometry/sine.cpp
)

MACRO(config_test_target TGT)

target_link_libraries(${TGT} catch_main cste_math::cste_math)
set_target_properties(${TGT} PROPERTIES FOLDER "tests")
add_test(${TGT} ${TGT})

if(MSVC)
  target_compile_options(${TGT} PRIVATE /W4 /WX)
else(MSVC)
  target_compile_options(${TGT} PRIVATE -Wall -Wextra -pedantic -Werror)
endif(MSVC)
endmacro()

add_executable(all_tests ${CSTE_MATH_TESTS})
config_test_target(all_tests)

if(CSTE_MATH_BUILD_SINGLE_HEADER)
  add_executable(all_tests_sh ${CSTE_MATH_TESTS})
  target_include_directories(all_tests_sh PRIVATE ${CMAKE_CURRENT})
  target_compile_definitions(all_tests_sh
    PRIVATE CSTE_MATH_TEST_SINGLE_HEADER
  )
  add_dependencies(all_tests_sh generate_single_include)
  config_test_target(all_tests_sh)
endif()
