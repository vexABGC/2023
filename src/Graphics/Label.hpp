#include "main.h"
class Label {
    private: lv_obj_t* label;
    public: void Init(lv_obj_t* screen, std::string text, lv_align_t alignment, lv_coord_t shiftX, lv_coord_t shiftY);
    public: void SetText(std::string text);
};