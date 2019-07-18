#ifndef _DATE_H_
#define _DATE_H_

#include "iostream"
#include "string"
#include "iomanip"
using namespace std;

class Date 
{
private:
	int dd, mm, yyyy;
public:
	Date();
	Date(int day, int month, int year);
	void input(unsigned int day, unsigned int month, unsigned int year);
	void output();
	Date increase1();
	Date decrease1();
	Date increase(int n);
	Date decrease(int n);
	int compare(Date a);
	long distance();
	long distanceGY();
	bool checkDate();
	friend ostream& operator <<(ostream&os, const Date&p)
	{
		os << p.dd << "/" << setw(2) << right << p.mm << "/" << setw(4) << left << p.yyyy;
		return os;
	}
};

#endif