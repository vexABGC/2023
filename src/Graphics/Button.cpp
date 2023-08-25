#include "main.h"
#include "../src/Graphics/Button.hpp"
#include "../src/Graphics/Label.hpp"
void Button::init(lv_obj_t* screen, std::string text, int buttonNum, lv_action_t buttonFunction, lv_align_t alignment, lv_coord_t shiftX = 0, lv_coord_t shiftY = 0, int sizeX = 100, int sizeY = 100){
    //create style for button
    //lv_style_t style_btn();
    //lv_style
    //create button and store
    this->button = lv_btn_create(screen, NULL);
    lv_btn_set_action(this->button, LV_BTN_ACTION_CLICK, buttonFunction);
    lv_obj_set_size(this->button, sizeX, sizeY);
    lv_obj_align(this->button, NULL, alignment, shiftX, shiftY);

    //create and set button label
    Label label;
    label.init(this->button, text, LV_ALIGN_CENTER, 0, 0);
}
void Button::setText(std::string text){
    Label label;
    label.init(this->button, text, LV_ALIGN_CENTER, 0, 0);
}