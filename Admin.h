#ifndef _ADMIN_H_
#define _ADMIN_H_

#include "Employee.h"
#include "Pharmacy.h"
#include "iomanip"
class Admin : public Employee
{
private:
public:
	void addEmployee(Pharmacy*p)
	{
		int dd, mm, yyyy;
		string lname, name, gender, phoneNo, id, position;
		double salary, bonus;
		Date dob;

		cout << "Input NEW EMPLOYEE!!" << endl;
		cout << "Input Last name: ";
		getline(cin, lname);
		cout << "Input First name: ";
		cin >> name;
		cout << "Input the PhoneNo: ";
		cin >> phoneNo;
		cout << "Input the ID: ";
		cin >> id;
		do
		{
			cout << "Input Birth Day Information!!" << endl << "Input day: ";
			cin >> dd;
			cout << "Input month: ";
			cin >> mm;
			cout << "Input year: ";
			cin >> yyyy;
			dob.input(dd, mm, yyyy);
		} while (!dob.checkDate() && cout << "Wrong Information!! Please try again!!" << endl);
		do
		{
			cout << "Input the gender(Male/Female): ";
			cin >> gender;
		} while ((gender != "Male" && gender != "Female") && cout << "You have to input Male/Female! Please try again!!" << endl);
		cout << "Input position: ";
		cin.get();
		getline(cin, position);
		do
		{
			cout << "Input salary: ";
			cin >> salary;
		} while (salary <= 0 && cout << "Salary must be positive!!" << endl);
		do
		{
			cout << "Input bonus: ";
			cin >> bonus;
		} while (bonus <= 0 && cout << "Bonus must be positive!!" << endl);
		Employee*e = new Employee(p->getNumEm() + 1, lname, name, phoneNo, id, dob, gender, position, salary, bonus);
		p->addEmployee(e);
	}
	void viewEmployee(Pharmacy*p)
	{
		cout << "!!LIST OF EMPLOYEES!!" << endl;
		cout << setw(3) << left << "No" ;
		cout << setw(25) << left << "Last Name";
		cout << setw(10) << left << "Name";
		cout << setw(10) << left << "Phone";
		cout << setw(10) << left << "ID";
		cout << setw(11) << left << "DOB";
		cout << setw(10) << left << "Gender";
		cout << setw(15) << left << "Position";
		cout << setw(10) << left << "Salary";
		cout << setw(10) << left << "Bonus" << endl;
		cout << setfill('-');	
		cout << setw(115) << "-" << endl;
		p->viewEmployee();
	}
	void deleteEmployee(Pharmacy*p)
	{
		cout << "DELETE EMPLOYEE" << endl;
		this->viewEmployee(p);
		int no;
		do
		{
			cout << "Choose a employee to delete(1-" << p->getNumEm() << "): ";
			cin >> no;
		} while ((no <= 0 || no > p->getNumEm()) && cout << "The pharmacy only have " << p->getNumEm() << " please try again!!" << endl);
		p->deleteEmployee(no);
		cout << "You have delete the employee at no: " << no << "successfully!!" << endl;
	}
	void editEmployee(Pharmacy*p)
	{
		cout << "EDIT EMPLOYEE" << endl;
		this->viewEmployee(p);
		int no;
		int choice;
		do
		{
			cout << "Choose an employee you want to edit: ";
			cin >> no;
		} while ((no <= 0 || no >= p->getNumEm()) && cout << "The pharmacy only have " << p->getNumEm() << " please try again!!" << endl);
		Employee*e = p->getEmployee(no);
		do
		{
			system("cls");
			cout << "Information of the Employee you choose!!" << endl;
			p->viewSingleEmployee(no);
			cout << "Choose 1 category to edit: " << endl;
			cout << "1. Last Name" << endl;
			cout << "2. First Name: " << endl;
			cout << "3. Phone No: " << endl;
			cout << "4. ID: " << endl;
			cout << "5. DOB: " << endl;
			cout << "6. Gender: " << endl;
			cout << "7. Position: " << endl;
			cout << "8. Salary: " << endl;
			cout << "9. Bonus: " << endl;
			cout << "10. Done" << endl;
			cin >> choice;
			switch (choice)
			{
			case 1:
			{
				string a;
				cout << "Input new Last name: ";
				cin.get();
				getline(cin, a);
				Employee*enew = new Employee(e->getNo(), a, e->getName(), e->getPhone(), e->getID(), e->getDOB(), e->getGender(), e->getPosition(), e->getSalary(), e->getBonus());
				p->editEmployee(no, enew);
				cout << "DONE" << endl;
				break;
			}
			case 2:
			{
				string a;
				cout << "Input new First Name: ";
				cin.get();
				getline(cin, a);
				Employee*enew = new Employee(e->getNo(), e->getLName(), a, e->getPhone(), e->getID(), e->getDOB(), e->getGender(), e->getPosition(), e->getSalary(), e->getBonus());
				p->editEmployee(no, enew);
				cout << "DONE" << endl;
				break;
			}
			case 3:
			{
				string a;
				cout << "Input new Phone Number: ";
				cin.get();
				getline(cin, a);
				Employee*enew = new Employee(e->getNo(), e->getLName(), e->getName(), a, e->getID(), e->getDOB(), e->getGender(), e->getPosition(), e->getSalary(), e->getBonus());
				p->editEmployee(no, enew);
				cout << "DONE" << endl;
				break;
			}
			case 4:
			{	
				string a;
				cout << "Input new ID No: ";
				cin.get();
				getline(cin, a);
				Employee*enew = new Employee(e->getNo(), e->getLName(), e->getName(), e->getPhone(), a, e->getDOB(), e->getGender(), e->getPosition(), e->getSalary(), e->getBonus());
				p->editEmployee(no, enew);
				cout << "DONE" << endl;
				break;
			}
			case 5:
			{
				int dd, mm, yyyy;
				Date dob;
				cout << "Input new Birthday information!!" << endl;
				do
				{
					cout << "Input day: ";
					cin >> dd;
					cout << "Input month: ";
					cin >> mm;
					cout << "Input year: ";
					cin >> yyyy;
					dob.input(dd, mm, yyyy);
				} while (!dob.checkDate() && cout << "Wrong Information!! Please try again!!" << endl);
				Employee*enew = new Employee(e->getNo(), e->getLName(), e->getName(), e->getPhone(), e->getID(), dob, e->getGender(), e->getPosition(), e->getSalary(), e->getBonus());
				p->editEmployee(no, enew);
				cout << "DONE" << endl;
				break;
			}
			case 6:
			{
				string a;
				do
				{
					cout << "Input new Gender(Male/Female): ";
					cin >> a;
				} while ((a != "Male" && a != "Female") && cout << "You have to input Male/Female! Please try again!!" << endl);
				Employee*enew = new Employee(e->getNo(), e->getLName(), e->getName(), e->getPhone(), e->getID(), e->getDOB(), a, e->getPosition(), e->getSalary(), e->getBonus());
				p->editEmployee(no, enew);
				cout << "DONE" << endl;
				break;
			}
			case 7:
			{
				string a;
				cout << "Input new Position: ";
				cin.get();
				getline(cin, a);
				Employee*enew = new Employee(e->getNo(), e->getLName(), e->getName(), e->getPhone() , e->getID(), e->getDOB(), e->getGender(), a, e->getSalary(), e->getBonus());
				p->editEmployee(no, enew);
				cout << "DONE" << endl;
				break;
			}
			case 8:
			{
				double sal;
				do
				{
					cout << "Input the new salary: ";
					cin >> sal;
				} while (sal <= 0 && cout << "Salary must be positive!!" << endl);
				Employee*enew = new Employee(e->getNo(), e->getLName(), e->getName(), e->getPhone() , e->getID(), e->getDOB(), e->getGender(), e->getPosition(), sal, e->getBonus());
				p->editEmployee(no, enew);
				cout << "DONE" << endl;
				break;
			}
			case 9:
			{
				double bon;
				do
				{
					cout << "Input the new bonus: ";
					cin >> bon;
				} while (bon <= 0 && cout << "Salary must be positive!!" << endl);
				Employee*enew = new Employee(e->getNo(), e->getLName(), e->getName(), e->getPhone(), e->getID(), e->getDOB(), e->getGender(), e->getPosition(), e->getSalary(), bon);
				p->editEmployee(no, enew);
				cout << "DONE" << endl;
				break;
			}
			case 10:
			{
				break;
			}
			default: cout << "You only can input from 1 to 10" << endl;
			}
		} while (choice != 10);
	}
};

#endif 