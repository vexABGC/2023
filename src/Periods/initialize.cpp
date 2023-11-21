//includes
#include "main.h"
#include "../src/Periods/periods.hpp"
#include "../src/globals.hpp"
#include "../src/Button/CreateButton.hpp"

//definition
//initialization of program code, NOTE: blocks other competition modes
void Initialize(){
    //setup main screen buttons
    createButton(0, 160, 80, 0, 0, LV_COLOR_PURPLE, LV_ALIGN_IN_TOP_RIGHT, "Track"); //track button
    createButton(1, 160, 80, 0, 0, LV_COLOR_YELLOW, LV_ALIGN_CENTER, "Left"); //left select button
    createButton(2, 160, 80, 0, 0, LV_COLOR_YELLOW, LV_ALIGN_IN_RIGHT_MID, "Right"); //right select button
    createButton(3, 160, 80, 0, 0, LV_COLOR_YELLOW, LV_ALIGN_IN_TOP_MID, "Skills"); //skills select button
    createButton(4, 160, 80, 0, 0, LV_COLOR_WHITE, LV_ALIGN_IN_TOP_LEFT, "Left"); //current selection display
    createButton(5, 160, 80, 0, 0, LV_COLOR_GREEN, LV_ALIGN_IN_LEFT_MID, "Motor Screen"); //motor setup screen button

    //setup motor screen buttons
    createButton(6, 120, 60, 0, 0, LV_COLOR_RED, LV_ALIGN_IN_TOP_RIGHT, "Motor"); //motor number display and cycler
    createButton(7, 120, 60, 0, -30, LV_COLOR_BLUE, LV_ALIGN_IN_RIGHT_MID, "Port"); //port number display and cycler
    createButton(8, 120, 60, 0, 30, LV_COLOR_RED, LV_ALIGN_IN_RIGHT_MID, "Save All"); //motor settings save button
    createButton(9, 120, 60, 0, 0, LV_COLOR_BLUE, LV_ALIGN_IN_BOTTOM_RIGHT, "Exit"); //motor settings exit button
    createButton(10, 120, 60, 0, 0, LV_COLOR_BLUE, LV_ALIGN_IN_TOP_LEFT, "Axis 1"); //axis 1 display and cycler
    createButton(11, 120, 60, 0, 30, LV_COLOR_BLUE, LV_ALIGN_IN_LEFT_MID, "Axis 2"); //axis 2 display and cycler
    createButton(12, 120, 60, 0, -30, LV_COLOR_RED, LV_ALIGN_IN_LEFT_MID, "Reverse Out"); //axis 1 reverse output toggle
    createButton(13, 120, 60, 0, 0, LV_COLOR_RED, LV_ALIGN_IN_BOTTOM_LEFT, "Reverse Out"); //axis 2 reverse output toggle
    createButton(14, 120, 60, 120, 0, LV_COLOR_RED, LV_ALIGN_IN_TOP_LEFT, "Modifier"); //modifier axis 1 display and cycler
    createButton(15, 120, 60, 120, 30, LV_COLOR_RED, LV_ALIGN_IN_LEFT_MID, "Modifier"); //modifier axis 2 display and cycler
    createButton(16, 120, 60, 120, -30, LV_COLOR_BLUE, LV_ALIGN_IN_LEFT_MID, "Mod Low"); //modifier axis 1 low amount display and cycler
    createButton(17, 120, 60, 120, 0, LV_COLOR_BLUE, LV_ALIGN_IN_BOTTOM_LEFT, "Mod Low"); //modifier axis 2 low amount display and cycler
    createButton(18, 120, 60, 240, 0, LV_COLOR_BLUE, LV_ALIGN_IN_TOP_LEFT, "Mod High"); //modifier axis 1 high amount display and cycler
    createButton(19, 120, 60, 240, 30, LV_COLOR_BLUE, LV_ALIGN_IN_LEFT_MID, "Mod High"); //modifier axis 2 high amount display and cycler

    //hide motor screen buttons
    for (int i = 0; i < 14; i++){
		lv_obj_set_hidden(objects[6+i], true);
	}

    //rumble that bot is ready
    master.rumble("..");
}