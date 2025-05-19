//#pragma once
#ifndef MILITARY_H
#define MILITARY_H

#include "Airplane.h"

#define TIME_FOR_ONE_LIP 30
#define LENGTH_OF_REQUIRED_AIRSTRIP 50

class Level;
class Dispatcher;
class Airstrip;

class Military : public Airplane{
public:

	void work(Level *level, Dispatcher *dispatcher, Airstrip *airstrip, int x, int y) override;

	Military() { cout << "Military was created\n"; }

	Military(int boardNumber, string stata, Date date, int maxLaps);

	~Military() { cout << "Military was deleted\n"; }
private:

};

#endif MILITARY_H