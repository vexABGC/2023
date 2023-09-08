//includes
#include "../src/Periods/periods.hpp"
#include "../src/Control/Movement.hpp"

//definition
//disabled code, runs during the disabled state of Field Management System or the VEX Competition Switch, following either autonomous or opcontrol
void Disabled(){
    //fake controller input
    int controllerInputs[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    
    //pass to movement
    Movement(controllerInputs);
}