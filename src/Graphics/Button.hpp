#include "main.h"
class Button{
    private: lv_obj_t* button;
    public: void init(lv_obj_t* screen, lv_action_t buttonMethod, std::string text, int buttonNum, lv_color_t buttonColor, lv_align_t alignment, lv_coord_t shiftX , lv_coord_t shiftY, int sizeX, int sizeY);
    public: void setText(std::string text);
    public: void setColor(lv_color_t color);
};