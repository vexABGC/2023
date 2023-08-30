#include "main.h"
class InputState {
    private: std::string saveLine;
    public: void CompileSaveLine(pros::Controller controller);
    public: std::string GetSaveLine();
};