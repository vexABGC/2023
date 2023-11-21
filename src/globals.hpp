//includes
#include "main.h"

//declarations
//regular globals
extern int time_delay;
extern int minimum_joystick;
extern double speed_multiplier;
extern double turn_multiplier;

//autonomous globals
extern bool should_track;
extern std::string skills_autonomous_location;
extern std::string left_autonomous_location;
extern std::string right_autonomous_location;
extern std::string autonomous_location;

//graphics globals
extern lv_obj_t** objects;
extern lv_style_t* styles;

//hardware
extern pros::Controller master;
extern pros::Motor lf_mtr;
extern pros::Motor lb_mtr;
extern pros::Motor rf_mtr;
extern pros::Motor rb_mtr;
extern pros::Motor l_intake;
extern pros::Motor r_intake;

//hardware groups
extern pros::Motor_Group left_mtrs;
extern pros::Motor_Group right_mtrs;
extern pros::Motor_Group intake_mtrs;