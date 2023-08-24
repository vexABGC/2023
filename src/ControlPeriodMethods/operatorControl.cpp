#include "../src/ControlPeriodMethods/operatorControl.hpp"
#include "../src/globals.hpp"
#include "../src/ControlPeriodMethods/controlGlobals.hpp"
#include "../src/Control/InputState.hpp"
#include "../src/Control/Movement.hpp"
#include <vector>
//driver control mode
void operatorControlMethod(){
    //setup input tracker
	std::vector<InputState> inputStates;
	int trackerCount = 0;
	while (true) {
		//read in LCD button input and print to LCD(Removed due to interference with LVGL)
		//pros::lcd::print(0, "%d %d %d", (pros::lcd::read_buttons() & LCD_BTN_LEFT) >> 2,
		//                 (pros::lcd::read_buttons() & LCD_BTN_CENTER) >> 1,
		//                 (pros::lcd::read_buttons() & LCD_BTN_RIGHT) >> 0);

		//get inputs
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

		//track input
		if (should_track){
			//update previous should track
			previous_should_track = should_track;
			//check if should end tracking
			if (trackerCount > 15 * 1000/time_delay) {
				should_track = false;
			}
			trackerCount += 1;
			//update screen
			master.set_text(0,0,"Auto: "+ trackerCount);
			//track input
			InputState inputState;
			inputStates.push_back(inputState);
		}else if((!should_track) and previous_should_track){
			//just ended tracking should save our tracked inputs
			//update previous should track
			previous_should_track = false;

			//process tracked inputs into file output
			std::string trackedInputsOutput = "";
			for (int i = 0; i < inputStates.size(); i++){
				trackedInputsOutput.append(inputStates[i].CompileSaveLine(master) + "\n");
			}
			trackedInputsOutput.pop_back();

			//save processed tracked inputs
			FILE* usd_input_save = fopen(autonomous_code_location.c_str(), "w");
			fputs(trackedInputsOutput.c_str(), usd_input_save);
			fclose(usd_input_save);
		}

		//wait 20 milliseconds to next op control period
		pros::delay(time_delay);
	}
}