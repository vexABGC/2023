//includes
#include "main.h"

//declaration
class InputState {
    private: std::string saveLine;
    public: InputState(pros::Controller controller);
    public: std::string GetSaveLine();
};