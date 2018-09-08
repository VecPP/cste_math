cmake_minimum_required(VERSION 3.9)

project(cste_math 
  VERSION 0.1
  DESCRIPTION "C++ constexpr math"
  LANGUAGES CXX)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

option(CSTE_MATH_BUILD_SINGLE_HEADER "Build the cste_math_single.h header" OFF)
option(CSTE_MATH_BUILD_DOCS "Build documentation" OFF)
option(CSTE_MATH_BUILD_TESTS "Build tests" OFF)
option(CSTE_MATH_BUILD_PACKAGE "Build Release Package" OFF)

SET(CSTE_MATH_HEADERS
  include/cste_math/calc/exponential.h
  include/cste_math/calc/modulo.h
  include/cste_math/calc/power.h
  include/cste_math/calc/square_root.h

  include/cste_math/misc/inf_nan.h
  include/cste_math/misc/sign.h
  
  include/cste_math/rounding/absolute.h
  include/cste_math/rounding/round.h
  include/cste_math/rounding/round_down.h
  include/cste_math/rounding/round_up.h
  include/cste_math/rounding/truncate.h
 
  include/cste_math/trigonometry/bound/cosine_pi4.h
  include/cste_math/trigonometry/bound/sine_pi4.h
  include/cste_math/trigonometry/cosine.h
  include/cste_math/trigonometry/sine.h

  include/cste_math/config.h
  include/cste_math/constants.h
  include/cste_math/cste_math.h
  include/cste_math/functions.h
)

if(CSTE_MATH_BUILD_DOCS)
  add_custom_command(
    OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/docs/404.html
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    DEPENDS mkdocs.yml
    COMMAND mkdocs build --verbose --clean --strict -f ${CMAKE_CURRENT_SOURCE_DIR}/mkdocs.yml -d ${CMAKE_CURRENT_BINARY_DIR}/docs
  )

  add_custom_target(generate_doc ALL DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/docs/404.html)
  set_target_properties(generate_doc PROPERTIES FOLDER "prepare_for_deploy")
endif()

if(CSTE_MATH_BUILD_SINGLE_HEADER)
  file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/cste_math/)

  set(SINGLE_INCLUDE_FILE ${CMAKE_CURRENT_BINARY_DIR}/cste_math/cste_math_single.h)
  set(NOTICE_FILE ${CMAKE_CURRENT_SOURCE_DIR}/misc/notice.txt)

  add_custom_command(
    OUTPUT ${SINGLE_INCLUDE_FILE}
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/
    DEPENDS ${CSTE_MATH_HEADERS}
    COMMAND python ${CMAKE_CURRENT_SOURCE_DIR}/tools/header_compiler/header_compiler.py 
      --output=${SINGLE_INCLUDE_FILE}
      --notice=${NOTICE_FILE}
      --header_guard="CSTE_MATH_SINGLE_INCLUDE_H_"
      --input=${CMAKE_CURRENT_SOURCE_DIR}/include/cste_math/cste_math.h)

  add_custom_target(generate_single_include ALL DEPENDS ${SINGLE_INCLUDE_FILE})
  set_target_properties(generate_single_include PROPERTIES FOLDER "prepare_for_deploy")
endif()


add_library(cste_math INTERFACE)
add_library(cste_math::cste_math ALIAS cste_math)

target_include_directories(cste_math INTERFACE 
  $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)

target_compile_features(cste_math INTERFACE cxx_std_17)

install(TARGETS cste_math EXPORT cste_mathTargets)

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/cste_math DESTINATION include)

install(EXPORT cste_mathTargets
        FILE cste_mathConfig.cmake
        NAMESPACE cste_math::
        DESTINATION lib/cmake/cste_math
         )

if(CSTE_MATH_BUILD_TESTS)
  enable_testing()
  add_subdirectory(tests)
endif()

if(CSTE_MATH_BUILD_PACKAGE)
  add_custom_command( 
    OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/cste_math.zip
    DEPENDS
      ${SINGLE_INCLUDE_FILE}
      ${CMAKE_CURRENT_BINARY_DIR}/docs/404.html
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/include ${CMAKE_CURRENT_BINARY_DIR}/include
    COMMAND ${CMAKE_COMMAND} -E copy ${SINGLE_INCLUDE_FILE} ${CMAKE_CURRENT_BINARY_DIR}/include
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/README.md ${CMAKE_CURRENT_BINARY_DIR}/README.md
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/LICENSE ${CMAKE_CURRENT_BINARY_DIR}/LICENSE
    COMMAND ${CMAKE_COMMAND} -E tar "cf" "cste_math.zip" --format=zip 
      "${CMAKE_CURRENT_BINARY_DIR}/README.md"
      "${CMAKE_CURRENT_BINARY_DIR}/LICENSE"
      "${CMAKE_CURRENT_BINARY_DIR}/include"
      "${CMAKE_CURRENT_BINARY_DIR}/docs"
  )

  add_custom_target(generate_zip ALL
    DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/cste_math.zip )
    set_target_properties(generate_zip PROPERTIES FOLDER "prepare_for_deploy")
endif()
