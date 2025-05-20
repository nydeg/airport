#include "Cargo.h"
#include "Level.h"
#include "Dispatcher.h"
#include "Airstrip.h"

void Cargo::work(Level *level, Dispatcher *dispatcher, Airstrip *airstrip, int x, int y) {
    if (this->getStatus() == "moving_to_request") {
        this->MovingToRequest(x, y);
    }
    else if (this->getStatus() == "moving_new_lap") {
        this->MovingNewLap(x, y);
    }
    else if (this->getStatus() == "boarding_startPoint") {
        this->BoardingStartPoint(airstrip->getStart().first, airstrip->getStart().second);
    }
    else if (this->getStatus() == "boarding_endPoint") {
        this->BoardingEndPoint(level, dispatcher, airstrip->getEnd().first, airstrip->getEnd().second);
    }
    else if (this->getStatus() == "take_off") {
        this->TakeOff(level);
    }
}
