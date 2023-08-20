#include "main.h"
using std::string;
class Label{
    private: lv_obj_t* label;
    public: void Init(lv_obj_t* screen, string text, lv_align_t alignment = LV_ALIGN_IN_TOP_LEFT, lv_coord_t shiftX = 0, lv_coord_t shiftY = 0){
        //create label and store
        this->label = lv_label_create(screen, NULL);
        lv_label_set_text(this->label, text.c_str());
        lv_obj_align(label, NULL, alignment, shiftX, shiftY);
    }
    public: void setText(string text){
        lv_label_set_text(this->label, text.c_str());
    }
};