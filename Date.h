//#pragma once
#ifndef DATE_H
#define DATE_H
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <sstream>
using std::cout;
using std::string;
class Date {

public:
	Date();

	Date(int d, int m, int y, int h, int min);

	Date(string sdate);

	string getStringDate() {
		if(hour < 10 && minute < 10)
			return std::to_string(year) + "." + std::to_string(month) + "." + std::to_string(day) + " 0" + std::to_string(hour) + ":0" + std::to_string(minute);
		if(hour < 10)
			return std::to_string(year) + "." + std::to_string(month) + "." + std::to_string(day) + " 0" + std::to_string(hour) + ":" + std::to_string(minute);
		if(minute < 10)
			return std::to_string(year) + "." + std::to_string(month) + "." + std::to_string(day) + " " + std::to_string(hour) + ":0" + std::to_string(minute);

		return std::to_string(year) + "." + std::to_string(month) + "." + std::to_string(day) + " " + std::to_string(hour) + ":" + std::to_string(minute);


	}


	void printDate() const;

	void changeDay(int d);

	void changeMonth(int m);

	void changeYear(int y);

	void changeHour(int h);

	void changeMinute(int min);

	bool relevantDate(int d, int m, int y, int h, int min);

	//access
	int getDay() { return day; }
	int getMonth() { return month; }
	int getYear() { return year; }
	int getHour() { return hour; }
	int getMinute() { return minute; }

	Date operator+ (int right) const; // add the ceil num of MINUTES
	//Date operator- (int right) const; // 

	int operator- (const Date& right) const;

	Date& operator++();
	Date& operator++(int);

	//Date& operator--();
	//Date& operator--(int);

	bool operator==(const Date& right) const;
	bool operator!=(const Date& right) const;
	bool operator>(const Date& right) const;
	bool operator<(const Date& right) const;
private:

	int day = -1;
	int month = -1;
	int year = -1;
	int hour = -1;
	int minute = -1;

};

//std::ostream& operator<<(std::ostream& out, const Date& right);
//std::istream& operator>>(std::istream& in, Date& right);

#endif DATE_H
