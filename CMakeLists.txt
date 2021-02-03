cmake_minimum_required(VERSION 3.9)

project(cste_math 
  VERSION 0.2
  DESCRIPTION "C++ constexpr math"
  LANGUAGES CXX)

option(CSTE_MATH_BUILD_DOCS "Build documentation" OFF)
option(CSTE_MATH_BUILD_TESTS "Build tests" OFF)
option(CSTE_MATH_BUILD_PACKAGE "Build Release Package" OFF)

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


add_library(cste_math INTERFACE)
add_library(cste_math::cste_math ALIAS cste_math)

target_include_directories(cste_math INTERFACE 
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)

target_compile_features(cste_math INTERFACE cxx_std_20)

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
