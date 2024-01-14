//includes
#include "main.h"
#include "../src/globals.hpp"
#include "../src/Periods/periods.hpp"

//initialization of program code, NOTE: blocks other competition modes
void initialize() {
    master.rumble("..");
    Initialize();
}

//disabled code, runs during the disabled state of Field Management System or the VEX Competition Switch, following either autonomous or opcontrol
void disabled() {}

//competition initialization, enabled during both autonomous and opcontrol
void competition_initialize() {}

//autonomous mode code
void autonomous() { Autonomous(); }

//driver control mode
void opcontrol() { OperatorControl(); }