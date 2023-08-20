//includes and namespaces
#include "main.h"
#include <iomanip>
using std::string;
using std::to_string;

//storage format:
//each line is an input state
//each value in a line is separated by a comma

//define input state class
//stores controller inputs state on creation
//when requested will compile the inputs state into a loadable form for later
class InputState {
    private:pros::Controller controller = (pros::E_CONTROLLER_MASTER);
    public:string CompileSaveLine(){
        //store inputs as array of ints
        int inputs[16] = {
            controller.get_analog(ANALOG_LEFT_X),
            controller.get_analog(ANALOG_LEFT_Y),
            controller.get_analog(ANALOG_RIGHT_X),
            controller.get_analog(ANALOG_RIGHT_Y),
            controller.get_digital(DIGITAL_UP),
            controller.get_digital(DIGITAL_DOWN),
            controller.get_digital(DIGITAL_LEFT),
            controller.get_digital(DIGITAL_RIGHT),
            controller.get_digital(DIGITAL_A),
            controller.get_digital(DIGITAL_B),
            controller.get_digital(DIGITAL_X),
            controller.get_digital(DIGITAL_Y),
            controller.get_digital(DIGITAL_L1),
            controller.get_digital(DIGITAL_L2),
            controller.get_digital(DIGITAL_R1),
            controller.get_digital(DIGITAL_R2)
        };

        //join array into string line
        string inputLine = "";
        for (int i = 0; i < 16; i++){
            inputLine.append(to_string(inputs[i]) + ",");
        }
        inputLine.pop_back();
        
        //return inputLine
        return inputLine;
    }
};