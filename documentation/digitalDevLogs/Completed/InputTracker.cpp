//includes
#include "main.h"
#include "display/lvgl.h"
#include "../src/Control/InputState.cpp"
#include "../src/Graphics/Button.cpp"
#include "../src/Math/Vector2.hpp"
#include <string>
#include <vector>
#include <fstream>

//using definitions
using std::vector;
using std::ifstream;
using std::getline;
using std::stoi;
using std::string;

//definitions and globals
#define time_delay 20 //milliseconds
#define left_mtr_port 1
#define right_mtr_port 2
Button autonomous_menu_button;
Button main_menu_button;
Button status_menu_button;

pros::Controller master(pros::E_CONTROLLER_MASTER);
pros::Motor left_mtr(left_mtr_port);
pros::Motor right_mtr(right_mtr_port);

std::string autonomous_code_location = "/usd/autonomousMovement.routine";
bool should_track = false;
bool previous_should_track = should_track;
vector<string> emulated_input_lines;

//movement code / function
void Movement(int controllerInputs[16]){
    //take in joystick inputs
    Vector2<int> leftJoystick(controllerInputs[0], controllerInputs[1]);
    Vector2<int> rightJoystick(controllerInputs[2], controllerInputs[3]);

    //update motors
    left_mtr.move(leftJoystick.getY());
    right_mtr.move(rightJoystick.getY());
}

//file loading(INSIDE VEX INITIALIZE)
//load file and split input lines
string line;
ifstream inputFile(autonomous_code_location);
if (inputFile.is_open()){
	while (getline(inputFile, line))
	{
		emulated_input_lines.push_back(line);
	}
	inputFile.close();
};



//file parsing and executing (INSIDE VEX AUTONOMOUS)
//iterate through each input line
for (int i = 0; i < emulated_input_lines.size(); i++){
	//get input line string and process into emulated inputs
	string inputLine = emulated_input_lines.at(1);

	//get current input stage's emulated inputs
	int emulatedInput[16];
	int count = 0;
	string splitPart;
	while (getline(inputLine, splitPart, ",")){
		//convert line to int and store
		emulatedInput[count] = stoi(splitPart);
		//increment
		count++;
	}

	//call movement with emulated movement
	Movement(emulatedInput);
	
	//delay
	pros::delay(time_delay);
};



//tracking code and saving (INSIDE VEX OPERATOR CONTROL)
//iterate through each input line
for (int i = 0; i < emulated_input_lines.size(); i++){
	//get input line string and process into emulated inputs
	string inputLine = emulated_input_lines.at(i);

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

//driver control mode
//setup input tracker
vector<InputState> inputStates;
int trackerCount = 0;
while (true) {
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
	if (should_track){
		//update previous should track
		previous_should_track = should_track;

		//check if should end tracking
		if (trackerCount > 15 * 1000/time_delay) {
			should_track = false;
		}
		trackerCount += 1;

		//update screen
		//master.set_text("Auto: " + trackerCount);
		//track input
		InputState inputState;
		inputStates.push_back(inputState);
	}else if((!should_track) and previous_should_track){
		//just ended tracking should save our tracked inputs
		//update previous should track
		previous_should_track = false;

		//process tracked inputs into file output
		string trackedInputsOutput = "";
		for (int i = 0; i < inputStates.size(); i++){
			trackedInputsOutput.append(inputStates[i].CompileSaveLine() + "\n");
		}
		trackedInputsOutput.pop_back();

		//save processed tracked inputs
		FILE* usd_input_save = fopen(autonomous_code_location.c_str(), "w");
		fputs(trackedInputsOutput.c_str(), usd_input_save);
		fclose(usd_input_save);
	}

	//wait 20 milliseconds to next op control period
	pros::delay(time_delay);
}