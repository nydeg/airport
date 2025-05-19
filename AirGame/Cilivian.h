//#pragma once
#ifndef CIVILIAN_H
#define CIVILIAN_H

#include "Airplane.h"

#define TIME_FOR_ONE_LIP 50
#define LENGTH_OF_REQUIRED_AIRSTRIP 90

class Civilian : public Airplane {
public:
	Civilian() { cout << "Civilian was created\n"; }

	Civilian(int boardNumber, string stata, Date date, int maxLaps);

	~Civilian() { cout << "Civilian was deleted\n"; }
private:

};

#endif CIVILIAN_H