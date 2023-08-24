//include statements
#include "main.h"
#include "../src/globals.hpp"

//INITIALIZATIONS ONLY
//other declarations
extern int time_delay;

//autonomous locations
std::string autonomous_code_location = "/usd/autonomousMovement.routine";

//regular globals
int time_delay = 20;
int minimum_joystick = 31;

//ports
int left_mtr_port = 1;
int right_mtr_port = 2;

//hardware
pros::Controller master(pros::E_CONTROLLER_MASTER);
pros::Motor left_mtr(left_mtr_port);
pros::Motor right_mtr(right_mtr_port);