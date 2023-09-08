//includes
#include "main.h"
#include "../src/Periods/periods.hpp"
#include "../src/globals.hpp"
#include "../src/Button/CreateButton.hpp"

//definition
//initialization of program code, NOTE: blocks other competition modes
void Initialize(){
    //setup buttons
    createButton(objects[0], styles[0], 0, LV_COLOR_PURPLE, LV_ALIGN_IN_TOP_RIGHT, "Track");
    createButton(objects[1], styles[1], 1, LV_COLOR_YELLOW, LV_ALIGN_CENTER, "Left");
    createButton(objects[2], styles[2], 2, LV_COLOR_YELLOW, LV_ALIGN_IN_RIGHT_MID, "Right");
    createButton(objects[3], styles[3], 3, LV_COLOR_YELLOW, LV_ALIGN_IN_TOP_MID, "Skills");

    //rumble that bot is ready
    master.rumble("..");
}