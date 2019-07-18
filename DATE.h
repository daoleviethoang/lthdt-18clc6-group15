#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
#include <cstdlib>
#include <io.h>
#include <time.h>
#include <vector>
using namespace std;
class Date
{
private:
	string m_Day;
	string m_Month;
	string m_Year;
public:
	Date()
	{
		m_Day = "";
		m_Month = "";
		m_Year = "";
	}
	Date(string day, string month, string year)
	{
		m_Day = day;
		m_Month = month;
		m_Year = year;
	}
	string getDay()
	{
		return m_Day;
	}
	string getMonth()
	{
		return m_Month;
	}
	string getYear()
	{
		return m_Year;
	}
	bool checkdate()
	{
		int maxday = 0;
		if (atoi(m_Year.c_str()) < 0 || atoi(m_Month.c_str()) < 0 || atoi(m_Month.c_str()) > 12 || atoi(m_Day.c_str()) < 0 || atoi(m_Day.c_str()) > 31)
		{
			return false;
		}
		else
		{
			switch (atoi(m_Month.c_str()))
			{
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
				maxday = 31;
				break;
			case 2:
				if ((atoi(m_Year.c_str()) % 4 == 0 && atoi(m_Year.c_str()) % 100 != 0) || (atoi(m_Year.c_str()) % 400 == 0))
					maxday = 29;
				else
					maxday = 28;
				break;
			case 4:
			case 6:
			case 9:
			case 11:
				maxday = 30;
				break;
			}
			if (atoi(m_Day.c_str()) <= maxday)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
	int calDate(int year, int month, int day) {
		if (month < 3) {
			year--;
			month += 12;
		}
		return 365 * year + year / 4 - year / 100 + year / 400 + (153 * month - 457) / 5 + day - 306;
	}
	void increase1()
	{
		if (checkdate() == true)
		{
			if (atoi(m_Day.c_str()) == 31 && atoi(m_Month.c_str()) == 12)
			{
				m_Day = "1";
				m_Month = "1";
				char buffer[33];
				int a = atoi(m_Year.c_str());
				a++;
				_itoa(a, buffer, 10);
				m_Year = buffer;
			}
			else if (atoi(m_Day.c_str()) == 31 && (atoi(m_Month.c_str()) == 1 || atoi(m_Month.c_str()) == 3 || atoi(m_Month.c_str()) == 5 || atoi(m_Month.c_str()) == 7 || atoi(m_Month.c_str()) == 8 || atoi(m_Month.c_str()) == 10))
			{
				char buffer[33];
				m_Day = "1";
				int a = atoi(m_Month.c_str());
				a++;
				_itoa(a, buffer, 10);
				m_Month = buffer;
			}
			else if (atoi(m_Day.c_str()) == 30 && (atoi(m_Month.c_str()) == 4 || atoi(m_Month.c_str()) == 6 || atoi(m_Month.c_str()) == 9 || atoi(m_Month.c_str()) == 11))
			{
				char buffer[33];
				m_Day = "1";
				int a = atoi(m_Month.c_str());
				a++;
				_itoa(a, buffer, 10);
				m_Month = buffer;
			}
			else if ((atoi(m_Day.c_str()) == 28 || atoi(m_Day.c_str()) == 29) && atoi(m_Month.c_str()) == 2)
			{
				m_Day = "1";
				m_Month = "3";
			}
			else
			{
				char buffer[33];
				int a = atoi(m_Day.c_str());
				a++;
				_itoa(a, buffer, 10);
				m_Day = buffer;
			}
		}
	}
	DATE increaseDate()
	{
		int n;
		do
		{
			cout << "Enter the number of days you want to increase: ";
			cin >> n;
		} while (n < 0);
		for (int i = 1; i <= n; i++)
		{
			increase1();
		}
	}
	void decrease1()
	{
		if (checkdate() == true)
		{
			if (atoi(m_Day.c_str()) == 1 && atoi(m_Month.c_str()) == 1)
			{
				m_Day = "31";
				m_Month = "12";
				char buffer[33];
				int a = atoi(m_Year.c_str());
				a--;
				_itoa(a, buffer, 10);
				m_Year = buffer;
			}
			else if (atoi(m_Day.c_str()) == 1 && (atoi(m_Month.c_str()) == 2 || atoi(m_Month.c_str()) == 4 || atoi(m_Month.c_str()) == 6 || atoi(m_Month.c_str()) == 8 || atoi(m_Month.c_str()) == 9 || atoi(m_Month.c_str()) == 11))
			{
				m_Day = "31";
				char buffer[33];
				int a = atoi(m_Month.c_str());
				a--;
				_itoa(a, buffer, 10);
				m_Month = buffer;
			}
			else if (atoi(m_Day.c_str()) == 1 && (atoi(m_Month.c_str()) == 5 || atoi(m_Month.c_str()) == 7 || atoi(m_Month.c_str()) == 10 || atoi(m_Month.c_str()) == 12))
			{
				m_Day = "30";
				char buffer[33];
				int a = atoi(m_Month.c_str());
				a--;
				_itoa(a, buffer, 10);
				m_Month = buffer;
			}
			else if (atoi(m_Day.c_str()) == 1 && atoi(m_Month.c_str()) == 3)
			{
				if ((atoi(m_Year.c_str()) % 4 == 0 && atoi(m_Year.c_str()) % 100 != 0) || (atoi(m_Year.c_str()) % 400 == 0))
					m_Day == "29";
				else
					m_Day = "28";
				m_Month = "2";
			}
			else
			{
				char buffer[33];
				int a = atoi(m_Day.c_str());
				a--;
				_itoa(a, buffer, 10);
				m_Day = buffer;
			}
		}
	}
	DATE decreaseDate()
	{
		int n;
		do
		{
			cout << "Enter the number of days you want to decrease: ";
			cin >> n;
		} while (n < 0);
		for (int i = 1; i <= n; i++)
		{
			decrease1();
		}
	}
};