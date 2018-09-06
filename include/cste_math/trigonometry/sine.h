#ifndef CSTE_MATH_TRIGNOMETRY_SINE_H_INCLUDED
#define CSTE_MATH_TRIGNOMETRY_SINE_H_INCLUDED

#include "cste_math/config.h"

#include "cste_math/constants.h"
#include "cste_math/trigonometry/bound/sine_pi4.h"
#include "cste_math/trigonometry/bound/cosine_pi4.h"
#include "cste_math/modulo.h"

#include <limits>
#include <iostream>
#include <iomanip>

namespace CSTE_MATH_NAMESPACE {

  // 
  template<typename T>
  constexpr T sine(const T& rad) {
    if(std::isnan(rad)) {
      return rad;
    }

    if (std::isinf(rad)) {
      return std::numeric_limits<T>::signaling_NaN();
    }
  
    long double r = rad;

    if(r > pi<long double>) {
      r = modulo(r, two_pi<long double>);
    } else if( r < -pi<long double>) {
      r = modulo(r, -two_pi<long double>);
    }

    if(r > pi<long double>) {
      r -= two_pi<long double>;
    } else if(r < -pi<long double>) {
      r += two_pi<long double>;
    }



    // Remap into the -PI/2->PI/2 range.
    if(r > half_pi<long double>) {
      r = pi<T> - r;
    } else if(r < -half_pi<long double>) {
      r = -pi<T> - r;
    }


    if(r < -quarter_pi<long double>) {
      return -cosine_pi4(r + half_pi<long double>);
    } else if(r > quarter_pi<long double>) {
      return cosine_pi4(r - half_pi<long double>);
    }
      
    return sine_pi4(r);
  }
}

#endif