//#pragma once
#ifndef CARGO_H
#define CARGO_H

#include "Airplane.h"

class Airstrip;

class Cargo : public Airplane {
public:

	void work(Level *level, Dispatcher *dispatcher, Airstrip *airstrip, int x, int y) override;

	Cargo() { cout << "Cargo was created\n"; }

	~Cargo() { cout << "Cargo was deleted\n"; }
private:
};

#endif CARGO_H