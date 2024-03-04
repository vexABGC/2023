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
lv_obj_t** objects = new lv_obj_t*[5];
lv_style_t* styles = new lv_style_t[5];

//hardware
pros::Controller master(pros::E_CONTROLLER_MASTER);
pros::Motor lf_mtr(16, pros::E_MOTOR_GEAR_BLUE, false, pros::E_MOTOR_ENCODER_ROTATIONS);
pros::Motor lb_mtr(20, pros::E_MOTOR_GEAR_BLUE, false, pros::E_MOTOR_ENCODER_ROTATIONS);
pros::Motor rf_mtr(11, pros::E_MOTOR_GEAR_BLUE, true, pros::E_MOTOR_ENCODER_ROTATIONS);
pros::Motor rb_mtr(13, pros::E_MOTOR_GEAR_BLUE, true, pros::E_MOTOR_ENCODER_ROTATIONS);
pros::Motor f_intake(7, true);
pros::Motor b_intake(8, true); // FLYWHEEL
pros::Motor l_wing(1, pros::E_MOTOR_GEAR_GREEN, true, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor r_wing(5, pros::E_MOTOR_GEAR_GREEN, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor elevation(6, pros::E_MOTOR_GEAR_GREEN, true, pros::E_MOTOR_ENCODER_DEGREES);

//hardware groups
pros::Motor_Group left_mtrs({lf_mtr, lb_mtr});
pros::Motor_Group right_mtrs({rf_mtr, rb_mtr});