#include "headers/globals.hpp"
#include "pros-grafana-lib/api.h"
// Controller
Controller master;

// Motors
Motor leftFront(4, true, AbstractMotor::gearset::blue, AbstractMotor::encoderUnits::degrees);
Motor leftBack(2, true, AbstractMotor::gearset::blue, AbstractMotor::encoderUnits::degrees);
Motor rightFront(12, false, AbstractMotor::gearset::blue, AbstractMotor::encoderUnits::degrees);
Motor rightBack(11, false, AbstractMotor::gearset::blue, AbstractMotor::encoderUnits::degrees);

MotorGroup leftDrive({leftFront, leftBack});
MotorGroup rightDrive({rightFront, rightBack});

//Grafana Declarations
void declareGrafanaVars() {
  grafanalib::GUIManager manager;
  manager.setRefreshRate(20);

  grafanalib::Variable<okapi::Motor> leftFrontMotorVar("Left Front Motor", leftFront);
  grafanalib::VariableGroup<okapi::Motor> chassisVars({leftFrontMotorVar});
  chassisVars.add_getter("Temperature", &okapi::Motor::getTemperature);
  chassisVars.add_getter("Actual Velocity", &okapi::Motor::getActualVelocity);
  chassisVars.add_getter("Voltage", &okapi::Motor::getVoltage);
  // chassisVars.add_getter("Battery", &pros::battery::get_capacity);

  manager.registerDataHandler(&chassisVars);
  manager.startTask();
}

// Sensors
pros::Vision vision(14);

/* Chassis Controller */
std::shared_ptr<ChassisController> drive =
    ChassisControllerBuilder()
    .withMotors(leftDrive, rightDrive)
    .withDimensions({AbstractMotor::gearset::green, 5.0/7.0}, {{3.25_in, 1.294_ft}, imev5BlueTPR})
    .build();

/* Chassis Async Motion Profile Controller */
std::shared_ptr<AsyncMotionProfileController> profileController =
    AsyncMotionProfileControllerBuilder()
    .withLimits({
      1.0, //Max Velocity m/s
      2.0,  //Max Acceleration m/s/s
      10.0 //Max Jerk m/s/s/s
    })
    .withOutput(drive)
    .buildMotionProfileController();
