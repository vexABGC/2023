#include "../src/ControlPeriodMethods/controlGlobals.hpp"
#include <vector>
Button autonomousMenuButton;
Button mainMenuButton;
Button statusMenuButton;
bool shouldTrack = false;
bool previousShouldTrack = shouldTrack;
std::vector<std::string> emulatedInputLines;