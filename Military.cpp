#include "Military.h"



Military::Military(int boardNumber, string stata, Date date, int maxLaps)
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
	
	cout << "Military was created with parameters\n";
}
