#ifndef _EMPLOYEE_H_
#define _EMPLOYEE_H_

#include "Person.h"

class Employee : public Person
{
private:
	int m_No;
	string m_Position;
	double m_Salary;
	double m_Bonus;
public:
	Employee() :Person()
	{
		m_No = 0;
		m_Position = "";
		m_Salary = 0;
		m_Bonus = 0;
	}
	Employee(int no,string lname, string name, string phone, string id, Date d, string gender, string pos, double salary, double bonus) :Person(lname, name, phone, id, d, gender)
	{
		m_No = no;
		m_Position = pos;
		m_Salary = salary;
		m_Bonus = bonus;
	}
	Employee(const Employee&e) :Person(e)
	{
		this->m_No = e.m_No;
		this->m_Position = e.m_Position;
		this->m_Salary = e.m_Salary;
		this->m_Bonus = e.m_Bonus;
	}
	int getNo()
	{
		return m_No;
	}
	string getPosition()
	{
		return m_Position;
	}
	double getSalary()
	{
		return m_Salary;
	}
	double getBonus()
	{
		return m_Bonus;
	}
	void decrease1No()
	{
		m_No--;
	}
};

#endif 