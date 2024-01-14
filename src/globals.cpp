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
int tracker_count = 0;
int autonomous_mode = 0;

//graphics globals
lv_obj_t** objects = new lv_obj_t*[7];
lv_style_t* styles = new lv_style_t[7];

//hardware
pros::Controller master(pros::E_CONTROLLER_MASTER);
pros::Motor lf_mtr(19, pros::E_MOTOR_GEAR_BLUE, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor lb_mtr(18, pros::E_MOTOR_GEAR_BLUE, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor rf_mtr(9, pros::E_MOTOR_GEAR_BLUE, true, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor rb_mtr(17, pros::E_MOTOR_GEAR_BLUE, true, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor f_intake(11, false);
pros::Motor b_intake(16, true);
pros::Motor l_wing(20, pros::E_MOTOR_GEAR_GREEN, true, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor r_wing(12, pros::E_MOTOR_GEAR_GREEN, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::ADIDigitalOut l_piston('A');
pros::ADIDigitalOut r_piston('B');

//hardware groups
pros::Motor_Group left_mtrs({lf_mtr, lb_mtr});
pros::Motor_Group right_mtrs({rf_mtr, rb_mtr});