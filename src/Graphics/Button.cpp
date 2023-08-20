#include "main.h"
#include "../src/Graphics/Label.cpp"
using std::string;
class Button{
    private: lv_obj_t* button;
    public: void Init(lv_obj_t* screen, string text, int buttonNum, lv_action_t buttonFunction, lv_align_t alignment = LV_ALIGN_IN_TOP_LEFT, lv_coord_t shiftX = 0, lv_coord_t shiftY = 0, int sizeX = 100, int sizeY = 100){
        //create button and store
        this->button = lv_btn_create(screen, NULL);
        lv_btn_set_action(this->button, LV_BTN_ACTION_CLICK, buttonFunction);
        lv_obj_set_size(this->button, sizeX, sizeY);
        lv_obj_align(this->button, NULL, alignment, shiftX, shiftY);

        //create and set button label
        Label label;
        label.Init(this->button, text, LV_ALIGN_CENTER);
    }
    public: void setText(string text){
        Label label;
        label.Init(this->button, text, LV_ALIGN_CENTER);
    }
};