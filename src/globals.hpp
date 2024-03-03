//includes
#include "main.h"

//definitions
#define PI 3.141592653589793

//declarations
//regular globals
extern int time_delay;
extern int minimum_joystick;
extern double speed_multiplier;
extern double turn_multiplier;

//autonomous globals
extern bool should_track;
extern int tracker_count;
extern int autonomous_mode;

//graphics globals
extern lv_obj_t** objects;
extern lv_style_t* styles;

//hardware
extern pros::Controller master;
extern pros::Motor lf_mtr;
extern pros::Motor lb_mtr;
extern pros::Motor rf_mtr;
extern pros::Motor rb_mtr;
extern pros::Motor b_intake;
extern pros::Motor l_wing;
extern pros::Motor r_wing;
extern pros::Motor l_elevation;
extern pros::Motor r_elevation;

//hardware groups
extern pros::Motor_Group left_mtrs;
extern pros::Motor_Group right_mtrs;