#include "main.h"
#include "okapi/api.hpp"
/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::lcd::initialize();
	pros::lcd::print(0, "Initialize!");
	pros::delay(10);
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

void autonomous() {
}

void opcontrol() {
	pros::lcd::clear();
	pros::lcd::print(1, "OPCONTROL!");

	leftDrive.setBrakeMode(AbstractMotor::brakeMode::coast);
	rightDrive.setBrakeMode(AbstractMotor::brakeMode::coast);

	declareGrafanaVars();

	// Control Loop
	while(true) {
    	drive->getModel()->arcade(master.getAnalog(ControllerAnalog::leftY),
                            master.getAnalog(ControllerAnalog::rightX));
    	pros::delay(10);
  	}
}
