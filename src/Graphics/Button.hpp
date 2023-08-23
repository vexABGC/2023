#include "main.h"
#include "../src/Graphics/Label.hpp"
class Button{
    private: lv_obj_t* button;
    public: void Init(lv_obj_t* screen, std::string text, int buttonNum, lv_action_t buttonFunction, lv_align_t alignment, lv_coord_t shiftX , lv_coord_t shiftY, int sizeX, int sizeY);
    public: void SetText(std::string text);
};