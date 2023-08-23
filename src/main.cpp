//includes
#include "main.h"
#include "display/lvgl.h"
#include "../src/globals.hpp"
#include "../src/Control/InputState.hpp"
#include "../src/Graphics/Button.hpp"
#include "../src/Math/Vector2.hpp"
#include "../src/Control/Movement.hpp"
#include <string>
#include <vector>
#include <fstream>

//using definitions
using std::vector;
using std::ifstream;
using std::getline;
using std::stoi;
using std::string;

//local globals
Button autonomousMenuButton;
Button mainMenuButton;
Button statusMenuButton;
bool shouldTrack = false;
bool previousShouldTrack = shouldTrack;
vector<string> emulatedInputLines;

//initialization of program code, NOTE: blocks other competition modes
void initialize() {
	//create menu tabs. autonomous menu button, main button, and status label
	//autonomousMenuButton.Init(lv_scr_act(), "Autonomous", LV_ALIGN_IN_TOP_LEFT, 0, 0, 120, 80);
	//mainMenuButton.Init(lv_scr_act(), "Main Menu", LV_ALIGN_IN_LEFT_MID, 0, 0, 120, 80);
	statusMenuButton.Init(lv_scr_act(), "Loading", 0, lv_action_t(), LV_ALIGN_CENTER, 0, 0, 0, 0);

	//create record button(not yet implemented)

	//load file and split input lines
	string line;
	ifstream inputFile(autonomousCodeLocation);
	if (inputFile.is_open()){
		while (getline(inputFile, line))
		{
			emulatedInputLines.push_back(line);
		}
		inputFile.close();
	};

	//display ready
	//statusMenuButton.SetText("Ready");
}
//disabled code, runs during the disabled state of Field Management System or the VEX Competition Switch, following either autonomous or opcontrol
void disabled() {}


//competition initialization, enabled during both autonomous and opcontrol
void competition_initialize() {}

//autonomous mode code
void autonomous() {
	//disable screen buttons, and notify user of disabled buttons(in event of accidental locking)
	//statusMenuButton.SetText("Locked");

	//iterate through each input line
	for (int i = 0; i < emulatedInputLines.size(); i++){
		//get input line string and process into emulated inputs
		string inputLine = emulatedInputLines.at(i);

		//get current input stage's emulated inputs
		int emulatedInput[16];
		int count = 0;
		string separator = ",";
		string splitPart;
		size_t pos = 0;
		while ((pos = inputLine.find(separator)) != std::string::npos) {
		    splitPart = inputLine.substr(0, pos);
		    std::cout << splitPart << std::endl;
		    inputLine.erase(0, pos + separator.length());
		}

		//call movement with emulated movement
		Movement(emulatedInput);
		
		//delay
		pros::delay(time_delay);
	}
}

//driver control mode
void opcontrol() {
	//setup input tracker
	vector<InputState> inputStates;
	int trackerCount = 0;
	while (true) {
		//read in LCD button input and print to LCD(Removed due to interference with LVGL)
		//pros::lcd::print(0, "%d %d %d", (pros::lcd::read_buttons() & LCD_BTN_LEFT) >> 2,
		//                 (pros::lcd::read_buttons() & LCD_BTN_CENTER) >> 1,
		//                 (pros::lcd::read_buttons() & LCD_BTN_RIGHT) >> 0);

		//get inputs
		int controllerInputs[16] = {
            master.get_analog(ANALOG_LEFT_X),  //input #00
            master.get_analog(ANALOG_LEFT_Y),  //input #01
            master.get_analog(ANALOG_RIGHT_X), //input #02
            master.get_analog(ANALOG_RIGHT_Y), //input #03
            master.get_digital(DIGITAL_UP),    //input #04
            master.get_digital(DIGITAL_DOWN),  //input #05
            master.get_digital(DIGITAL_LEFT),  //input #06
            master.get_digital(DIGITAL_RIGHT), //input #07
            master.get_digital(DIGITAL_A),     //input #08
            master.get_digital(DIGITAL_B),     //input #09
            master.get_digital(DIGITAL_X),     //input #10
            master.get_digital(DIGITAL_Y),     //input #11
            master.get_digital(DIGITAL_L1),    //input #12
            master.get_digital(DIGITAL_L2),    //input #13
            master.get_digital(DIGITAL_R1),    //input #14
            master.get_digital(DIGITAL_R2)     //input #15
        };

		//pass to movement function
		Movement(controllerInputs);

		//track input
		if (shouldTrack){
			//update previous should track
			previousShouldTrack = shouldTrack;
			//check if should end tracking
			if (trackerCount > 15 * 1000/time_delay) {
				shouldTrack = false;
			}
			trackerCount += 1;
			//update screen
			master.set_text(0,0,"Auto: "+ trackerCount);
			//track input
			InputState inputState;
			inputStates.push_back(inputState);
		}else if((!shouldTrack) and previousShouldTrack){
			//just ended tracking should save our tracked inputs
			//update previous should track
			previousShouldTrack = false;

			//process tracked inputs into file output
			string trackedInputsOutput = "";
			for (int i = 0; i < inputStates.size(); i++){
				trackedInputsOutput.append(inputStates[i].CompileSaveLine(master) + "\n");
			}
			trackedInputsOutput.pop_back();

			//save processed tracked inputs
			FILE* usd_input_save = fopen(autonomousCodeLocation.c_str(), "w");
			fputs(trackedInputsOutput.c_str(), usd_input_save);
			fclose(usd_input_save);
		}

		//wait 20 milliseconds to next op control period
		pros::delay(time_delay);
	}
}