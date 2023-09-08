//includes
#include "main.h"
#include "../src/Control/InputState.hpp"
#include <iomanip>

//definitions
InputState::InputState(pros::Controller controller){
    //store inputs as array of ints
    int inputs[16] = {
        controller.get_analog(ANALOG_LEFT_X),
        controller.get_analog(ANALOG_LEFT_Y),
        controller.get_analog(ANALOG_RIGHT_X),
        controller.get_analog(ANALOG_RIGHT_Y),
        controller.get_digital(DIGITAL_UP),
        controller.get_digital(DIGITAL_DOWN),
        controller.get_digital(DIGITAL_LEFT),
        controller.get_digital(DIGITAL_RIGHT),
        controller.get_digital(DIGITAL_A),
        controller.get_digital(DIGITAL_B),
        controller.get_digital(DIGITAL_X),
        controller.get_digital(DIGITAL_Y),
        controller.get_digital(DIGITAL_L1),
        controller.get_digital(DIGITAL_L2),
        controller.get_digital(DIGITAL_R1),
        controller.get_digital(DIGITAL_R2)
    };

    //join array into string line
    std::string inputLine = "";
    for (int i = 0; i < 16; i++){
        inputLine.append(std::to_string(inputs[i]) + ",");
    }
    inputLine.pop_back();
    this->saveLine = inputLine;
}
std::string InputState::GetSaveLine(){
    //return saved line
    return this->saveLine;
}