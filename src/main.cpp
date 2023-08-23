//includes
#include "main.h"
#include "../src/RobotControlMethods/initialize.hpp"
#include "../src/RobotControlMethods/disabled.hpp"
#include "../src/RobotControlMethods/competitionInitialize.hpp"
#include "../src/RobotControlMethods/autonomous.hpp"
#include "../src/RobotControlMethods/operatorControl.hpp"

//initialization of program code, NOTE: blocks other competition modes
void initialize() {initializeMethod();}

//disabled code, runs during the disabled state of Field Management System or the VEX Competition Switch, following either autonomous or opcontrol
void disabled() {disabledMethod();}

//competition initialization, enabled during both autonomous and opcontrol
void competition_initialize() {competitionInitializeMethod();}

//autonomous mode code
void autonomous() {autonomousMethod();}

//driver control mode
void opcontrol() {operatorControlMethod();}