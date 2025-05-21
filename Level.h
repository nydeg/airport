//#pragma once
#ifndef LEVEL_H
#define LEVEL_H

#include <iostream>
#include <vector>

using namespace std;

class Airplane;
class Airstrip;

struct LapCoordinate {
	int x;
	int y;
	string position; // upper right/left corner, lower right/left corner
};

class Level {
public:

	Level(int levelNumber);

	void initLapCoordinates();

	//access
	int getFine() { return fine; }
	vector<Airstrip*> getAirstrips() { return airstrips; }
	vector<Airplane*> getAirplanes() { return airplanes; }
	int getScore() { return score; }
	int getCountOfAirplanes() { return countOfAirplanes; }
	vector<LapCoordinate> getLapCoordinates() { return this->lapCoordinates; }

private:
	int fine;
	vector<Airstrip*> airstrips;
	vector<Airplane*> airplanes;
	int score;
	int countOfAirplanes;

	vector<LapCoordinate> lapCoordinates;

	//startSchedule
};

#endif LEVEL_h
