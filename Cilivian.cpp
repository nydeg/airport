#include "Cilivian.h"
#include "Airstrip.h"


Civilian::Civilian(int boardNumber, string stata, Date date, int maxLaps)
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

	cout << "Civilian was created with parameters\n";
}


void Civilian::work(Level *level, Dispatcher *dispatcher, Airstrip *airstrip, int x, int y) {
	if (this->getStatus() == "moving_to_request") {
		this->MovingToRequest(x, y);
	}
	else if (this->getStatus() == "moving_new_lap") {
		this->MovingNewLap(x, y);
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