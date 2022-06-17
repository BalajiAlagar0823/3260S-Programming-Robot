#include "balajiLib/linearMotionProfile.hpp"

namespace balaji {

  SCurveMotionProfile::SCurveMotionProfile(double max_V, double time_to_max_v, double dist) {
    
  }

  trianglularMotionProfile::trianglularMotionProfile(double max_V, double time_to_max_v, double dist) {
    accel = max_V / time_to_max_v;
  }
  /* Returns Target Velocity t seconds into profile */
  double trianglularMotionProfile::velocity(double t) {
    return (accel * t);
  }

}
