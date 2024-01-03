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
			tracker_count = 0;
			master.rumble("..");
			break;
		case 1:
			//left auton button pressed, update autonomous location
			autonomous_mode = 0;

			//change button text
			lv_obj_clean(objects[4]);
			lv_label_set_text(lv_label_create(objects[4], NULL), "Left");
			break;
		case 2:
			//right auton button pressed, update autonomous location
			autonomous_mode = 1;

			//change button text
			lv_obj_clean(objects[4]);
			lv_label_set_text(lv_label_create(objects[4], NULL), "Right");
			break;
		case 3:
			//skills auton button pressed, update autonomous location
			autonomous_mode = 2;

			//change button text
			lv_obj_clean(objects[4]);
			lv_label_set_text(lv_label_create(objects[4], NULL), "Skills");
			break;
		case 4:
			//current mode selected "button"
			//ignore
			break;
		case 5:
			//x position "button"
			//ignore
			break;
		case 6:
			//y position "button"
			//ignore
			break;
	}
	return LV_RES_OK;
}