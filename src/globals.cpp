#include "main.h"
#include "../src/globals.hpp"
std::string autonomousCodeLocation = "/usd/autonomousMovement.routine";
int time_delay = 20;
int left_mtr_port = 1;
int right_mtr_port = 2;
pros::Controller master(pros::E_CONTROLLER_MASTER);
pros::Motor left_mtr(left_mtr_port), right_mtr(right_mtr_port);