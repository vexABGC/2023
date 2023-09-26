//includes
#include "main.h"
#include "../src/Control/InputState.hpp"
#include <iomanip>

//definitions
InputState::InputState(){
    
}
InputState::InputState(pros::Controller controller){
    //store inputs in data array of int8's
    this->data[0]  = static_cast<int8_t>(controller.get_analog(ANALOG_LEFT_X));
    this->data[1]  = static_cast<int8_t>(controller.get_analog(ANALOG_LEFT_Y));
    this->data[2]  = static_cast<int8_t>(controller.get_analog(ANALOG_RIGHT_X));
    this->data[3]  = static_cast<int8_t>(controller.get_analog(ANALOG_RIGHT_Y));
    this->data[4]  = static_cast<int8_t>(controller.get_digital(DIGITAL_UP));
    this->data[5]  = static_cast<int8_t>(controller.get_digital(DIGITAL_DOWN));
    this->data[6]  = static_cast<int8_t>(controller.get_digital(DIGITAL_LEFT));
    this->data[7]  = static_cast<int8_t>(controller.get_digital(DIGITAL_RIGHT));
    this->data[8]  = static_cast<int8_t>(controller.get_digital(DIGITAL_A));
    this->data[9]  = static_cast<int8_t>(controller.get_digital(DIGITAL_B));
    this->data[10] = static_cast<int8_t>(controller.get_digital(DIGITAL_X));
    this->data[11] = static_cast<int8_t>(controller.get_digital(DIGITAL_Y));
    this->data[12] = static_cast<int8_t>(controller.get_digital(DIGITAL_L1));
    this->data[13] = static_cast<int8_t>(controller.get_digital(DIGITAL_L2));
    this->data[14] = static_cast<int8_t>(controller.get_digital(DIGITAL_R1));
    this->data[15] = static_cast<int8_t>(controller.get_digital(DIGITAL_R2));
}
void InputState::GetData(int8_t* dataPointer){
    //update pointer to match data
    for (int i = 0; i < 16; i++){
        dataPointer[i] = this->data[i];
    }
}