//#pragma once
#ifndef AIRSTRIP_H
#define AIRSTRIP_H

#include<iostream>

using namespace std;

class Airstrip {
public:

	Airstrip();

	Airstrip(pair<int,int> st, pair<int,int> end);

	//access
	pair<int, int> getStart() { return start; }
	pair<int, int> getEnd() { return end; }
	pair<int, int> getEndInSky() { return this->endInSky; }
	pair<int, int> getStartInRoad() { return this->startInRoad; }
	int getLength() { return length; }

private:
	pair<int, int> start;
	pair<int, int> end;
	pair<int, int> endInSky;
	pair<int, int> startInRoad;
	int length; // compute from start and end
	string status;
};

#endif AIRSTRIP_H