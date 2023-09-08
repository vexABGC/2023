//includes
#include "../src/Button/buttonMethod.hpp"
#include "../src/globals.hpp"

//definition
//button method
lv_res_t buttonMethod(lv_obj_t* btn){
	int id = lv_obj_get_free_num(btn);
	master.set_text(0,0,std::to_string(id));
	switch (id)
	{
		case 1:
			//autonomous track button pressed
			//enable autonomous tracking and rumble controller
			should_track = true;
			master.rumble("..");
			break;
		case 2:
			//left auton button pressed, update autonomous location
			autonomous_location = left_autonomous_location;

			//change button colors to indicate chosen autonomous
			(*styles[1]).body.main_color = LV_COLOR_GREEN;
			(*styles[2]).body.main_color = LV_COLOR_YELLOW;
			(*styles[3]).body.main_color = LV_COLOR_YELLOW;
			(*styles[1]).body.grad_color = LV_COLOR_GREEN;
			(*styles[2]).body.grad_color = LV_COLOR_YELLOW;
			(*styles[3]).body.grad_color = LV_COLOR_YELLOW;
			break;
		case 3:
			//right auton button pressed, update autonomous location
			autonomous_location = right_autonomous_location;

			//change button colors to indicate chosen autonomous
			(*styles[1]).body.main_color = LV_COLOR_YELLOW;
			(*styles[2]).body.main_color = LV_COLOR_GREEN;
			(*styles[3]).body.main_color = LV_COLOR_YELLOW;
			(*styles[1]).body.grad_color = LV_COLOR_YELLOW;
			(*styles[2]).body.grad_color = LV_COLOR_GREEN;
			(*styles[3]).body.grad_color = LV_COLOR_YELLOW;
			break;
		case 4:
			//skills auton button pressed, update autonomous location
			autonomous_location = skills_autonomous_location;

			//change button colors to indicate chosen autonomous
			(*styles[1]).body.main_color = LV_COLOR_YELLOW;
			(*styles[2]).body.main_color = LV_COLOR_YELLOW;
			(*styles[3]).body.main_color = LV_COLOR_GREEN;
			(*styles[1]).body.grad_color = LV_COLOR_YELLOW;
			(*styles[2]).body.grad_color = LV_COLOR_YELLOW;
			(*styles[3]).body.grad_color = LV_COLOR_GREEN;
			break;
	}
	return LV_RES_OK;
}