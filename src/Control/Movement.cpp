//includes
#include "main.h"
#include "../Math/Vector2.hpp"
#include "../src/Control/Movement.hpp"
#include "../src/globals.hpp"

//definition
void Movement(int controllerInputs[16]){
    //Movement code goes here:
    //take in joystick inputs
    Vector2<int> leftJoystick(controllerInputs[0], controllerInputs[1]);
    Vector2<int> rightJoystick(controllerInputs[2], controllerInputs[3]);

    //split arcade control setup
    //setup motor group sides vector (left, right)
    Vector2<int> motorSides(0,0);

    //overall and teen speed mode toggles
    speed_multiplier = controllerInputs[14]==1 ? 1 : 0.5;
    turn_multiplier = controllerInputs[12]==1 ? 1 : 0.5;

    //calculate turning values(0 if less than a minimum set), and set motor group sides vector to calculated turning values
    if (abs(rightJoystick.getX()) > minimum_joystick){
        //if positive, turn right, right wheels backward, left wheels forward
        //if negative, turn left, right wheels forward, left wheels backward
        //thus left wheels sign = joystick X sign
        //thus right wheels sign = -1 * joystick X sign
        motorSides.setX(rightJoystick.getX());
        motorSides.setY(-rightJoystick.getX());

        //scale turning with turn speed multiplier
        motorSides.scale(turn_multiplier);
    }
    
    //add forward/backward to motor group sides vector
    motorSides.add(leftJoystick.getY());

    //scale motor speeds with overall speed multiplier
    motorSides.scale(speed_multiplier);

    //update motor groups
    left_mtrs.move(motorSides.getX()*speed_multiplier);
    right_mtrs.move(motorSides.getY()*speed_multiplier);
}