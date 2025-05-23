//#pragma once
#ifndef MILITARY_H
#define MILITARY_H

#include "Airplane.h"

#define TIME_FOR_ONE_LIP 30
#define LENGTH_OF_REQUIRED_AIRSTRIP 50

class Military : public Airplane{
public:
	Military() { cout << "Military was created\n"; }

	Military(int boardNumber, string stata, Date date, int maxLaps);

	~Military() { cout << "Military was deleted\n"; }
private:

};

#endif MILITARY_H