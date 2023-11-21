//includes
#include "main.h"
#include "../src/globals.hpp"

//definitions only
//regular globals
int time_delay = 20;
int minimum_joystick = 30;
double speed_multiplier = 0.5;
double turn_multiplier = 0.5;

//easy control code globals (BETA)
int motor_number = 1; //current motor being edited
int axis_one[8] = {0, 0, 0, 0, 0, 0, 0, 0}; //0 = OFF, 1 = ON, 2 = LX, 3 = -LX, 4 = LY, 5 = -LY, 6 = RX, 7 = -RX, 8 = RY, 9 = -RY
int axis_two[8] = {0, 0, 0, 0, 0, 0, 0, 0}; //0 = OFF, 1 = ON, 2 = LX, 3 = -LX, 4 = LY, 5 = -LY, 6 = RX, 7 = -RX, 8 = RY, 9 = -RY
int axis_one_settings[3] = {0, 0, 0};
int axis_two_settings[3] = {0, 0, 0};
int port_numbers[8] = {0, 0, 0, 0, 0, 0, 0, 0}; //0 = null

//autonomous globals
bool should_track = false;
std::string skills_autonomous_location = "/usd/skills.routine";
std::string left_autonomous_location = "/usd/left.routine";
std::string right_autonomous_location = "/usd/right.routine";
std::string autonomous_location = left_autonomous_location;

//graphics globals
lv_obj_t** objects = new lv_obj_t*[99];
lv_style_t* styles = new lv_style_t[99];

//hardware
pros::Controller master(pros::E_CONTROLLER_MASTER);
pros::Motor lf_mtr(2, false);
pros::Motor lb_mtr(3, false);
pros::Motor rf_mtr(4, true);
pros::Motor rb_mtr(5, true);
pros::Motor l_intake(6, false);
pros::Motor r_intake(7, true);

//hardware groups
pros::Motor_Group left_mtrs({lf_mtr, lb_mtr});
pros::Motor_Group right_mtrs({rf_mtr, rb_mtr});
pros::Motor_Group intake_mtrs({l_intake, r_intake});