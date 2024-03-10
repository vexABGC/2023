//speeds
#define ELEVATION_SPEED 130
#define WING_SPEED 150

//includes
#include "main.h"
#include "../src/Control/Movement.hpp"
#include "../src/globals.hpp"

//toggle variables and last time toggled variables
bool wingsOn = false;
bool flyOn = false;
uint32_t wingsTime = 0;
uint32_t flyTime = 0;
int lElevationDegrees = -5*100;
int rElevationDegrees = -5*100;
int32_t isOverTempPrev[] = {false, false, false}; //fly, l elevation, r elevation

//definition
void Movement(int controllerInputs[16]){
    //movement code goes here:
    //check over temp
    int32_t isOverTemp[] = {b_intake.is_over_temp(), l_elevation.is_over_temp(), r_elevation.is_over_temp()};
    for (int i = 0; i < sizeof(isOverTemp)/sizeof(isOverTemp[0]); i++){
        if (isOverTemp[i] == true && isOverTempPrev[i] == false){
            master.rumble("------");
        }
        isOverTempPrev[i] = isOverTemp[i];
        std::stringstream controllerText;
        controllerText << "f ";
        controllerText << isOverTemp[0];
        controllerText << " ";
        controllerText << "l ";
        controllerText << isOverTemp[1];
        controllerText << " ";
        controllerText << "r ";
        controllerText << isOverTemp[2];
        master.set_text(1, 0, controllerText.str().c_str());
    }

    //wing toggle
    if(controllerInputs[8] == 1 && pros::millis() - wingsTime > 500){
        wingsOn = !wingsOn;
        wingsTime = pros::millis();
    }

    //fly wheel / back intake control with check for match load override
    if(controllerInputs[12] == 1){
        if (controllerInputs[6] == 1){
            b_intake.move(95);
        }else{
            b_intake.move(127);
        }
    }else{
        b_intake.move(0);
    }

    //wing control with check for 180 degree extension override
    if(wingsOn){
        if(controllerInputs[13] == 1){
            l_wing.move_absolute(210, WING_SPEED);
        }else{
            l_wing.move_absolute(90, WING_SPEED);
        }
        if(controllerInputs[15] == 1){
            r_wing.move_absolute(210, WING_SPEED);
        }else{
            r_wing.move_absolute(90, WING_SPEED);
        }
    }else{
        if(controllerInputs[13] == 1){
            l_wing.move_absolute(210, 150);
        }else{
            l_wing.move_absolute(0, WING_SPEED);
        }
        if(controllerInputs[15] == 1){
            r_wing.move_absolute(210, WING_SPEED);
        }else{
            r_wing.move_absolute(0, WING_SPEED);
        }
    }

    // elevation control
    if (controllerInputs[11] == 1){
        lElevationDegrees = -5 * 15;
        rElevationDegrees = -5 * 15;
    }else if (controllerInputs[7] == 1){
        lElevationDegrees = -5 * 185;
        rElevationDegrees = -5 * 185;
    }else if (controllerInputs[4] == 1){
        lElevationDegrees = -5 * 40;
        rElevationDegrees = -5 * 40;
    }

    if (controllerInputs[5] == 1){
        //move up pneumatics
        l_elevation.move_velocity(ELEVATION_SPEED);
        r_elevation.move_velocity(ELEVATION_SPEED);
        lElevationDegrees = l_elevation.get_position();
        rElevationDegrees = r_elevation.get_position();
    }else if(controllerInputs[9] == 1){
        //move down 
        l_elevation.move_velocity(-ELEVATION_SPEED);
        r_elevation.move_velocity(-ELEVATION_SPEED);
        lElevationDegrees = l_elevation.get_position();
        rElevationDegrees = r_elevation.get_position();
    }else {
        l_elevation.move_absolute(lElevationDegrees, 150);
        r_elevation.move_absolute(rElevationDegrees, 150);
    }

    //movement control
    //setup up forward/back on motors
    int lft = controllerInputs[1];
    int rgt = controllerInputs[1];

    //speed control
    if (controllerInputs[14] == 1){
        speed_multiplier = 0.8;
    }else{
        speed_multiplier = 0.5;
    }

    //setup up turning on motors
    if(abs(controllerInputs[2]) > minimum_joystick){
        lft += controllerInputs[2] * turn_multiplier;
        rgt -= controllerInputs[2] * turn_multiplier;
    }

    //move motors
    if (lft != 0 || rgt != 0){
        left_mtrs.move(lft * speed_multiplier);
        right_mtrs.move(rgt * speed_multiplier);
    }else{
        left_mtrs.brake();
        right_mtrs.brake();
    }
}