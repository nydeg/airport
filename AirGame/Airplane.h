//#pragma once
#ifndef AIRPLANE_H
#define AIRPLANE_H

#include "iostream"
#include "Date.h"

using std::cout;
using std::string;

class Airplane {
public:

private:
	string status;
	Date takeoffTime;
	Date boardingTime;
	int deviation; // in minutes

	Date timeToUp;
	Date timeToDown;
	int maxLaps;
	int lengthAirstrip;
	int oneLipInMinute;

};

#endif AIRPLAHE_H