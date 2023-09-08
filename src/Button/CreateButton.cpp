//includes
#include "main.h"
#include "../src/Button/CreateButton.hpp"
#include "../src/Button/ButtonMethod.hpp"

//method definition, method used to easily create button using pointers for continuity
void createButton(lv_obj_t* button, lv_style_t* style, uint32_t number, lv_color_t color, lv_align_t alignment, std::string text){
    //copy plain style into style, and set color
    lv_style_copy(style, &lv_style_plain);
    (*style).body.main_color = color;
    (*style).body.grad_color = color;

    //create button with alignment, size, button method/number, styles, and label with text
    button = lv_btn_create(lv_scr_act(), NULL);
    lv_obj_set_free_num(button, number);
    lv_btn_set_action(button, LV_BTN_ACTION_CLICK, buttonMethod);
    lv_obj_set_size(button, 160, 80);
    lv_obj_align(button, NULL, alignment, 0, 0);
    lv_btn_set_style(button, LV_BTN_STATE_REL, style);
    lv_btn_set_style(button, LV_BTN_STATE_PR, &lv_style_plain);
    lv_label_set_text(lv_label_create(button, NULL), text.c_str());
}