//#pragma once
#ifndef LEVEL_H
#define LEVEL_H

#include <iostream>
#include "Airplane.h"
#include "Airstrip.h"
#include "Lap.h"
#include <vector>
using namespace std;

class Airplane;
class Airstrip;




class Level {
public:

	Level(int levelNumber);
	Level();

	void initLapCoordinates();

	void scheduleSort();

	//access
	int getFine() { return fine; }
	int getLevelNum() { return level_num; }
	int getScore() { return score; }
	int getCountOfAirplanes() { return countOfAirplanes; }

	vector<Airstrip*>& getAirstrips() { return airstrips; }
	vector<Airplane*>& getAirplanes() { return airplanes; }
	vector<LapCoordinate> getLapCoordinates() { return this->lapCoordinates; }

	pair<int, int> getHangarForTakeoffCoordinates() { return this->hangarForTakeoffCoordinates; }
	pair<int, int> getHangarForBoardingCoordinates() { return this->hangarForBoardingCoordinates; }
	pair<int, int> getRoadHangarForTakeoffCoordinates() { return this->roadHangarForTakeoffCoordinates; }
	pair<int, int> getRoadHangarForBoardingCoordinates() { return this->roadHangarForBoardingCoordinates; }

private:
	int fine;
	int level_num;
	vector<Airstrip*> airstrips;
	vector<Airplane*> airplanes;
	int score;
	int countOfAirplanes;

	vector<LapCoordinate> lapCoordinates;

	pair<int, int> hangarForTakeoffCoordinates;
	pair<int, int> roadHangarForTakeoffCoordinates;
	pair<int, int> hangarForBoardingCoordinates;
	pair<int, int> roadHangarForBoardingCoordinates;



	//startSchedule
};

#endif LEVEL_h
