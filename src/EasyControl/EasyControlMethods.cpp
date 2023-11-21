//include
#include "main.h"
#include "../src/EasyControl/EasyControlMethods.hpp"
#include <sstream>

//constants and variables
const char* axisNames[10] = {
    "Always Off",
    "On/Toggle",
    "Left Stick X",
    "-Left Stick X",
    "Left Stick Y",
    "-Left Stick Y",
    "Right Stick X",
    "-Right Stick X",
    "Right Stick Y",
    "-Right Stick Y"
};

//definitions
void CycleNumber(int &num, int min, int max){
    num++;
	if (num > max){
		num = min;
	}
}
void ChangeText(lv_obj_t* object, const char* newText){
    lv_obj_t* label = lv_obj_get_child(object, NULL);
	lv_label_set_text(label, newText);
}
void UpdateMotorDisplay(lv_obj_t* display, int motorNum){
    std::stringstream text;
    text << "Motor " << motorNum;
    ChangeText(display, text.str().c_str());
}
void UpdatePortDisplay(lv_obj_t* display, int portNum){
    std::stringstream text;
    text << "Port " << portNum;
    ChangeText(display, text.str().c_str());
}
void UpdateAxisOneDisplay(lv_obj_t* display, int axisOneNum){
    std::stringstream text;
    text << "Axis 1\n" << axisNames[axisOneNum];
    ChangeText(display, text.str().c_str());
}
void UpdateAxisTwoDisplay(lv_obj_t* display, int axisTwoNum){
    std::stringstream text;
    text << "Axis 2\n" << axisNames[axisTwoNum];
    ChangeText(display, text.str().c_str());
}