//includes
#include "main.h"
#include "../src/Periods/periods.hpp"
#include "../src/globals.hpp"
#include "../src/Control/Movement.hpp"
//#include "../src/Math/Vector.hpp"
#include <sstream>
#include <fstream>
#include <iostream>

//constants
#define numInputs 750

//definition
//autonomous mode code
void OperatorControl(){
    //rumble to notify of op control
    master.rumble("..");

    //input tracker local globals
    int8_t inputs[12000] = {};
    
    //control loop
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
        //check if should track
        if(should_track){
            //check if regular tracking or end of tracking
            if(tracker_count < numInputs){
                //track input and store
                for (int i = 0; i < 16; i++){
                    inputs[tracker_count*16 + i] = controllerInputs[i];
                }
            }else{
                //disable should track
                should_track = false;

                //create file name
                std::stringstream fileName;
                fileName << "/usd/";
                fileName << autonomous_mode;
                fileName << ".routine";

                //open file
                std::ofstream file(fileName.str(), std::ios::binary);

                //loop through each recorded data point and write to file
                for (int i = 0; i < numInputs * 16; i++){
                    file.write(reinterpret_cast<const char*>(&(inputs[i])), 1);
                }

                //rumble controller
                master.rumble("--");
            }

            //increment count
            tracker_count++;
        }

        //wait time delay amount until next op control cycle
        pros::delay(time_delay);
    }
}