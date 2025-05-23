#include <vector>
#include <iostream>
#include "Airplane.h"
#include "Dispatcher.h"
#include "Level.h"
#include <cmath>

#include "Airstrip.h"

using namespace std;

LapCoordinate nextLapCoordinate(LapCoordinate curLapCoordinate, vector<LapCoordinate> coordinates) {
    if (curLapCoordinate.position == "upper-right") {
        return coordinates[1];
    } else if (curLapCoordinate.position == "upper-left") {
        return coordinates[2];
    } else if (curLapCoordinate.position == "lower-left") {
        return coordinates[3];
    } else if (curLapCoordinate.position == "lower-right") {
        return coordinates[0];
    }
}

LapCoordinate Airplane::findNearestPoint(int x0, int y0, vector<LapCoordinate> points) {
    LapCoordinate res;
    int minn = 1e9;
    for (auto p: points) {
        int cur = sqrt((p.x - x0) * (p.x - x0) + (p.y - y0) * (p.y - y0));
        if (cur < minn) {
            res = p;
        }
    }
    return res;
}

void Airplane::MoveInLap(Level *level) {
    vector<LapCoordinate> path;
    vector<LapCoordinate> lapCoordinates = level->getLapCoordinates();
    LapCoordinate startLapPoint = findNearestPoint(this->x, this->y, lapCoordinates);
    // nearest lap point from current place
    path.push_back(startLapPoint);
    if (startLapPoint.position == "upper-right") {
        path.push_back(lapCoordinates[1]);
        path.push_back(lapCoordinates[2]);
        path.push_back(lapCoordinates[3]);
    } else if (startLapPoint.position == "upper-left") {
        path.push_back(lapCoordinates[2]);
        path.push_back(lapCoordinates[3]);
        path.push_back(lapCoordinates[0]);
    } else if (startLapPoint.position == "lower-left") {
        path.push_back(lapCoordinates[3]);
        path.push_back(lapCoordinates[0]);
        path.push_back(lapCoordinates[1]);
    } else if (startLapPoint.position == "lower-right") {
        path.push_back(lapCoordinates[0]);
        path.push_back(lapCoordinates[1]);
        path.push_back(lapCoordinates[2]);
    }
    // draw a path here
}

void Airplane::MoveToAirstrip(Level *level, int airstripNumber) {
    vector<pair<int, int> > path;
    Airstrip *curAirstrip = level->getAirstrips()[airstripNumber];
    vector<LapCoordinate> lapCoordinates = level->getLapCoordinates();
    LapCoordinate curLapPoint = findNearestPoint(this->x, this->y, lapCoordinates);
    path.push_back({curLapPoint.x, curLapPoint.y});
    while (curLapPoint.position != "upper-left") {
        curLapPoint = nextLapCoordinate(curLapPoint, lapCoordinates);
        path.push_back({curLapPoint.x, curLapPoint.y});
    }
    path.push_back(curAirstrip->getEndInSky());
    path.push_back(curAirstrip->getEnd());
    path.push_back(curAirstrip->getStart());
    // draw a path here
}

void Airplane::MoveToTakeoff(Level *level, int airstripNumber) {
    vector<pair<int, int> > path;
    Airstrip *curAirstrip = level->getAirstrips()[airstripNumber];
    path.push_back(curAirstrip->getStart());
    path.push_back(curAirstrip->getEnd());
    path.push_back(curAirstrip->getEndInSky());
    // draw a path here
}

Airplane::Airplane()
{
	deviation = 0;
	status = "";
	maxLaps = 0;
	boardNumber = 0;
	lengthOfAirstrip = 0;
	oneLipInMinute = 0;
	Date currDate;
	timeOfAction = currDate;
void Airplane::MoveFromHangarToAirstrip(Level *level, int airstripNumber) {
    vector<pair<int, int> > path;
    Airstrip *curAirstrip = level->getAirstrips()[airstripNumber];
    path.push_back(level->getRoadHangarForTakeoffCoordinates());
    path.push_back(curAirstrip->getStartInRoad());
    path.push_back(curAirstrip->getStart());
    // draw a path here
}

	cout << "airplane was created\n";
void Airplane::MoveFromAirstripToHangar(Level *level, int airstripNumber) {
    vector<pair<int, int> > path;
    Airstrip *curAirstrip = level->getAirstrips()[airstripNumber];
    path.push_back(curAirstrip->getStartInRoad());
    path.push_back(level->getRoadHangarForBoardingCoordinates());
    path.push_back(level->getHangarForBoardingCoordinates());
    // draw a path here
}



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
    } else {
        // send to the queue
        this->setStatus("board_waiting");
    }
}

void Airplane::MovingNewLap(int x, int y) {
    if (this->getX() != x || this->getY() != y) {
        // change coordinates
    } else {
        this->setStatus("moving_to_request");
    }
}

void Airplane::BoardingStartPoint(int startX, int startY) {
    if (this->getX() != startX || this->getY() != startY) {
        // change coordinates
    } else {
        this->setStatus("boarding_endPoint");
    }
}

void Airplane::BoardingEndPoint(Level *level, Dispatcher *dispatcher, int endX, int endY) {
    if (this->getX() != endX || this->getY() != endY) {
        // change coordinates
    } else {
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
