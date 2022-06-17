#pragma once
#include "okapi/api/units/QLength.hpp"
#include "okapi/api/units/QAngle.hpp"
#include "okapi/api/units/QSpeed.hpp"
#include "okapi/api/units/QAngularSpeed.hpp"
#include "okapi/api/units/QAcceleration.hpp"
#include "okapi/api/units/QAngularAcceleration.hpp"
#include "okapi/api/units/QJerk.hpp"
#include "okapi/api/units/QAngularJerk.hpp"
#include "okapi/api/units/QTime.hpp"


namespace okapi{
   constexpr QLength field = 12*foot;

   constexpr QAngle rotationTick = degree * 360 / 4096;

   constexpr QSpeed ftps = foot / second;

   constexpr QAcceleration ftps2 = ftps / second;

   constexpr QAngularAcceleration radps2 = radps / second;

   constexpr QJerk ftps3 = ftps2 / second;

   constexpr QAngularJerk radps3 = radps2 / second;

inline namespace literals {
  /* Length Unit Literals */
  constexpr QLength operator"" _field(long double x) { return static_cast<double>(x)*field; }
  constexpr QLength operator"" _field(unsigned long long int x) { return static_cast<double>(x)*field; }

  /* Speed Unit */
  

  /* Angular Speed Literals */


  /* Acceleration Unit */

  /* Angular Acceleration Literals */

  /* Jerk Literals */

  /* Angular Jerk Literals */
}

}
