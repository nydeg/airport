//#pragma once
#ifndef AIRPLANE_H
#define AIRPLANE_H

#include "iostream"
#include "Date.h"

using std::cout;
using std::string;

class Airplane {
public:

	Airplane() { cout << "airplane was created\n"; }

	~Airplane(){cout << "airplane was deleted\n";}

	//access
	Date getTimeOfAction() { return timeOfAction; }
	int getBoardNumber() { return boardNumber; }
	string getStatus() { return status; }
	//Date getTakeOffTime() { return takeOffTime; }
	//Date getBoardingTime() { return boardingTime; }
	int getDeviation() { return deviation; }
	//Date getTimeToUp() { return timeToUp; }
	//Date getTimeToDown() { return timeToDown; }
	int getMaxLaps() { return maxLaps; }
	int getlengthOfAirstrip() { return lengthOfAirstrip; }
	int getOneLipInMinute() { return oneLipInMinute; }

	//setters
	void setTimeOfAction(Date date) { timeOfAction = date; }
	void setBoardNumber(int bNum) { boardNumber = bNum; }
	void setStatus(string stata) { status = stata; }
	//void setTakeOffTime(Date date) { takeOffTime = date; }
	//void setBoardingTime(Date date) { boardingTime = date; }
	void setMaxLaps(int num) { maxLaps = num; }
	void setLengthOfAirstrip(int len) { lengthOfAirstrip = len; }
	void setOneLipInMinute(int value) { oneLipInMinute = value; }

private:
	int deviation; // in minutes

	string status;
	Date timeOfAction;
	int maxLaps;

	//Date takeOffTime;
	//Date boardingTime;
	

	int boardNumber;
	//Date timeToUp;
	//Date timeToDown;


	int lengthOfAirstrip;
	int oneLipInMinute;

};

#endif AIRPLAHE_H