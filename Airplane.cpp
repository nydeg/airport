#include "Airplane.h"

Airplane::Airplane()
{
	deviation = 0;
	status = "";
	maxLaps = 0;
	boardNumber = 0;
	lengthOfAirstrip = 0;
	oneLipInMinute = 0;
	Date currDate;
	timeOfAction = currDate;

	cout << "airplane was created\n";

}
