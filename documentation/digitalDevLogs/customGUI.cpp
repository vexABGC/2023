//includes
#include <main.h>

//label class declaration
class Label {
    private: lv_obj_t* label;
    
    public: Label(lv_obj_t* screen, std::string text, lv_align_t alignment, lv_coord_t shiftX, lv_coord_t shiftY){
        //create label and store
        this->label = lv_label_create(screen, NULL);
        lv_label_set_text(this->label, text.c_str());
        lv_obj_align(label, NULL, alignment, shiftX, shiftY);
    }

    public: void setText(std::string text){
        lv_label_set_text(this->label, text.c_str());
    }
};

//button class declaration
class Button {
    private: lv_obj_t* button;
    
    public: Button(lv_obj_t* screen, lv_action_t buttonMethod, std::string text, int buttonNum, lv_color_t buttonColor, lv_align_t alignment, lv_coord_t shiftX = 0, lv_coord_t shiftY = 0, int sizeX = 100, int sizeY = 100){
        //create button
        this->button = lv_btn_create(screen, NULL);
        lv_obj_set_free_num(this->button, buttonNum);
        lv_btn_set_action(this->button, LV_BTN_ACTION_CLICK, buttonMethod);
        lv_obj_set_size(this->button, sizeX, sizeY);
        lv_btn_set_style(this->button, LV_BTN_STYLE_REL, &lv_style_plain);
        lv_btn_set_style(this->button, LV_BTN_STYLE_PR, &lv_style_plain);
        lv_obj_align(this->button, NULL, alignment, shiftX, shiftY);

        //create and set button label
        Label label(this->button, text, LV_ALIGN_CENTER, 0, 0);
    }

    public:void setText(std::string text){
        Label label(this->button, text, LV_ALIGN_CENTER, 0, 0);
    }
};

//example
Button button(lv_scr_act(), NULL, "Test button", 0, LV_COLOR_RED, LV_ALIGN_IN_TOP_LEFT, 0, 0, 160, 80);
Label label (lv_scr_act(), "Test label", LV_ALIGN_IN_LEFT_MID, 0, 0);