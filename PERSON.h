#pragma once
#include "DATE.h"
class PERSON:public Date
{
private:
	string m_Name;
	string m_PhoneNo;
	string m_ID;
public:
	PERSON()
	{
		m_Name = "";
		m_PhoneNo = "";
		m_ID = "";
	}
	PERSON(string name, string phoneno, string id)
	{
		m_Name = name;
		m_PhoneNo = phoneno;
		m_ID = id;
	}
	void input(string name, string phoneno, string id, string day, string month, string year)
	{
		PERSON(name, phoneno, id);
		Date::Date(day, month, year);
	}
	string getName()
	{
		return m_Name;
	}
	string getPhoneNo()
	{

		return m_PhoneNo;
	}
	string getID()
	{
		return m_ID;
	}
};