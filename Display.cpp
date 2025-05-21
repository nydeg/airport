#include "Display.h"

Display::Display() {
}

Display::Display(vector<Airplane *> *flights, vector<Airstrip *> *Airstrips) {
    schedule = flights;
    strips = Airstrips;
    cout << "\n --> Dispaly was created!\n";
}

Display::Display(Date curr, int fine, int score, vector<Airplane *>* flights, vector<Airstrip*>* Airstrips) {
    currTime = curr;
    currFine = fine;
    currScore = score;
    schedule = flights;
    strips = Airstrips;

    cout << "\n --> Dispaly was created!\n";
}

void Display::showingInfo() {
    
}
