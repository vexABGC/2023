//includes
#include "../src/Button/buttonMethod.hpp"
#include "../src/globals.hpp"

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
	}
	return LV_RES_OK;
}