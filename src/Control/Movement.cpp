#include "main.h"
#include "../src/Math/Vector2.hpp"
#include "../src/Control/Movement.hpp"
#include "../src/globals.hpp"
void Movement(int controllerInputs[16]){
    //Movement code goes here:
    //take in joystick inputs
    Vector2<int> leftJoystick(controllerInputs[0], controllerInputs[1]);
    Vector2<int> rightJoystick(controllerInputs[2], controllerInputs[3]);

    //update motors
    left_mtr.move(leftJoystick.getY());
    right_mtr.move(rightJoystick.getY());
}