//includes
#include "main.h"
#include "../src/Periods/periods.hpp"
#include "../src/globals.hpp"
#include "../src/Control/Movement.hpp"
#include <fstream>
#include <vector>

//usings
using std::string;
using std::ifstream;
using std::getline;
using std::vector;

//definition
//autonomous mode code
void Autonomous(){
    //declare needed variables
    vector<string> inputLines;

    //rumble to notify of autonomous
    master.rumble("..");

    //load file, split input lines, and store
    string line;
    ifstream inputFile(autonomous_location);
    if (inputFile.is_open()){
		while (std::getline(inputFile, line))
		{
			inputLines.push_back(line);
		}
		inputFile.close();
	}

    //iterate through each input line
    for (int lineNum = 0; lineNum < inputLines.size(); lineNum++){
        //get input line
        string inputLine = inputLines.at(lineNum);

        //setup necessary variables for next stage, including error handling emulated inputs
        int emulatedInput[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
        int count = 0;
        string stringValue;
        size_t pos = 0;
        
        //loop through each value of the line
        while ((pos = inputLine.find(string(","))) != string::npos){
            //get current string value from line, convert it to an integer, and store in emulated input
            emulatedInput[count] = std::stoi(inputLine.substr(0, pos));

            //erase value
            inputLine.erase(0, pos + string(",").length());

            //increment counter
            count = count + 1;
        }

        //pass emulated movement to movement to move
        Movement(emulatedInput);

        //delay until next movement cycle
        pros::delay(time_delay);
    }
}