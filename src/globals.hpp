#include "main.h"
#include "../src/Graphics/Button.hpp"

//DECLARATIONS ONLY
//autonomous selectors and locations
extern bool autonomousSide; //false = left, true = right
extern std::string autonomous_code_location;

//regular globals
extern int time_delay;
extern int minimum_joystick;
extern lv_obj_t * tabView;
extern bool should_avoid;
extern bool should_track;

//GUI elements
extern Button autonomous_menu_tab;
extern Button main_menu_tab;
extern Button status_menu_tab;
extern Button autonomous_left;
extern Button autonomous_right;
extern Button enemy_avoidance;
extern Button track_button;


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