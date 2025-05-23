//#pragma once
#ifndef CARGO_H
#define CARGO_H

#include "Airplane.h"

#define TIME_FOR_ONE_LIP 40
#define LENGTH_OF_REQUIRED_AIRSTRIP 40

class Airstrip;

class Cargo : public Airplane {
public:

	void work(Level *level, Dispatcher *dispatcher, Airstrip *airstrip, int x, int y) override;

	Cargo() { cout << "Cargo was created\n"; }

	Cargo(int boardNumber, string stata, Date date, int maxLaps);

	~Cargo() { cout << "Cargo was deleted\n"; }
private:
};

#endif CARGO_H