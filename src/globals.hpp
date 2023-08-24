#include "main.h"

//DECLARATIONS ONLY
//other declarations
extern int time_delay;

//autonomous locations
extern std::string autonomous_code_location;

//regular globals
extern int time_delay;
extern int minimum_joystick;

//ports
extern int left_front_mtr_port;
extern int left_back_mtr_port;
extern int right_front_mtr_port;
extern int right_back_mtr_port;


//hardware
extern pros::Controller master;
extern pros::Motor left_front_mtr;
extern pros::Motor left_back_mtr;
extern pros::Motor right_front_mtr;
extern pros::Motor right_back_mtr;

//hardware groups
extern pros::Motor_Group left_mtrs;
extern pros::Motor_Group right_mtrs;