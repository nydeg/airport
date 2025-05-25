//#pragma once
#ifndef CARGO_H
#define CARGO_H

#include "Airplane.h"

#define TIME_FOR_ONE_LIP 40
#define LENGTH_OF_REQUIRED_AIRSTRIP 40

class Cargo : public Airplane {
public:
	Cargo() { cout << "Cargo was created\n"; }

	Cargo(int boardNumber, string stata, Date date, int maxLaps, Level* level);

	~Cargo() { cout << "Cargo was deleted\n"; }

	void work(Level *level, Dispatcher *dispatcher, Airstrip *airstrip, int x, int y) override;

private:
};

#endif CARGO_H