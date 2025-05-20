#include "Display.h"

Display::Display() {
}

Display::Display(Date curr, int fine, int score, vector<Airplane *>* flights, vector<Airstrip*>* Airstrips) {
    currTime = curr;
    currFine = fine;
    currScore = score;
    schedule = flights;
    strips = Airstrips;
}
