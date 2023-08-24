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
int left_front_mtr_port = 1;
int left_back_mtr_port = 2;
int right_front_mtr_port = 3;
int right_back_mtr_port = 4;

//hardware
pros::Controller master(pros::E_CONTROLLER_MASTER);
pros::Motor left_front_mtr(left_front_mtr_port);
pros::Motor left_back_mtr(left_back_mtr_port);
pros::Motor right_front_mtr(right_front_mtr_port);
pros::Motor right_back_mtr(right_back_mtr_port);

//hardware groups
pros::Motor_Group left_mtrs({left_front_mtr, left_back_mtr});
pros::Motor_Group right_mtrs({right_front_mtr, right_back_mtr});