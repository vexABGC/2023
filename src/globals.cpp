//includes
#include "main.h"
#include "../src/globals.hpp"

//definitions only
//regular globals
int time_delay = 20;
int minimum_joystick = 30;
double speed_multiplier = 0.5;
double turn_multiplier = 0.5;

//autonomous globals
bool should_track = false;
std::string skills_autonomous_location = "/usd/skills.routine";
std::string left_autonomous_location = "/usd/left.routine";
std::string right_autonomous_location = "/usd/right.routine";
std::string autonomous_location = left_autonomous_location;

//graphics globals
lv_obj_t** objects = new lv_obj_t*[4];
lv_style_t** styles = new lv_style_t*[4];

//hardware
pros::Controller master(pros::E_CONTROLLER_MASTER);
pros::Motor lf_mtr(2, false);
pros::Motor lb_mtr(3, false);
pros::Motor rf_mtr(4, true);
pros::Motor rb_mtr(5, true);

//hardware groups
pros::Motor_Group left_mtrs({lf_mtr, lb_mtr});
pros::Motor_Group right_mtrs({rf_mtr, rb_mtr});