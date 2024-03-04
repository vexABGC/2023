//includes
#include "main.h"
#include "../src/Periods/periods.hpp"
#include "../src/globals.hpp"
#include "../src/Control/Movement.hpp"
#include <sstream>
#include <fstream>

//constants
#define numInputs 750
//revolutions * circumference = length, revolutions * pi * 4" = length, revolutions = length/(4pi), revolutions = length * linear multiplier
//linear multiplier = 1/4pi = 0.0397
//wheel tread circumference / wheel circumference = 9.5pi / 4pi = 9.5/4 = 2.375 = robot revolution / wheel revolution
#define linearMultiplier 0.079577471545947667884441881686257181017229822870228224373833672029448398817113267545056901383126542978036421363378979018446455923057289326438983705365849919614619983468704538786538873198462653844358696
#define angularMultiplier 2.375

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
    std::cout << fileName.str() << std::endl;

    //get file at autonomous location
    std::ifstream file(fileName.str());
    if (!file.is_open()){
        std::cout << "open error" << std::endl;
    }

    //first 45 seconds of skills (if skills)
    if (autonomous_mode == 2){
        int startTime = pros::millis();
        std::cout << pros::millis() - startTime << std::endl;
        while (pros::millis() - startTime < 000){
            std::cout << pros::millis() - startTime << std::endl;
            b_intake.move(127);
            l_wing.move_absolute(120, 100);
            r_wing.move_absolute(120, 100);
            pros::delay(100);
        }
        //end of flywheel time, time to move using odom
        //turn off wheel, close wings
        b_intake.move(0);
        l_wing.move_absolute(0, 100);
        r_wing.move_absolute(0, 100);
        pros::delay(200);

        //reverse 2ft
        //left_mtrs.move_relative(24 * linearMultiplier, 30);
        //right_mtrs.move_relative(24 * linearMultiplier, 30);
        while (!(lf_mtr.is_stopped() && lb_mtr.is_stopped() && rf_mtr.is_stopped() && rb_mtr.is_stopped())){
            pros::delay(20);
        }
        master.rumble("..");

        //turn ccw 90 degrees
        left_mtrs.move_relative(-0.25 * angularMultiplier, 30);
        right_mtrs.move_relative(0.25 * angularMultiplier, 30);
        while (!(lf_mtr.is_stopped() && lb_mtr.is_stopped() && rf_mtr.is_stopped() && rb_mtr.is_stopped())){
            pros::delay(20);
        }
        master.rumble("..");

        //TEMPORARY TO TEST
        return;

        //forward 2ft
        left_mtrs.move_relative(24 * linearMultiplier, 150);
        right_mtrs.move_relative(24 * linearMultiplier, 150);
        while (!(lf_mtr.is_stopped() && lb_mtr.is_stopped() && rf_mtr.is_stopped() && rb_mtr.is_stopped())){
            pros::delay(20);
        }
        master.rumble("..");

        //turn ccw 90 degrees
        left_mtrs.move_relative(-0.25 * angularMultiplier, 150);
        right_mtrs.move_relative(0.25 * angularMultiplier, 150);
        while (!(lf_mtr.is_stopped() && lb_mtr.is_stopped() && rf_mtr.is_stopped() && rb_mtr.is_stopped())){
            pros::delay(20);
        }
        master.rumble("..");

        //forward 6ft
        left_mtrs.move_relative(72 * linearMultiplier, 150);
        right_mtrs.move_relative(72 * linearMultiplier, 150);
        while (!(lf_mtr.is_stopped() && lb_mtr.is_stopped() && rf_mtr.is_stopped() && rb_mtr.is_stopped())){
            pros::delay(20);
        }
        master.rumble("..");

        //turn ccw 90 degrees
        left_mtrs.move_relative(-0.25 * angularMultiplier, 150);
        right_mtrs.move_relative(0.25 * angularMultiplier, 150);
        while (!(lf_mtr.is_stopped() && lb_mtr.is_stopped() && rf_mtr.is_stopped() && rb_mtr.is_stopped())){
            pros::delay(20);
        }
        master.rumble("..");

        //open wings
        l_wing.move_absolute(90, 100);
        r_wing.move_absolute(90, 100);
        pros::delay(200);

        //forward 2 ft
        left_mtrs.move_relative(24 * linearMultiplier, 150);
        right_mtrs.move_relative(24 * linearMultiplier, 150);
        while (!(lf_mtr.is_stopped() && lb_mtr.is_stopped() && rf_mtr.is_stopped() && rb_mtr.is_stopped())){
            pros::delay(20);
        }
        master.rumble("..");

        //close wings
        l_wing.move_absolute(0, 100);
        r_wing.move_absolute(0, 100);
        pros::delay(200);
        
        //turn ccw 45 degrees
        left_mtrs.move_relative(-0.125 * angularMultiplier, 150);
        right_mtrs.move_relative(0.125 * angularMultiplier, 150);
        while (!(lf_mtr.is_stopped() && lb_mtr.is_stopped() && rf_mtr.is_stopped() && rb_mtr.is_stopped())){
            pros::delay(20);
        }
        master.rumble("..");

        //forward 2sqrt2 ft
        left_mtrs.move_relative(34 * linearMultiplier, 150);
        right_mtrs.move_relative(34 * linearMultiplier, 150);
        while (!(lf_mtr.is_stopped() && lb_mtr.is_stopped() && rf_mtr.is_stopped() && rb_mtr.is_stopped())){
            pros::delay(20);
        }
        master.rumble("..");

        //turn cw 135 degrees
        left_mtrs.move_relative(-0.375 * angularMultiplier, 150);
        right_mtrs.move_relative(0.375 * angularMultiplier, 150);
        while (!(lf_mtr.is_stopped() && lb_mtr.is_stopped() && rf_mtr.is_stopped() && rb_mtr.is_stopped())){
            pros::delay(20);
        }
        master.rumble("..");

        //open wings
        l_wing.move_absolute(90, 100);
        r_wing.move_absolute(90, 100);
        pros::delay(200);

        //forward 1.5 ft
        left_mtrs.move_relative(18 * linearMultiplier, 150);
        right_mtrs.move_relative(18 * linearMultiplier, 150);
        while (!(lf_mtr.is_stopped() && lb_mtr.is_stopped() && rf_mtr.is_stopped() && rb_mtr.is_stopped())){
            pros::delay(20);
        }
        master.rumble("..");

        //extend wings
        l_wing.move_absolute(135, 100);
        r_wing.move_absolute(135, 100);
        pros::delay(200);

        //close wings
        l_wing.move_absolute(0, 100);
        r_wing.move_absolute(0, 100);
        pros::delay(200);

        //prevent record loading
        return;
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