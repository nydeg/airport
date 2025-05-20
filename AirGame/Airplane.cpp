#include "Airplane.h"

#include "Dispatcher.h"
#include "Level.h"

void Airplane::DeleteAirplane(Level *level) {
    // int airplaneIndex = find(level->getAirplanes().begin(), level->getAirplanes().end(), this);
    int airplaneIndex = 0;
    for (int i = 0; i < level->getAirplanes().size(); i++) {
        if (level->getAirplanes()[i] == this) {
            airplaneIndex = i;
            break;
        }
    }
    level->getAirplanes().erase(level->getAirplanes().begin() + airplaneIndex);
    delete this;
}

void Airplane::MovingToRequest(int x, int y) {
    if (this->getX() != x || this->getY() != y) {
        // change coordinates
    }
    else {
        // send to the queue
        this->setStatus("board_waiting");
    }
}

void Airplane::MovingNewLap(int x, int y) {
    if (this->getX() != x || this->getY() != y) {
        // change coordinates
    }
    else {
        this->setStatus("moving_to_request");
    }
}

void Airplane::BoardingStartPoint(int startX, int startY) {
    if (this->getX() != startX || this->getY() != startY) {
        // change coordinates
    }
    else {
        this->setStatus("boarding_endPoint");
    }
}

void Airplane::BoardingEndPoint(Level *level, Dispatcher *dispatcher, int endX, int endY) {
    if (this->getX() != endX || this->getY() != endY) {
        // change coordinates
    }
    else {
        this->setStatus("landed");

        // delete plane
        this->DeleteAirplane(level);
        // increase user score
        dispatcher->setCurrentScore(dispatcher->getCurrentScore() + 1);
    }
}

void Airplane::TakeOff(Level *level) {
    this->setStatus("take_off");
    this->DeleteAirplane(level);
}

