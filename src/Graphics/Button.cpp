#include "Button.hpp"
#include "Label.hpp"
void Button::init(lv_obj_t* screen, lv_action_t buttonMethod, std::string text, int buttonNum, lv_color_t buttonColor, lv_align_t alignment, lv_coord_t shiftX = 0, lv_coord_t shiftY = 0, int sizeX = 100, int sizeY = 100){
    ////create style for released button
    //lv_style_t styleReleased;
    //lv_style_copy(&styleReleased, &lv_style_plain);
    //styleReleased.body.main_color = buttonColor;
    //styleReleased.body.radius = 0;
    //styleReleased.text.color = LV_COLOR_WHITE;

    ////create style for pressed button
    //lv_style_t stylePressed;
    //lv_style_copy(&stylePressed, &lv_style_plain);
    //uint8_t colorShift = 30;
    //uint8_t colorRed = buttonColor.red - colorShift;
    //uint8_t colorBlue = buttonColor.blue - colorShift;
    //uint8_t colorGreen = buttonColor.green - colorShift;
    //stylePressed.body.main_color = LV_COLOR_MAKE(colorRed, colorGreen, colorBlue);
    //stylePressed.body.radius = 0;
    //stylePressed.text.color = LV_COLOR_WHITE;

    //create button
    this->button = lv_btn_create(screen, NULL);
    lv_obj_set_free_num(this->button, buttonNum);
    lv_btn_set_action(this->button, LV_BTN_ACTION_CLICK, buttonMethod);
    lv_obj_set_size(this->button, sizeX, sizeY);
    //lv_btn_set_style(this->button, LV_BTN_STYLE_REL, &styleReleased);
    //lv_btn_set_style(this->button, LV_BTN_STYLE_PR, &stylePressed);
    lv_obj_align(this->button, NULL, alignment, shiftX, shiftY);

    //create and set button label
    Label label;
    label.init(this->button, text, LV_ALIGN_CENTER, 0, 0);
}
void Button::setText(std::string text){
    Label label;
    label.init(this->button, text, LV_ALIGN_CENTER, 0, 0);
}
void Button::setColor(lv_color_t color){
    //create style for released button
    //lv_style_t styleReleased;
    //lv_style_copy(&styleReleased, &lv_style_plain);
    //styleReleased.body.main_color = color;
    //styleReleased.body.radius = 0;
    //styleReleased.text.color = LV_COLOR_WHITE;
//
    ////create style for pressed button
    //lv_style_t stylePressed;
    //lv_style_copy(&stylePressed, &lv_style_plain);
    //uint8_t colorShift = 30;
    //uint8_t colorRed = color.red - colorShift;
    //uint8_t colorBlue = color.blue - colorShift;
    //uint8_t colorGreen = color.green - colorShift;
    //stylePressed.body.main_color = LV_COLOR_MAKE(colorRed, colorGreen, colorBlue);
    //stylePressed.body.radius = 0;
    //stylePressed.text.color = LV_COLOR_WHITE;
}