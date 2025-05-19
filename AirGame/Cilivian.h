//#pragma once
#ifndef CIVILIAN_H
#define CIVILIAN_H

#include "Airplane.h"

class Civilian : public Airplane {
public:

	void work(Level *level, Dispatcher *dispatcher, Airstrip *airstrip, int x, int y) override;

	Civilian() { cout << "Civilian was created\n"; }

	~Civilian() { cout << "Civilian was deleted\n"; }
private:

};

#endif CIVILIAN_H