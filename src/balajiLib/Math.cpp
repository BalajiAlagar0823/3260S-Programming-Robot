#include "balajiLib/Math.hpp"

namespace balaji{

  double Math::deadBand(double value, double db){
    if(abs(value) < db) return 0;
    else return value;
  }

  double Math::ftpsToRPM(double ftps, okapi::ChassisScales scale, okapi::AbstractMotor::GearsetRatioPair gearset){
    return ftps * 12 / (scale.wheelDiameter.convert(okapi::inch) * M_PI) * gearset.ratio * 60;
  }

  double Math::rpmToFtps(double rpm, okapi::ChassisScales scale, okapi::AbstractMotor::GearsetRatioPair gearset){
    return rpm / 60 / gearset.ratio * (scale.wheelDiameter.convert(okapi::inch) * M_PI) / 12;
  }

  double Math::ftToTick(double ft, okapi::ChassisScales scale, okapi::AbstractMotor::GearsetRatioPair gearset){
    return ft * 12 / (scale.wheelDiameter.convert(okapi::inch) * M_PI) * gearset.ratio * scale.tpr;
  }

  double Math::tickToFeet(double tick, okapi::ChassisScales scale, okapi::AbstractMotor::GearsetRatioPair gearset){
    return (tick/scale.tpr) / (gearset.ratio)*(scale.wheelDiameter.convert(okapi::inch) * M_PI) / 12;
  }

  std::pair<double, double> Math::quadraticFormula(double a, double b, double c){
    double discriminant = b * b - 4 * a * c;

    if(discriminant < 0) throw std::runtime_error("Quadratic Formula: No Real Solution!");
    else if(abs(discriminant) <= 0.001) return {-b / 2 * a, -b / 2 * a};
    else {
      double x1 = (-b + sqrt(discriminant)) / (2 * a);
      double x2 = (-b - sqrt(discriminant)) / (2 * a);
      return {x1, x2};
    }
  }

  int Math::signum(double value) {
    return (value > 0) - (value < 0);
  }

}
