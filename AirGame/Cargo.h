//#pragma once
#ifndef CARGO_H
#define CARGO_H

#include "Airplane.h"

class Cargo : public Airplane {
public:
	Cargo() { cout << "Cargo was created\n"; }

	~Cargo() { cout << "Cargo was deleted\n"; }
private:
};

#endif CARGO_H