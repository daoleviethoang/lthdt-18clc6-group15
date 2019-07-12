#ifndef _PHARMACY_H_
#define _PHARMACY_H_

#include "iostream"
#include "vector"
#include "Employee.h"
#include "fstream"
using namespace std;

class Pharmacy
{
private:
	string m_Name;
	vector<Employee*>m_Emp;
public:
	bool loadEmployee(const char *path, string b)
	{
		ifstream fin;
		fin.open(path);
		if (fin.fail())
			return false;

		int No, dd, mm, yyyy;
		string lname, name, gender, phoneNo, id, position;
		double salary, bonus;

		getline(fin, b, '\n');
		while (fin >> No)
		{
			fin.get();
			getline(fin, lname, ',');
			getline(fin, name, ',');
			getline(fin, phoneNo, ',');
			getline(fin, id, ',');
			fin >> dd;
			getline(fin, b, '/');
			fin >> mm;
			getline(fin, b, '/');
			fin >> yyyy;
			getline(fin, b, ',');
			getline(fin, gender, ',');
			getline(fin, position, ',');
			fin >> salary;
			getline(fin, b, ',');
			fin >> bonus;
			Date d;
			d.input(dd, mm, yyyy);
			Employee*e = new Employee(No, lname, name, phoneNo, id, d, gender, position, salary, bonus);
			m_Emp.push_back(e);
		}
		fin.close();
		return true;
	}
};

#endif 