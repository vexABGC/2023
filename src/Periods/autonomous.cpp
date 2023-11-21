//includes
#include "main.h"
#include "../src/Periods/periods.hpp"
#include "../src/globals.hpp"
#include "../src/Control/Movement.hpp"
#include <fstream>

//definition
//autonomous mode code
void Autonomous(){
    //rumble to notify of autonomous
    master.rumble("..");

    //important numbers
    int numInputs = 15*1000/time_delay;

    //get file at autonomous location
    FILE* file = fopen(left_autonomous_location.c_str(), "r");
    if (file == NULL){
        std::cout << "open error" << std::endl;
        return;
    }

    //read file as binary into data
    char data[numInputs * 16];
    fgets(data, numInputs*16, file);

    //close file
    fclose(file);

    //declare emulated input array
    int emulatedInput[16];

    //iterate through each input group
    for (int inputGroup = 0; inputGroup < numInputs; inputGroup++){
        //iterate through each input of input group
        for (int inputIndex = 0; inputIndex < 16; inputIndex++){
            //store data at location (16 times input group plus input index) to emulated input array
            emulatedInput[inputIndex] = static_cast<int8_t>(data[inputGroup*16 + inputIndex]);
            std::cout << (int)(data[inputGroup*16 + inputIndex]) << " ";
        }

        std::cout << std::endl;

        //pass emulated movement to movement method to move robot
        Movement(emulatedInput);

        //delay until next movement cycle
        pros::delay(time_delay);
    }
}