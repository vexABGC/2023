#include "../src/Graphics/ButtonMethodHandler.hpp"
#include "../src/globals.hpp"
lv_res_t ButtonMethod(lv_obj_t* button){
    uint8_t id = lv_obj_get_free_num(button);
    switch (id){
        case 0:
            //autonomous menu tab
            lv_tabview_set_tab_act(tabView, 0, false);
            break;
        case 1:
            //main menu tab
            lv_tabview_set_tab_act(tabView, 1, false);
            break;
        case 2:
            //status menu tab
            lv_tabview_set_tab_act(tabView, 2, false);
            break;
        case 4:
            //left autonomous mode button
            autonomousSide = false; //false = left, true = right
            break;
        case 5:
            //right autonomous mode button
            autonomousSide = true; //false = left, true = right
            break;
        case 6:
            //avoidance button
            //set variable
            should_avoid = !should_avoid;
            //set color
            enemy_avoidance.setColor(should_avoid ? LV_COLOR_GREEN : LV_COLOR_RED);
            break;
        case 7:
            //track button
            //set variable
            should_track = !should_avoid;
            //set color
            track_button.setColor(should_track ? LV_COLOR_GREEN : LV_COLOR_RED);
            break;
    }
    return LV_RES_OK;
}