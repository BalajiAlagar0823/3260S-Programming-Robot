#pragma once

namespace balaji {
  /* SCurve Motion Profile Class */
  class SCurveMotionProfile {
    public:
      SCurveMotionProfile(double max_V, double time_to_max_v, double dist);
      double velocity(double t);
      double length;

    private:
      double max_v;
      double accel_stop;
      double max_v_stop;
      double decel_stop;

      double distance_accelerating(double acceleration, double time);
      double time_acceleration(double acceleration, double distance);
  };
  
  /* Triangular Motion Profile Class */
  class trianglularMotionProfile {
    public:
      trianglularMotionProfile(double max_V, double time_to_max_v, double dist);
      double velocity(double t);

    private:
      double accel;
  };

}
