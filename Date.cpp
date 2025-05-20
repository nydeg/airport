#include "Date.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <time.h>


using std::cout;
using std::cin;

Date::Date()
{
	time_t mytime = time(NULL);
	struct tm* now = localtime(&mytime);
	day = now->tm_mday;
	month = now->tm_mon + 1;
	year = now->tm_year + 1900;
	hour = now->tm_hour;
	minute = now->tm_min;
}


bool Date::relevantDate(int d, int m, int y, int h, int min) {

	//time
	if (h < 0 || min < 0) {
		return false;
	}
	if (h > 23 || min > 59) {
		return false;
	}
	
	//month, year, day
	if (d <= 0 || m <= 0 || y <= 0) {
		return false;
	}

	if (d > 31)
		return false;

	if (m == 2) {
		if (((y % 4 == 0) && (y % 100 != 0) || (y % 400 == 0))) {
			if (d > 29)
				return false;
			return true;
		}
		if (d > 28)
			return false;
		return true;
	}

	if (m == 4 || m == 6 || m == 9 || m == 11) {
		if (d > 30)
			return false;
		return true;
	}

	return true;
}

Date Date::operator+(int right) const
{
	Date res(*this);
	res.minute += right;
	while (res.relevantDate(res.day, res.month, res.year, res.hour, res.minute) == false) {
		if (res.minute > 59) {
			res.hour += res.minute / 60; // ceil
			res.minute = res.minute % 60; // ost
		}

		if (res.hour > 23) {
			res.day += res.hour / 24;
			res.hour = res.hour % 24;
		}


		//day, month, year
		if (res.month == 2) {
			if (((res.year % 4 == 0) && (res.year % 100 != 0) || (res.year % 400 == 0))) {
				if (res.day > 29)
				{
					res.month++;
					res.day = res.day - 29;
				}
				continue;
			}
			if (res.day > 28)
			{
				res.month++;
				res.day = res.day - 28;
			}
			continue;
		}

		if (res.month == 4 || res.month == 6 || res.month == 9 || res.month == 11) {
			if (res.day > 30)
			{
				res.month++;
				res.day = res.day - 30;
			}
			continue;
		}
		if (res.day > 31) {
			if (res.month == 12) {
				res.year++;
				res.month = 1;
				res.day = res.day - 31;
				continue;
			}
			res.month++;
			res.day = res.day - 31;
		}
	}

	return res;
}

/*
Date Date::operator-(int right) const
{
	Date res(*this);
	res.minute -= right;
	while (res.relevantDate(res.day, res.month, res.year, res.hour, res.minute) == false) {
		if (res.month == 3) {
			if (((res.year % 4 == 0) && (res.year % 100 != 0) || (res.year % 400 == 0))) {
				res.month--;
				res.day = 29 + res.day;
				continue;
			}
			res.month--;
			res.day = 28 + res.day;
			continue;
		}

		if (res.month == 5 || res.month == 7 || res.month == 10 || res.month == 12) {
			res.month--;
			res.day = 30 + res.day;
			continue;
		}
		if (res.month == 1) {
			res.year--;
			res.month = 12;
			res.day = 31 + res.day;
			continue;
		}
		res.month--;
		res.day = 31 + res.day;
	}

	return res;
}
*/

int Date::operator-(const Date& right) const
{
	if (*this < right) {
		cout << "Error of difference\n";
		return -1;
	}

	Date temp(right);

	int counter = 0;
	while (*this != temp) {
		++temp;
		counter++;
		
	}
	return counter;
}

Date& Date::operator++()
{
	*this = *this + 1;
	return *this;
}

Date& Date::operator++(int)
{
	++*this;
	return *this;
}

/*
Date& Date::operator--()
{
	*this = *this - 1;
	return *this;
}

Date& Date::operator--(int)
{
	--*this;
	return *this;
}
*/

bool Date::operator==(const Date& right) const
{
	if (this->day == right.day && this->month == right.month && this->year == right.year && this->hour == right.hour && this->minute == right.minute)
		return true;
	return false;
}

bool Date::operator!=(const Date& right) const
{
	if (*this == right)
		return false;
	return true;
}

bool Date::operator>(const Date& right) const
{
	if (this->year < right.year) {
		return false;
	}
	else if (this->year > right.year) {
		return true;
	}
	else {
		if (this->month < right.month) {
			return false;
		}
		else if (this->month > right.month) {
			return true;
		}
		else {
			if (this->day < right.day) {
				return false;
			}
			else if (this->day > right.day) {
				return true;
			}
			else {
				if (this->hour < right.hour) {
					return false;
				}
				else if (this->hour > right.hour) {
					return true;
				}
				else {
					if (this->minute < right.minute) {
						return false;
					}
					else if (this->minute > right.minute) {
						return true;
					}
					else
						return false; // ���� �����
				}
			}
		}
	}

}

bool Date::operator<(const Date& right) const
{
	if (*this != right && !(*this > right))
		return true;
	return false;
}



Date::Date(int d, int m, int y, int h, int min) :Date()
{

	if (relevantDate(d, m, y, h, min)) {
		this->day = d;
		this->month = m;
		this->year = y;
		this->hour = h;
		this->minute = min;
		return;
	}
	return;
}


int transform(char x) {
	return (int)x - 48;
}


Date::Date(string sdate) :Date()
{
	
	if (sdate.length() != 16) {
		cout << "Date is false\n";
		return;
	}
	if (sdate[2] != '.' || sdate[5] != '.' || sdate[10] != ' ' || sdate[13] != ':') {
		cout << "Date is false\n";
		return;
	}
	for (int i = 0; i < 10; i++) {
		if (i != 2 && i != 5)
			if (!(48 <= (int)sdate[i] && (int)sdate[i] <= 57))
				return;
	}
	int d = 10 * transform(sdate[0]) + transform(sdate[1]);
	int m = 10 * transform(sdate[3]) + transform(sdate[4]);
	int y = 1000 * transform(sdate[6]) + 100 * transform(sdate[7]) + 10 * transform(sdate[8]) + transform(sdate[9]);
	int h = 10 * transform(sdate[11]) + transform(sdate[12]);
	int min = 10 * transform(sdate[14]) + transform(sdate[15]);

	if (relevantDate(d, m, y, h, min)) {
		this->day = d;
		this->month = m;
		this->year = y;
		this->hour = h;
		this->minute = min;
		return;
	}
	return;

	return;

}

void Date::printDate() const
{
	cout << "day: " << day << " month: " << month << " year: " << year << " hour: " << hour << " minute: " << minute <<"\n";
}

void Date::changeDay(int d)
{
	day = (relevantDate(d, month, year, hour, minute)) ? d : day;
}

void Date::changeMonth(int m)
{
	month = (relevantDate(day, m, year, hour, minute)) ? m : month;
}

void Date::changeYear(int y)
{
	year = (relevantDate(day, month, y, hour, minute)) ? y : year;
}

void Date::changeHour(int h)
{
	hour = (relevantDate(day, month, year, h, minute)) ? h : hour;
}

void Date::changeMinute(int min)
{
	minute = (relevantDate(day, month, year, hour, min)) ? min : minute;
}
/*
std::ostream& operator<<(std::ostream& out, const Date& right)
{
	right.printDate();
	return out;
}

std::istream& operator>>(std::istream& in, Date& right)
{
	int d, m, y;
	in >> d >> m >> y;
	right.changeDay(d);
	right.changeMonth(m);
	right.changeYear(y);
	return in;
}
*/