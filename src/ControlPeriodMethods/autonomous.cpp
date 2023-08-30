#include "../src/ControlPeriodMethods/autonomous.hpp"
#include "../src/ControlPeriodMethods/controlGlobals.hpp"
#include "../src/Control/Movement.hpp"
#include "../src/globals.hpp"
#include <fstream>
//autonomous mode code
void autonomousMethod(){
    //disable screen buttons, and notify user of disabled buttons(in event of accidental locking)
	//status_menu_button.SetText("Locked");
	master.set_text(0, 0, "auton active");
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

	//iterate through each input line
	master.set_text(0, 0,"running auton");
	std::string inputLine;
	for (int i = 0; i < emulated_input_lines.size(); i++){
		//get input line string and process into emulated inputs
		inputLine = emulated_input_lines.at(i);

		//get current input stage's emulated inputs
		int emulatedInput[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
		int count = 0;
		std::string separator = ",";
		std::string splitPart;
		size_t pos = 0;
		int counter = 0;
		while ((pos = inputLine.find(separator)) != std::string::npos) {
		    splitPart = inputLine.substr(0, pos);
			//set emulated input
			emulatedInput[counter] = std::stoi(splitPart);
		    inputLine.erase(0, pos + separator.length());
			counter = counter + 1;
		}

		//call movement with emulated movement
		Movement(emulatedInput);
		
		//delay
		pros::delay(time_delay);
	}
}