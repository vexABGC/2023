#include "main.h"
#include <fstream>
#include "../src/globals.hpp"
#include "../src/ControlPeriodMethods/controlGlobals.hpp"
#include "../src/ControlPeriodMethods/initialize.hpp"
//lv_obj_t tabView;
//temporary button function
lv_res_t buttonMethod(lv_obj_t* btn){
	int id = lv_obj_get_free_num(btn);
	master.set_text(0,0,std::to_string(id));
	switch (id)
	{
	case 0:
		//lv_tabview_set_tab_act(&tabView, 0, false);
		break;
	case 1:
		//lv_tabview_set_tab_act(&tabView, 1, false);
		break;
	case 2:
		//lv_tabview_set_tab_act(&tabView, 2, false);
		break;
	case 3:
		//enable autonomous tracking
		should_track = not should_track;
		master.set_text(0, 0, "auton");
		break;
	}
	return LV_RES_OK;
}
//initialization of program code, NOTE: blocks other competition modes
void initializeMethod(){
	master.set_text(0, 0, "ready");
	//create tab screens and set invisible tabs
	//lv_obj_t* tabView = lv_tabview_create(lv_scr_act(), NULL);
	//lv_obj_t *lv_scr_act() = lv_tabview_add_tab(tabView, ""); // No text needed for tabs
	//lv_obj_t *lv_scr_act() = lv_tabview_add_tab(tabView, "");    // as they will be hidden
	//lv_obj_t *lv_scr_act() = lv_tabview_add_tab(tabView, "");
	//lv_tabview_set_btns_hidden(tabView, true);

	//setup autonomous menu
	autonomous_menu_button.init(lv_scr_act(), buttonMethod, "Autonomous", 3, LV_COLOR_RED, LV_ALIGN_IN_TOP_LEFT, 0, 0, 160, 80);
	main_menu_button.init(lv_scr_act(), buttonMethod, "Main Menu", 1, LV_COLOR_GREEN, LV_ALIGN_IN_LEFT_MID, 0, 0, 160, 80);
	status_menu_button.init(lv_scr_act(), buttonMethod, "Loading", 2, LV_COLOR_BLUE, LV_ALIGN_IN_BOTTOM_LEFT, 0, 0, 160, 80);
	
	//setup main menu
	autonomous_menu_button.init(lv_scr_act(), buttonMethod, "Autonomous", 3, LV_COLOR_RED, LV_ALIGN_IN_TOP_LEFT, 0, 0, 160, 80);
	main_menu_button.init(lv_scr_act(), buttonMethod, "Main Menu", 1, LV_COLOR_GREEN, LV_ALIGN_IN_LEFT_MID, 0, 0, 160, 80);
	status_menu_button.init(lv_scr_act(), buttonMethod, "Loading", 2, LV_COLOR_BLUE, LV_ALIGN_IN_BOTTOM_LEFT, 0, 0, 160, 80);

	//setup status menu
	autonomous_menu_button.init(lv_scr_act(), buttonMethod, "Autonomous", 3, LV_COLOR_RED, LV_ALIGN_IN_TOP_LEFT, 0, 0, 160, 80);
	main_menu_button.init(lv_scr_act(), buttonMethod, "Main Menu", 1, LV_COLOR_GREEN, LV_ALIGN_IN_LEFT_MID, 0, 0, 160, 80);
	status_menu_button.init(lv_scr_act(), buttonMethod, "Loading", 2, LV_COLOR_BLUE, LV_ALIGN_IN_BOTTOM_LEFT, 0, 0, 160, 80);

	//display ready
	//status_menu_button.setText("Ready");
}