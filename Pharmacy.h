#ifndef _PHARMACY_H_
#define _PHARMACY_H_

#include "iostream"
#include "vector"
#include "Employee.h"
#include "fstream"
#include "iomanip"
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
	
	int getNumEm()
	{
		return m_Emp.size();
	}
	
	void addEmployee(Employee*e)
	{
		m_Emp.push_back(e);
	}

	void viewEmployee()
	{
		for (int i = 0; i < m_Emp.size(); i++)
		{
			cout << setfill(' ');
			cout << setw(3) << left << m_Emp[i]->getNo() << "|";
			cout << setw(24) << left << m_Emp[i]->getLName();
			cout << setw(9) << left << m_Emp[i]->getName() << "|";
			cout << setw(9) << left << m_Emp[i]->getPhone() << "|";
			cout << setw(9) << left << m_Emp[i]->getID() << "|";
			cout << setfill('0');
			cout << setw(2) << right << m_Emp[i]->getDOB() << "|";
			cout << setfill(' ');
			cout << setw(9) << left << m_Emp[i]->getGender() << "|";
			cout << setw(14) << left << m_Emp[i]->getPosition() << "|";
			cout.precision(20);
			cout << setw(9) << left << m_Emp[i]->getSalary() << "|";
			cout << setw(9) << left << m_Emp[i]->getBonus() << endl;
		}
	}

	void deleteEmployee(int n)
	{
		m_Emp.erase(m_Emp.begin() + n-1);
		for (int i = n-1; i < m_Emp.size(); i++)
		{
			m_Emp[i]->decrease1No();
		}
	}

	Employee*getEmployee(int n)
	{
		return m_Emp[n - 1];
	}

	void editEmployee(int n, Employee*e)
	{
		m_Emp[n - 1] = e;
	}

	void viewSingleEmployee(int n)
	{
		cout << setfill(' ');
		cout << setw(3) << left << m_Emp[n-1]->getNo() << "|";
		cout << setw(24) << left << m_Emp[n-1]->getLName();
		cout << setw(9) << left << m_Emp[n-1]->getName() << "|";
		cout << setw(9) << left << m_Emp[n-1]->getPhone() << "|";
		cout << setw(9) << left << m_Emp[n-1]->getID() << "|";
		cout << setfill('0');
		cout << setw(2) << right << m_Emp[n-1]->getDOB() << "|";
		cout << setfill(' ');
		cout << setw(9) << left << m_Emp[n-1]->getGender() << "|";
		cout << setw(14) << left << m_Emp[n-1]->getPosition() << "|";
		cout.precision(20);
		cout << setw(9) << left << m_Emp[n-1]->getSalary() << "|";
		cout << setw(9) << left << m_Emp[n-1]->getBonus() << endl;
	}

};

#endif 