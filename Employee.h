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
};

#endif 