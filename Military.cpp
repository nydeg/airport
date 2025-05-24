#include "Military.h"
#include <string>

#include "Airstrip.h"


Military::Military(int boardNumber, string stata, Date date, int maxLaps)
{
	//unique data
	setBoardNumber(boardNumber);
	if (stata == "V") {
		setStatus("awaiting_takeoff");
		if(boardNumber/100 != 1) {
			setX(1200);
			setY(350);
		}
		else {
			setX(1300);
			setY(260);
		}

	}
	else {
		setStatus("awaiting_boarding");
	}
	setTimeOfAction(date);


	setMaxLaps(maxLaps);

	//for every military
	setLengthOfAirstrip(LENGTH_OF_REQUIRED_AIRSTRIP);
	setOneLipInMinute(TIME_FOR_ONE_LIP);
	
	cout << "Military was created with parameters\n";
}


void Military::work(Level *level, Dispatcher *dispatcher, Airstrip *airstrip, int x, int y) {
	int poo = 2;
	if (this->getStatus() == "awaiting_boarding") {
		this->MoveInLap(level, poo, airstrip);
	}
	else if (this->getStatus() == "boarding_startPoint") {
		int status = 0;
		if(MoveInLap(level, status, airstrip)) {
			cout << "BOARDING!!!\n";
			BoardingStartPoint(airstrip->getStart().first, airstrip->getStart().second);
		}
		//this->MoveInLap(level, 1, airstrip);
	}
	else if (this->getStatus() == "boarding_endPoint") {
		this->BoardingEndPoint(level, dispatcher, airstrip->getEnd().first, airstrip->getEnd().second);
	}
	else if (this->getStatus() == "take_off") {
		this->TakeOffEndPoint(level, dispatcher, 0, airstrip->getEnd().second);
	}

}