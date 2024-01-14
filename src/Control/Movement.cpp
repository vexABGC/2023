//includes
#include "main.h"
#include "../src/Control/Movement.hpp"
#include "../src/globals.hpp"

//toggle variables and last time toggled variables
bool wingsOn = false;
bool flyOn = false;
uint32_t wingsTime = 0;
uint32_t flyTime = 0;

//definition
void Movement(int controllerInputs[16]){
    //Movement code goes here:
    //update front intake based on L2 and R2
    f_intake.move(127*(controllerInputs[15]-controllerInputs[13]));

    //fly wheel / back intake toggle
    if(controllerInputs[9] == 1 && pros::millis() - flyTime > 500){
        flyOn = !flyOn;
        flyTime = pros::millis();
    }

    //wing toggle
    if(controllerInputs[8] == 1 && pros::millis() - wingsTime > 500){
        wingsOn = !wingsOn;
        wingsTime = pros::millis();
    }

    //fly wheel / back intake control with check for match load override
    if(flyOn){
        if(controllerInputs[13] == 1){
            b_intake.move(-0.3*127*controllerInputs[13]);
        }else{
            b_intake.move(0.7*127);
        }
    }else{
        if(controllerInputs[10] == 1){
            b_intake.move(127);
        }else{
            b_intake.move(-127*controllerInputs[13]);
        }
    }

    //wing control with check for 180 degree extension override
    if(wingsOn){
        if(controllerInputs[11] == 1){
            l_wing.move_absolute(180, 200);
            r_wing.move_absolute(180, 200);
        }else{
            l_wing.move_absolute(90, 200);
            r_wing.move_absolute(90, 200);
        }
    }else{
        if(controllerInputs[11] == 1){
            l_wing.move_absolute(270, 200);
            r_wing.move_absolute(180, 200);
        }else{
            l_wing.move_absolute(0, 200);
            r_wing.move_absolute(0, 200);
        }
    }

    //pneumatics control
    if (controllerInputs[4] == 1){
        //flip up pneumatics
        l_piston.set_value(true);
        r_piston.set_value(true);
    }else if(controllerInputs[5] == 1){
        //flip down pneumatics
        l_piston.set_value(false);
        r_piston.set_value(false);
    }

    //movement control
    //setup up forward/back on motors
    int lft = controllerInputs[1];
    int rgt = controllerInputs[1];

    //setup up turning on motors
    if(abs(controllerInputs[2]) > minimum_joystick){
        lft += controllerInputs[2] * turn_multiplier;
        rgt -= controllerInputs[2] * turn_multiplier;
    }

    //move motors
    left_mtrs.move(lft * speed_multiplier);
    right_mtrs.move(rgt * speed_multiplier);
}