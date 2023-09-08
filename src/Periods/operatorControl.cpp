//includes
#include "main.h"
#include "../src/Periods/periods.hpp"
#include "../src/globals.hpp"
#include "../src/Control/InputState.hpp"
#include "../src/Control/Movement.hpp"
#include <vector>
#include <iostream>

//using declarations
using std::vector;
using std::string;

//definition
//autonomous mode code
void OperatorControl(){
    //rumble to notify of op control
    master.rumble("..");

    //input tracker local globals
    vector<InputState> inputStates;
    int trackerCount = 0;
    bool previousShouldTrack = false;
    while (true) {
        //get inputs and store
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

        //input tracking
        //check if should track and if should store
        if (should_track){
            //should track
            //update previous should track
            previousShouldTrack = true;

            //check if should end tracking
            if (trackerCount > 15 * (1000/time_delay)){
                should_track = false;
            }

            //update tracking count
            trackerCount += 1;

            //track input and store
            InputState inputState(master);
            inputStates.push_back(inputState);
        }else if((!should_track) && previousShouldTrack){
            //just ended tracking, should save tracked info
            //update previous should track
            previousShouldTrack = false;

            //rumble to notify end tracking
            master.rumble("..");

            //process tracked inputs into file output
            string trackedInputsOutput = "";
			for (int i = 0; i < inputStates.size(); i++){
				trackedInputsOutput.append(inputStates[i].GetSaveLine() + "\n");
			}
			trackedInputsOutput.pop_back();

            //save processed file output
            FILE* usd_input_save = fopen(autonomous_location.c_str(), "w");
            fputs(trackedInputsOutput.c_str(), usd_input_save);
            fclose(usd_input_save);
        }

        //wait time delay amount until next op control cycle
        pros::delay(time_delay);
    }
}