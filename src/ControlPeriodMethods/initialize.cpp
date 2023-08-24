#include "main.h"
#include <fstream>
#include "../src/globals.hpp"
#include "../src/ControlPeriodMethods/controlGlobals.hpp"
#include "../src/ControlPeriodMethods/initialize.hpp"
//initialization of program code, NOTE: blocks other competition modes
void initializeMethod(){
    //create menu tabs. autonomous menu button, main button, and status label
	//autonomous_menu_button.init(lv_scr_act(), "Autonomous", LV_ALIGN_IN_TOP_LEFT, 0, 0, 120, 80);
	//main_menu_button.init(lv_scr_act(), "Main Menu", LV_ALIGN_IN_LEFT_MID, 0, 0, 120, 80);
	status_menu_button.init(lv_scr_act(), "Loading", 0, lv_action_t(), LV_ALIGN_CENTER, 0, 0, 0, 0);

	//create record button(not yet implemented)

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

	//display ready
	//status_menu_button.setText("Ready");
}