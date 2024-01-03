//includes
#include "main.h"
#include "../src/Periods/periods.hpp"
#include "../src/globals.hpp"
#include "../src/Control/Movement.hpp"
#include "../src/Math/Vector.hpp"
#include <sstream>
#include <fstream>
#include <iostream>

//constants
#define inputsLR 750
#define inputsS 3000

//definition
//autonomous mode code
void OperatorControl(){
    //rumble to notify of op control
    master.rumble("..");

    //input tracker local globals
    int8_t inputs[48000] = {};

    //odometry local globals
    Distance wheelDiameter = 4_in;
    Distance wheelTrack = 16_in;
    Distance wheelBackDistance = 3_in;
    DistanceVector<long double, FeetRatio> position(0_ft, 0_ft);
    Angle lWheel = 0_tck;
    Angle rWheel = 0_tck;
    Angle bWheel = 0_tck;
    Angle orientation = 0_rad;
    
    //control loop
    while (true) {
        //odometry
        //calculate wheel deltas in ticks
        //delta ticks = ticks new - ticks old
        Angle<long double, TicksRatio> lDeltaTicks = l_encoder.get_value() - lWheel.getAngle();
        Angle<long double, TicksRatio> rDeltaTicks = r_encoder.get_value() - rWheel.getAngle();
        Angle<long double, TicksRatio> bDeltaTicks = b_encoder.get_value() - bWheel.getAngle();

        //calculate wheel deltas in inches
        //distance = radius * radians
        //distance = diameter * radians / 2
        Distance lDeltaInches = wheelDiameter * lDeltaTicks.toRadians().getAngle() / 2.0;
        Distance rDeltaInches = wheelDiameter * rDeltaTicks.toRadians().getAngle() / 2.0;
        Distance bDeltaInches = wheelDiameter * bDeltaTicks.toRadians().getAngle() / 2.0;

        //update pervious encoder values
        lWheel = lWheel + lDeltaTicks;
        rWheel = rWheel + rDeltaTicks;
        bWheel = bWheel + bDeltaTicks;

        //calculate total wheel travel in inches
        //distance = diameter * radians / 2
        Distance lTotalInches = wheelDiameter * lWheel.toRadians().getAngle() / 2.0;
        Distance rTotalInches = wheelDiameter * rWheel.toRadians().getAngle() / 2.0;
        Distance bTotalInches = wheelDiameter * bWheel.toRadians().getAngle() / 2.0;

        //calculate delta orientation
        //orientation = (l total - r total ) / wheel track
        Angle deltaOrientation = 1_rad * ((lDeltaInches - rDeltaInches) / wheelTrack);

        //update previous orientation
        orientation = orientation + deltaOrientation;

        //calculate local offset depending on if our orientation has changed
        DistanceVector<long double, InchesRatio> localDelta(0_in, 0_in);
        if (deltaOrientation == 0_rad){
            //same orientation
            localDelta.setX(bDeltaInches);
            localDelta.setY(rDeltaInches);
        }else{
            //new orientation
            //dx = 2sin(theta/2) * ((delta back/delta theta) + back distance)
            //dy = 2sin(theta/2) * ((delta right/delta theta) + 0.5 * wheel track)
            localDelta.setX(((bDeltaInches/orientation.getAngle()) + wheelBackDistance) * 2 * sinl(orientation.getAngle()/2.0));
            localDelta.setY(((rDeltaInches/orientation.getAngle()) + wheelTrack/2) * 2 * sinl(orientation.getAngle()/2.0));
        }

        //calculate average orientation 
        //avg = new - delta / 2
        Angle averageOrientation = orientation - deltaOrientation / 2.0;

        //calculate global offset as local offset rotated by average orientation
        Angle localAngle = localDelta.getAngleRadians();
        Distance localMagnitude = localDelta.getMagnitude();
        DistanceVector<long double, InchesRatio> globalDelta(averageOrientation + localAngle, localMagnitude);

        //update position
        position = position + globalDelta.toFeet();

        //display position
        std::stringstream textX("X Position:\n");
        std::stringstream textY("Y Position:\n");
        textX << position.getX().getDistance();
        textY << position.getY().getDistance();
        lv_label_set_text(lv_label_create(objects[5], NULL), textX.str().c_str());
        lv_label_set_text(lv_label_create(objects[6], NULL), textY.str().c_str());

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
            //get maximum tracks for mode tracked
            int maxTrack = ((autonomous_mode == 2) ? inputsS : inputsLR);

            //check if regular tracking or end of tracking
            if(tracker_count < maxTrack){
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
                for (int i = 0; i < maxTrack * 16; i++){
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