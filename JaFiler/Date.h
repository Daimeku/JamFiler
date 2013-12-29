#pragma once
#include <iostream>
#include <fstream>

using namespace std;
class Date
{
private:
	int day;
	int month;
	int year;

public:
	Date(void);
	~Date(void);
	Date(int, int, int);
	void setDay(int d);
	int getDay();
	void setMonth(int m);
	int getMonth();
	void setYear(int y);
	int getYear();
	void display();
	void toFile();
	void getDate();

};

