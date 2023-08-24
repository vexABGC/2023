#include "../src/ControlPeriodMethods/controlGlobals.hpp"
#include <vector>
Button autonomous_menu_button;
Button main_menu_button;
Button status_menu_button;
bool should_track = false;
bool previous_should_track = should_track;
std::vector<std::string> emulated_input_lines;