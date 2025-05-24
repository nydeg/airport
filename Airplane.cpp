#include "Airplane.h"
#include <vector>
#include <iostream>
#include "Dispatcher.h"
#include "Level.h"
#include <cmath>
#include <random>
#include "Airstrip.h"


using namespace std;

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

    static std::random_device rd;  // Источник энтропии
    static std::mt19937 gen(rd()); // Генератор (Mersenne Twister)
    std::uniform_int_distribution<> distrib(0, 100); // Равномерное распределение

    //ind = 1;
    //x = 30;
    //y = 30;


    ind = distrib(gen)%4;

    //ind = 1;

    switch(ind) {
        case(0): {
            x = 30;
            y = 870;
            break;
        }
        case(1): {
            x = 30;
            y = 30;
            break;
        }
        case(2): {
            x = 1480;
            y = 30;
            break;
        }
        case(3): {
            x = 1480;
            y = 870;
            break;
        }
    };

    test.setScale(sf::Vector2f(100,100));
    test.setFillColor(sf::Color::Red);
    test.setPosition(0,0);


	cout << "airplane was created\n";

}


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

LapCoordinate Airplane::findNearestPoint(int x0, int y0, vector<LapCoordinate>& points) {
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

int Airplane::MoveInLap(Level *level,  int& status, Airstrip* airstrip) {
        vector<LapCoordinate> lapCoordinates = level->getLapCoordinates();

        if(MovingNewLap(lapCoordinates[this->getCornenrInd()].x, lapCoordinates[this->getCornenrInd()].y, status, airstrip)) {
            return 1;
        }
        return 0;

    //cout << "point -- > "  <<this->getCornenrInd() << "\n";
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

void Airplane::MoveFromHangarToAirstrip(Level *level, int airstripNumber) {
    vector<pair<int, int> > path;
    Airstrip *curAirstrip = level->getAirstrips()[airstripNumber];
    path.push_back(level->getRoadHangarForTakeoffCoordinates());
    path.push_back(curAirstrip->getStartInRoad());
    path.push_back(curAirstrip->getStart());
    // draw a path here
}

void Airplane::MoveFromAirstripToHangar(Level *level, int airstripNumber) {
    vector<pair<int, int> > path;
    Airstrip *curAirstrip = level->getAirstrips()[airstripNumber];
    path.push_back(curAirstrip->getStartInRoad());
    path.push_back(level->getRoadHangarForBoardingCoordinates());
    path.push_back(level->getHangarForBoardingCoordinates());
    // draw a path here
}


int Airplane::DeleteAirplane(Level *level) {
    // int airplaneIndex = find(level->getAirplanes().begin(), level->getAirplanes().end(), this);
    int airplaneIndex = 0;
    for (int i = 0; i < level->getAirplanes().size(); i++) {
        if (level->getAirplanes()[i] == this) {
            airplaneIndex = i;
            break;
        }
    }

    level->getAirplanes().erase(level->getAirplanes().begin() + airplaneIndex);
    //delete this;

    return airplaneIndex;
}

void Airplane::Moving(int x, int y, string new_status) {
    //cout << "MOOVING!!!" << "\n";
    if (this->getX() != x || this->getY() != y) {
        //cout << x << " " << y << "\n";
        if (this->getX() > x) this->x--;
        else if (this->getX() < x) this->x++;
        else {
            if (this->getY() > y) this->y--;
            else if (this->getY() < y) this->y++;
        }
        //cout << "--> " << getX() << " " << getY() << "\n";
    } else {

        // send to the queue
        this->setStatus(new_status);
    }
}

int Airplane::MovingNewLap(int x, int y, int& status, Airstrip* airstrip) {

    if(ind == 0) {
        if(getStatus() == "boarding_startPoint") {
            return 1;
        }
    }

    if (this->getX() != x || this->getY() != y) {
        if (this->getX() > x) this->x--;
        else if (this->getX() < x) this->x++;
        else {
            if (this->getY() > y) this->y--;
            else if (this->getY() < y) this->y++;
        }

    }else {


            ind = (ind+1)%4;
            return 0;
            //cout << "--> " << ind << "\t" << getX() << " " << getY() << "\n";
    }
    return 0;

}

void Airplane::BoardingStartPoint(int startX, int startY) {
    Moving(startX, startY, "boarding_endPoint");
}

void Airplane::BoardingEndPoint(Level *level, Dispatcher *dispatcher, int endX, int endY) {
    if (this->getX() != endX || this->getY() != endY) {
        Moving(endX, endY, "landed");
    } else {

        // delete plane
        int index = this->DeleteAirplane(level);
        level->setIndexOfLastDeletedPlane(index);
        // increase user score
        dispatcher->setCurrentScore(dispatcher->getCurrentScore() + 1);
    }
}

void Airplane::TakeOffStartPoint(int startX, int startY) {
    Moving(startX, startY, "takeoff_endPoint");
}

void Airplane::TakeOffEndPoint(Level* level, Dispatcher* dispatcher, int endX, int endY) {
    if (this->getX() != endX && this->getY() != endY) {
        Moving(endX, endY, "takeoff");
    }
    else {

        // delete plane
        int index = this->DeleteAirplane(level);
        level->setIndexOfLastDeletedPlane(index);
        // increase user score
        dispatcher->setCurrentScore(dispatcher->getCurrentScore() + 1);
    }
}

void Airplane::TakeOff(Level* level) {
    this->setStatus("take_off");
    int index = this->DeleteAirplane(level);
    level->setIndexOfLastDeletedPlane(index);
}