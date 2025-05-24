#include "Cargo.h"
#include "Level.h"
#include "Dispatcher.h"
#include "Airstrip.h"

Cargo::Cargo(int boardNumber, string stata, Date date, int maxLaps)
{
	//unique data
	setBoardNumber(boardNumber);
	if (stata == "V") {
		setStatus("awaiting_takeoff");
	}
	else {
		setStatus("awaiting_boarding");
	}
	setTimeOfAction(date);


	setMaxLaps(maxLaps);

	//for every military
	setLengthOfAirstrip(LENGTH_OF_REQUIRED_AIRSTRIP);
	setOneLipInMinute(TIME_FOR_ONE_LIP);

	cout << "Cargo was created with parameters\n";
}


void Cargo::work(Level *level, Dispatcher *dispatcher, Airstrip *airstrip, int x, int y) {
	if (this->getStatus() == "awaiting_boarding") {
		this->MoveInLap(level);
	}
	else if (this->getStatus() == "boarding_startPoint") {
		this->BoardingStartPoint(airstrip->getStart().first, airstrip->getStart().second);
	}
	else if (this->getStatus() == "boarding_endPoint") {
		this->BoardingEndPoint(level, dispatcher, airstrip->getEnd().first, airstrip->getEnd().second);
	}
	else if (this->getStatus() == "take_off") {
		this->TakeOff(level);
	}
}