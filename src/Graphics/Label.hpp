#include "main.h"
class Label {
    private: lv_obj_t* label;
    public: void init(lv_obj_t* screen, std::string text, lv_align_t alignment, lv_coord_t shiftX, lv_coord_t shiftY);
    public: void setText(std::string text);
};