#include<iostream>
#include<windows.h>
#include<ctime>
using namespace std;

#pragma once

class Time
{
	int hours;
	int minutes;
	int seconds;

public:
	Time();
	Time(int h, int m, int s);

	void Print();

	void SetSeconds(int sec);
	void SetMinutes(int min);
	void SetHours(int hour);
	int GetSeconds() const;
	int GetMinutes() const;
	int GetHours() const;

	friend Time operator + (const Time& time, int sec);
	friend istream& operator >> (istream& is, Time& original);
	friend ostream& operator << (ostream& os, const Time& original);
};


bool operator > (const Time& One, const Time& Two);
bool operator < (const Time& One, const Time& Two);
bool operator == (const Time& One, const Time& Two);
bool operator != (const Time& One, const Time& Two);

istream& operator >> (istream& is, Time& original);
ostream& operator << (ostream& os, const Time& original);