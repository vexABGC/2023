#include "main.h"
#include <fstream>
#include "../src/globals.hpp"
#include "../src/ControlPeriodMethods/controlGlobals.hpp"
#include "../src/ControlPeriodMethods/initialize.hpp"
//initialization of program code, NOTE: blocks other competition modes
void initializeMethod(){
    //create menu tabs. autonomous menu button, main button, and status label
	//autonomousMenuButton.Init(lv_scr_act(), "Autonomous", LV_ALIGN_IN_TOP_LEFT, 0, 0, 120, 80);
	//mainMenuButton.Init(lv_scr_act(), "Main Menu", LV_ALIGN_IN_LEFT_MID, 0, 0, 120, 80);
	statusMenuButton.Init(lv_scr_act(), "Loading", 0, lv_action_t(), LV_ALIGN_CENTER, 0, 0, 0, 0);

	//create record button(not yet implemented)

	//load file and split input lines
	std::string line;
	std::ifstream inputFile(autonomousCodeLocation);
	if (inputFile.is_open()){
		while (std::getline(inputFile, line))
		{
			emulatedInputLines.push_back(line);
		}
		inputFile.close();
	};

	//display ready
	//statusMenuButton.SetText("Ready");
}