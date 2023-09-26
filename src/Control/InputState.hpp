//includes
#include "main.h"

//declaration
class InputState {
    private: int8_t data[16];
    public: InputState();
    public: InputState(pros::Controller controller);
    public: void GetData(int8_t* dataPointer);
};