//includes
//#include "main.h"
//#include "../src/globals.hpp"

//buttonM method definition
lv_res_t buttonMethod(lv_obj_t* btn){
    //button handle code
    return LV_RES_OK;
}

//method definition, method used to easily create button using pointers for continuity
void createButton(uint32_t number, lv_coord_t width, lv_coord_t height, lv_coord_t shiftX, lv_coord_t shiftY, lv_color_t color, lv_align_t alignment, std::string text){
    //create style, copy plain style into style, and set color
    styles[number] = lv_style_t();
    lv_style_copy(&styles[number], &lv_style_plain);
    styles[number].body.main_color = color;
    styles[number].body.grad_color = color;

    //create button with alignment, size, button method/number, styles, and label with text
    objects[number] = lv_btn_create(lv_scr_act(), NULL);
    lv_obj_set_free_num(objects[number], number);
    lv_btn_set_action(objects[number], LV_BTN_ACTION_CLICK, buttonMethod);
    lv_obj_set_size(objects[number], width, height);
    lv_obj_align(objects[number], NULL, alignment, shiftX, shiftY);
    lv_btn_set_style(objects[number], LV_BTN_STATE_REL, &styles[number]);
    lv_btn_set_style(objects[number], LV_BTN_STATE_PR, &lv_style_plain);
    lv_label_set_text(lv_label_create(objects[number], NULL), text.c_str());
}

//example, creates two buttons
lv_obj_t** objects = new lv_obj_t*[2];
lv_style_t** styles = new lv_obj_t*[2];
createButton(0, 160, 80, 0, 0, LV_COLOR_RED, LV_ALIGN_IN_TOP_LEFT, "Button 1");
createButton(1, 160, 80, 0, 0, LV_COLOR_BLUE, LV_ALIGN_IN_LEFT_MID, "Button 2");