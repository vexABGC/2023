//includes
#include "../src/globals.hpp"
#include "../src/Periods/periods.hpp"
#include "../src/Control/Movement.hpp"

//definition
//disabled code, runs during the disabled state of Field Management System or the VEX Competition Switch, following either autonomous or opcontrol
void Disabled(){
    //set all motors to 0, and coast
    left_mtrs.set_brake_modes(pros::E_MOTOR_BRAKE_COAST);
    right_mtrs.set_brake_modes(pros::E_MOTOR_BRAKE_COAST);
    b_intake.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    l_wing.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    r_wing.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    l_elevation.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    r_elevation.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    left_mtrs.move(0);
    right_mtrs.move(0);
    b_intake.move(0);
    l_wing.move(0);
    r_wing.move(0);
    l_elevation.move(0);
    r_elevation.move(0);
}