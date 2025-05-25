//#pragma once
#ifndef AIRPLANE_H
#define AIRPLANE_H

#include "iostream"
#include "Date.h"
#include "Level.h"
#include <vector>
#include "Lap.h"
#include "SFML/Graphics.hpp"

using std::cout;
using std::string;
using namespace std;

class Level;
class Dispatcher;
class Airstrip;

class Airplane {
public:

	Airplane();

	~Airplane(){cout << "airplane was deleted\n";}

	virtual void work(Level *level, Dispatcher *dispatcher, Airstrip *airstrip, int x, int y) = 0;

	void TakeOff(Level* level);

	// functions for work
	void Moving(int x, int y, string new_status);
	int MovingNewLap(int x, int y,  int& status, Airstrip* airstrip);
	void BoardingStartPoint(int startX, int startY);
	void BoardingEndPoint(Level *level, Dispatcher *dispatcher, int endX, int endY);
	void TakeOffStartPoint(int startX, int startY);
	void TakeOffEndPoint(Level* level, Dispatcher* dispatcher, int endX, int endY);

	int MoveInLap(Level *level, int& status, Airstrip* airstrip);
	int DeleteAirplane(Level *level);
	void MoveToAirstrip(Level *level, int airstripNumber);
	void MoveToTakeoff(Level *level, int airstripNumber);
	void MoveFromHangarToAirstrip(Level *level, int airstripNumber);
	void MoveFromAirstripToHangar(Level *level, int airstripNumber);
	LapCoordinate findNearestPoint(int x0, int y0, vector<LapCoordinate>& points);


	void updatePos();

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
	int getX() { return this->x; }
	int getY() { return this->y; }
	int getCornenrInd() { return ind; }
	int getIndex() { return ind;}
	string getType() { return type; }

	sf::RectangleShape getTestShape(){return test;}


	//setters
	void setTimeOfAction(Date date) { timeOfAction = date; }
	void setBoardNumber(int bNum) { boardNumber = bNum; }
	void setStatus(string stata) { status = stata; }
	//void setTakeOffTime(Date date) { takeOffTime = date; }
	//void setBoardingTime(Date date) { boardingTime = date; }
	void setMaxLaps(int num) { maxLaps = num; }
	void setLengthOfAirstrip(int len) { lengthOfAirstrip = len; }
	void setOneLipInMinute(int value) { oneLipInMinute = value; }
	void setType(string type) { this->type = type; }
	void setX(int x) { this->x = x; }
	void setY(int y) { this->y = y; }
	void setBoardIndex(int index) { this->boardIndex = index; }
	void setIndex(int tmp){ind = tmp;}


private:
	int deviation; // in minutes

	int x;
	int y;

	string type;

	string status;
	Date timeOfAction;
	int maxLaps;

	int ind = 0; // pos in lap [0, 3]

	//Date takeOffTime;
	//Date boardingTime;

	int boardNumber;
	//Date timeToUp;
	//Date timeToDown;


	int lengthOfAirstrip;
	int oneLipInMinute;


	sf::RectangleShape test;

protected:
	int boardIndex;

};

#endif AIRPLAHE_H