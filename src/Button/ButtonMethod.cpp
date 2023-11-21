//includes
#include <sstream>
#include "../src/Button/buttonMethod.hpp"
#include "../src/EasyControl/EasyControlMethods.hpp"
#include "../src/globals.hpp"

//statics
#define motorSettings 14

//definition
//button method
lv_res_t buttonMethod(lv_obj_t* btn){
	int id = lv_obj_get_free_num(btn);
	switch (id)
	{
		case 0:
			//autonomous track button pressed
			//enable autonomous tracking and rumble controller
			should_track = true;
			master.rumble("..");
			break;
		case 1:
			//left auton button pressed, update autonomous location
			autonomous_location = left_autonomous_location;

			//change button text
			lv_obj_clean(objects[4]);
			lv_label_set_text(lv_label_create(objects[4], NULL), "Left");
			break;
		case 2:
			//right auton button pressed, update autonomous location
			autonomous_location = right_autonomous_location;

			//change button text
			lv_obj_clean(objects[4]);
			lv_label_set_text(lv_label_create(objects[4], NULL), "Right");
			break;
		case 3:
			//skills auton button pressed, update autonomous location
			autonomous_location = skills_autonomous_location;

			//change button text
			lv_obj_clean(objects[4]);
			lv_label_set_text(lv_label_create(objects[4], NULL), "Auton");
			break;
		case 4:
			//current mode selected "button"
			//ignore
			break;
		case 5:
			//motor settings button
			//remove all buttons from main screen
			for (int i = 0; i < 6; i++){
				lv_obj_set_hidden(objects[i], true);
			}

			//activate motor settings buttons
			for (int i = 0; i < motorSettings; i++){
				lv_obj_set_hidden(objects[6+i], false);
			}

			//setup motor display
			if (motor_number > 8){
				motor_number = 1;
			}
			UpdateMotorDisplay(objects[6], motor_number);

			//setup port display
			UpdatePortDisplay(objects[7], port_numbers[motor_number-1]);

			//setup axis 1 display
			UpdateAxisOneDisplay(objects[10], axis_one[motor_number-1]);

			//setup axis 2 display
			UpdateAxisTwoDisplay(objects[11], axis_two[motor_number-1]);
			break;
		case 6:
			//motor number display and cycler
			//update motor num and motor display
			CycleNumber(motor_number, 1, 8);
			UpdateMotorDisplay(objects[6], motor_number);

			//update port display
			UpdatePortDisplay(objects[7], port_numbers[motor_number-1]);

			//update axis 1 display
			UpdateAxisOneDisplay(objects[10], axis_one[motor_number-1]);

			//update axis 2 display
			UpdateAxisTwoDisplay(objects[11], axis_two[motor_number-1]);
			break;
		case 7:
			//port number display and cycler
			//update port display and num
			CycleNumber(port_numbers[motor_number-1], 0, 8);
			UpdatePortDisplay(objects[7], port_numbers[motor_number-1]);
			break;
		case 8:
			//motor settings save button
			//add later
			break;
		case 9:
			//motor settings exit button
			//activate buttons from main screen
			for (int i = 0; i < 6; i++){
				lv_obj_set_hidden(objects[i], false);
			}

			//remove motor settings buttons
			for (int i = 0; i < motorSettings; i++){
				lv_obj_set_hidden(objects[6+i], true);
			}
			break;
		case 10:
			//axis 1 cycler
			CycleNumber(axis_one[motor_number-1], 0, 9);
			UpdateAxisOneDisplay(objects[10], axis_one[motor_number-1]);
			break;
		case 11:
			//axis 2 cycler
			CycleNumber(axis_two[motor_number-1], 0, 9);
			UpdateAxisTwoDisplay(objects[11], axis_two[motor_number-1]);
			break;
	}
	return LV_RES_OK;
}