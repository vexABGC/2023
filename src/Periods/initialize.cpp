//includes
#include "main.h"
#include "../src/Periods/periods.hpp"
#include "../src/globals.hpp"
#include "../src/Button/CreateButton.hpp"

//definition
//initialization of program code, NOTE: blocks other competition modes
void Initialize(){
    //setup buttons
    createButton(0, 160, 80, 0, 0, LV_COLOR_PURPLE, LV_ALIGN_IN_TOP_RIGHT, "Track"); //track button
    createButton(1, 160, 80, 0, 0, LV_COLOR_YELLOW, LV_ALIGN_CENTER, "Left"); //left select button
    createButton(2, 160, 80, 0, 0, LV_COLOR_YELLOW, LV_ALIGN_IN_RIGHT_MID, "Right"); //right select button
    createButton(3, 160, 80, 0, 0, LV_COLOR_YELLOW, LV_ALIGN_IN_TOP_MID, "Skills"); //skills select button
    createButton(4, 160, 80, 0, 0, LV_COLOR_WHITE, LV_ALIGN_IN_TOP_LEFT, "Left"); //current selection display

    //set up drive and wing brakes
    lf_mtr.set_brake_mode(MOTOR_BRAKE_HOLD);
    lb_mtr.set_brake_mode(MOTOR_BRAKE_HOLD);
    rf_mtr.set_brake_mode(MOTOR_BRAKE_HOLD);
    rb_mtr.set_brake_mode(MOTOR_BRAKE_HOLD);
    l_wing.set_brake_mode(MOTOR_BRAKE_HOLD);
    r_wing.set_brake_mode(MOTOR_BRAKE_HOLD);

    //rumble that bot is ready
    master.rumble("..");
}