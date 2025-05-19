//#pragma once
#ifndef LEVEL_H
#define LEVEL_H

#include <iostream>
#include <vector>

using namespace std;

class Airplane;
class Airstrip;

class Level {
public:

	Level(int levelNumber);

	//access
	int getFine() { return fine; }
	vector<Airstrip*> getAirstrips() { return airstrips; }
	vector<Airplane*> getAirplanes() { return airplanes; }
	int getScore() { return score; }
	int getCountOfAirplanes() { return countOfAirplanes; }

private:
	int fine;
	vector<Airstrip*> airstrips;
	vector<Airplane*> airplanes;
	int score;
	int countOfAirplanes;

	//startSchedule
};

#endif LEVEL_h
