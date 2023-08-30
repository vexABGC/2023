#include "main.h"
#include <fstream>
#include "../src/globals.hpp"
#include "../src/ControlPeriodMethods/controlGlobals.hpp"
#include "../src/ControlPeriodMethods/initialize.hpp"
#include "../src/Graphics/ButtonMethodHandler.hpp"
//initialization of program code, NOTE: blocks other competition modes
void initializeMethod(){
	//create tab screens and set invisible tabs
	tabView = lv_tabview_create(lv_scr_act(), NULL);
	lv_obj_t *tabAutonomous = lv_tabview_add_tab(tabView, ""); // No text needed for tabs
	lv_obj_t *tabMain = lv_tabview_add_tab(tabView, "");    // as they will be hidden
	lv_obj_t *tabStatus = lv_tabview_add_tab(tabView, "");
	lv_tabview_set_btns_hidden(tabView, true);

	//setup autonomous menu
	//tabs
	Button autonomous_menu_tab(tabAutonomous, ButtonMethod, "Auton", 0, LV_COLOR_RED, LV_ALIGN_IN_TOP_LEFT, 0, 0, 160, 80);
	Button main_menu_tab(tabAutonomous, ButtonMethod, "Main", 1, LV_COLOR_GREEN, LV_ALIGN_IN_LEFT_MID, 0, 0, 160, 80);
	Button status_menu_tab(tabAutonomous, ButtonMethod, "Status", 2, LV_COLOR_BLUE, LV_ALIGN_IN_BOTTOM_LEFT, 0, 0, 160, 80);
	//content
	//add autonomous left and right routine buttons
	Button autonomous_left(tabAutonomous, ButtonMethod, "Left", 4, LV_COLOR_PURPLE, LV_ALIGN_IN_BOTTOM_MID, 0, 0, 160, 80);
	Button autonomous_right(tabAutonomous, ButtonMethod, "Right", 5, LV_COLOR_PURPLE, LV_ALIGN_IN_BOTTOM_RIGHT, 0, 0, 160, 80);
	//add record movement button
	Button track_button(tabAutonomous, ButtonMethod, "Track", 7, LV_COLOR_RED, LV_ALIGN_IN_TOP_RIGHT, 0, 0, 160, 80);
	
	//setup main menu
	//tabs
	Button autonomous_menu_tab(tabMain, ButtonMethod, "Auton", 0, LV_COLOR_RED, LV_ALIGN_IN_TOP_LEFT, 0, 0, 160, 80);
	Button main_menu_tab(tabMain, ButtonMethod, "Main", 1, LV_COLOR_GREEN, LV_ALIGN_IN_LEFT_MID, 0, 0, 160, 80);
	Button status_menu_tab(tabMain, ButtonMethod, "Status", 2, LV_COLOR_BLUE, LV_ALIGN_IN_BOTTOM_LEFT, 0, 0, 160, 80);
	//content
	//add toggle enemy avoidance pause button
	Button enemy_avoidance(tabMain, ButtonMethod, "Avoid", 6, LV_COLOR_RED, LV_ALIGN_IN_LEFT_MID, 0, 0, 160, 80);

	//setup status menu
	//tabs
	Button autonomous_menu_tab(tabStatus, ButtonMethod, "Auton", 0, LV_COLOR_RED, LV_ALIGN_IN_TOP_LEFT, 0, 0, 160, 80);
	Button main_menu_tab(tabStatus, ButtonMethod, "Main", 1, LV_COLOR_GREEN, LV_ALIGN_IN_LEFT_MID, 0, 0, 160, 80);
	Button status_menu_tab(tabStatus, ButtonMethod, "Status", 2, LV_COLOR_BLUE, LV_ALIGN_IN_BOTTOM_LEFT, 0, 0, 160, 80);
	//content

	//set active tab
	lv_tabview_set_tab_act(tabView, 1, false);

	//load file and split input lines
	std::string line;
	std::ifstream inputFile(autonomous_code_location);
	if (inputFile.is_open()){
		while (std::getline(inputFile, line))
		{
			emulated_input_lines.push_back(line);
		}
		inputFile.close();
	};
}