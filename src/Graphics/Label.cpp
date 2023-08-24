#include "main.h"
#include "../src/Graphics/Label.hpp"
void Label::init(lv_obj_t* screen, std::string text, lv_align_t alignment, lv_coord_t shiftX, lv_coord_t shiftY){
    //create label and store
    this->label = lv_label_create(screen, NULL);
    lv_label_set_text(this->label, text.c_str());
    lv_obj_align(label, NULL, alignment, shiftX, shiftY);
}
void Label::setText(std::string text){
    lv_label_set_text(this->label, text.c_str());
}