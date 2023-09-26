//includes
#include "main.h"
#include "../src/Periods/periods.hpp"
#include "../src/globals.hpp"
#include "../src/Control/InputState.hpp"
#include "../src/Control/Movement.hpp"
#include <fstream>
#include <iostream>

//definition
//autonomous mode code
void OperatorControl(){
    //rumble to notify of op control
    master.rumble("..");

    //input tracker local globals
    int numInputs = 15 * (1000/time_delay);
    InputState inputStates[750];
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
            if (trackerCount > numInputs){
                should_track = false;
            }

            //track input and store
            InputState inputState(master);
            inputStates[trackerCount] = inputState;

            //update tracking count
            trackerCount += 1;
        }else if((!should_track) && previousShouldTrack){
            //just ended tracking, should save tracked info
            //update previous should track
            previousShouldTrack = false;

            //rumble to notify end tracking
            master.rumble("..");

            //store inputs
            //open file at autonomous location
            std::ofstream file(autonomous_location, std::ios::binary);

            //setup data pointer, loop through each input state, get input state data, loop through each piece of data, convert each piece, and write each piece
            int8_t inputData[16];
            char* dataByte;
            for (int inputState = 0; inputState < numInputs; inputState++){
                inputStates[inputState].GetData(inputData);
                for (int dataIndex = 0; dataIndex < 16; dataIndex++){
                    dataByte = reinterpret_cast<char *>(&(inputData[dataIndex]));
                    file.write(dataByte,1);
                }
            }
        }

        //wait time delay amount until next op control cycle
        pros::delay(time_delay);
    }
}