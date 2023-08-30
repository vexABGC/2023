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
	for (int i = 0; i < emulated_input_lines.size(); i++){
		//get input line string and process into emulated inputs
		std::string inputLine = emulated_input_lines.at(i);
		std::cout << inputLine << std::endl;

		//get current input stage's emulated inputs
		int emulatedInput[16];
		int count = 0;
		std::string separator = ",";
		std::string splitPart;
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