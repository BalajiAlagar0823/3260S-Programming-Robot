#pragma once

namespace balaji {

  class FFVelController{
    private:
      double kV, kA_Up, kA_Down, kP_Pos, kP_Vel;
      double currPos, currVel, power;

    public:
      FFVelController() = default;
      ~FFVelController() = default;

      FFVelController(double ikV, double ikAU, double ikAD, double ikP_Pos, double ikP_Vel);

      double step(double position, double velocity, double acceleration, double currentPos, double currentVel);

      double getTargetPower() const;

      double getkV() const;
  };

}
