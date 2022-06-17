#pragma once
#include "Units.hpp"
#include "okapi/api/device/motor/abstractMotor.hpp"
#include "okapi/api/chassis/controller/chassisScales.hpp"
#include <cmath>
#include <utility>
#include <stdexcept>

namespace balaji{

  namespace Math{

    double deadBand(double value, double db);

    double ftpsToRPM(double ftps, okapi::ChassisScales scale, okapi::AbstractMotor::GearsetRatioPair gearset);

    double rpmToFtps(double rpm, okapi::ChassisScales scale, okapi::AbstractMotor::GearsetRatioPair gearset);

    double ftToTick(double ft, okapi::ChassisScales scale, okapi::AbstractMotor::GearsetRatioPair gearset);

    double tickToFeet(double tick, okapi::ChassisScales scale, okapi::AbstractMotor::GearsetRatioPair gearset);

    std::pair<double, double> quadraticFormula(double a, double b, double c);

    int signum(double value);

  }

}
