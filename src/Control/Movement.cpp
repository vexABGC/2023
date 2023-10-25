//includes
#include "main.h"
#include "../Math/Vector2.hpp"
#include "../src/Control/Movement.hpp"
#include "../src/globals.hpp"

//definition
void Movement(int controllerInputs[16]){
    //Movement code goes here:
    //set intake to 127 if R2 pressed, else set intake to 0
    int intake = 127*controllerInputs[15];

    //subtract 127 from intake if L2 pressed, else subtract 0
    intake -= 127*controllerInputs[13];

    //output intake output
    intake_mtrs.move(intake);

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
        //make sure to scale these values with turn multiplier
        motorSides.setX(rightJoystick.getX() * turn_multiplier);
        motorSides.setY(-rightJoystick.getX() * turn_multiplier);
    }
    
    //add forward/backward to motor group sides vector
    motorSides.add(leftJoystick.getY());

    //update motor groups with speed multiplier scaled values
    left_mtrs.move(motorSides.getX() * speed_multiplier);
    right_mtrs.move(motorSides.getY() * speed_multiplier);

}