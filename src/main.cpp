//includes
#include "main.h"
#include "../src/ControlPeriodMethods/initialize.hpp"
#include "../src/ControlPeriodMethods/disabled.hpp"
#include "../src/ControlPeriodMethods/competitionInitialize.hpp"
#include "../src/ControlPeriodMethods/autonomous.hpp"
#include "../src/ControlPeriodMethods/operatorControl.hpp"

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