#ifndef _PERSON_H_
#define _PERSON_H_

#include "iostream"
#include "string"
#include "Date.h"
using namespace std;

class Person
{
protected:
	string m_LastName;
	string m_FirstName;
	string m_PhoneNo;
	string m_ID;
	Date m_DOB;
	string m_Gender;
public:
	Person()
	{
		m_LastName = "";
		m_FirstName = "";
		m_PhoneNo = "";
		m_ID = "";
		m_Gender = "";
	}
	Person(string lname, string name, string phone, string id, Date d, string gender)
	{
		m_LastName = lname;
		m_FirstName = name;
		m_PhoneNo = phone;
		m_ID = id;
		m_DOB = d;
		m_Gender = gender;
	}
	Person(const Person&p)
	{
		this->m_LastName = p.m_LastName;
		this->m_FirstName = p.m_FirstName;
		this->m_PhoneNo = p.m_PhoneNo;
		this->m_ID = p.m_ID;
		this->m_DOB = p.m_DOB;
		this->m_Gender = p.m_Gender;
	}
	string getLName()
	{
		return m_LastName;
	}
	string getName()
	{
		return m_FirstName;
	}
	string getPhone()
	{
		return m_PhoneNo;
	}
	string getID()
	{
		return m_ID;
	}
	Date getDOB()
	{
		return m_DOB;
	}
	string getGender()
	{
		return m_Gender;
	}
};

#endif 