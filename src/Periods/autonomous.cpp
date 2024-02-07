//includes
#include "main.h"
#include "../src/Periods/periods.hpp"
#include "../src/globals.hpp"
#include "../src/Control/Movement.hpp"
#include <sstream>
#include <fstream>

//constants
#define numInputs 750

//definition
//autonomous mode code
void Autonomous(){
    //rumble to notify of autonomous
    master.rumble("..");

    //create file name
    std::stringstream fileName;
    fileName << "/usd/";
    fileName << autonomous_mode;
    fileName << ".routine";

    //get file at autonomous location
    std::ifstream file(fileName.str());
    if (!file.is_open()){
        std::cout << "open error" << std::endl;
        return;
    }

    //first 45 seconds of skills (if skills)
    if (autonomous_mode == 2){
        int startTime = pros::millis();
        while (pros::millis() - startTime < 45000){
            b_intake.move(127);
            l_wing.move_absolute(90, 200);
            r_wing.move_absolute(90, 200);
            pros::delay(100);
        }
        b_intake.move(0);
        l_wing.move_absolute(0, 200);
        r_wing.move_absolute(0, 200);
    }

    //declare variables for reading and parsing inputs
    int inputs[16] = {};
    char byte;

    //iterate through each input group
    for (int group = 0; group < numInputs; group++){
        //iterate through input of group
        for (int input = 0; input < 16; input++){
            //get data and store into inputs
            file.read(&byte, 1);
            inputs[input] = (int8_t) byte;

            //DEBUG: print byte
            std::cout << byte << " ";
        }
        //DEBUG: separate input groups 
        std::cout << std::endl;

        //pass input to movement method
        Movement(inputs);

        //wait until next cycle
        pros::delay(time_delay);
    }

    //close file
    file.close();
}