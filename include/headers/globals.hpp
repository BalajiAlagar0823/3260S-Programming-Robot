#pragma once
#include "main.h"
#include "pros-grafana-lib/api.h"
// Controller
extern Controller master;

// Motors
extern MotorGroup leftDrive;
extern MotorGroup rightDrive;

//Grafana Declarations
void declareGrafanaVars();

// Sensors
extern pros::Vision vision;

// Motion Profile Constants
extern std::shared_ptr<ChassisController> drive;
extern std::shared_ptr<AsyncMotionProfileController> profileController;
