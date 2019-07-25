#ifndef _ADMIN_H_
#define _ADMIN_H_

#include "Employee.h"
#include "Pharmacy.h"
#include "iomanip"
#include "DeleteSpace.h"
class Admin : public Employee
{
private:
	vector<vector <string>> schedule;
public:
	Admin(Pharmacy*p)
	{
		schedule.resize(p->getNumEm());
		for (int i = 0; i < p->getNumEm(); i++)
		{
			schedule[i].resize(8);
		}
	}
	void addEmployee(Pharmacy*p)
	{
		int dd, mm, yyyy, day, status, x, y;
		string lname, name, gender, phoneNo, id, position, user, select;
		double salary, bonus;
		Date dob;
		cout << "Input NEW EMPLOYEE!!" << endl;
		cout << "Input Last name: ";
		cin.get();
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
		user = "NV" + DeleteSpace(lname) + name;
		Employee*e = new Employee(p->getNumEm() + 1, lname, name, phoneNo, id, dob, gender, position, salary, bonus, user);
		p->addEmployee(e);

		cout << "Now, we need to schedule the working time for new employee: " << endl;
		vector<string> newSchedule(8, "Present");
		newSchedule[0] = user;
		cout << "The current schedule for the new employee is full Present, now you will choose a day-off" << endl;
		cout << setw(17) << left << "User" << "|"
			<< setw(8) << left << "Mon" << "|"
			<< setw(8) << left << "Tue" << "|"
			<< setw(8) << left << "Wed" << "|"
			<< setw(8) << left << "Thu" << "|"
			<< setw(8) << left << "Fri" << "|"
			<< setw(8) << left << "Sat" << "|"
			<< setw(8) << left << "Sun" << "|" << endl;
		cout << setw(17) << left << newSchedule[0] << "|";
		for (int i=1;i<8;i++)
		{
			cout << setw(8) << left << newSchedule[i] << "|";
		}
		do
		{
			do
			{
				cout << endl << "Choose a day to edit" << endl;
				cout << "Mon: 2, Tue: 3, Wed: 4, Thu: 5, Fri: 6, Sat: 7, Sun: 8" << endl;
				cin >> day;
			} while ((day < 2 || day>8) && cout << "You can only input from 2 to 8!!" << endl);
			do
			{
				cout << "Choose the status you want to be (1: Present/ 2: Off): ";
				cin >> status;
			} while (status != 1 && status != 2 && cout << "You only have 2 choices 1/2" << endl);
			if (status == 1)
			{
				newSchedule[day - 1] = "Present";
			}
			else
			{
				newSchedule[day - 1] = "Off";
			}
			do
			{
				cout << "Do you want to continue(Yes/No): ";
				cin >> select;
				if (select == "Yes")
				{
					y = 0;
					x = 1;
				}
				else if (select == "No")
				{
					y = 0;
					x = 0;
				}
				else
				{
					cout << "Wrong input!! You only can input Yes/No!!" << endl;
					y = 1;
				}
			} while (y != 0);
		} while (x != 0);
		this->schedule.push_back(newSchedule);

		cout << "Add a new employee to the list successfully!!" << endl;
		this->saveSchedule("Workingschedule.csv");
		p->saveEmployee("Employee.csv");
	}
	
	void viewEmployee(Pharmacy*p)
	{
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
		for (int i = 0; i < p->getNumEm(); i++)
		{
			cout << setfill(' ');
			cout << setw(3) << left << p->getEmployee(i+1)->getNo() << "|";
			cout << setw(24) << left << p->getEmployee(i+1)->getLName();
			cout << setw(9) << left << p->getEmployee(i+1)->getName() << "|";
			cout << setw(9) << left << p->getEmployee(i+1)->getPhone() << "|";
			cout << setw(9) << left << p->getEmployee(i+1)->getID() << "|";
			cout << setfill('0');
			cout << setw(2) << right << p->getEmployee(i+1)->getDOB() << "|";
			cout << setfill(' ');
			cout << setw(9) << left << p->getEmployee(i+1)->getGender() << "|";
			cout << setw(14) << left << p->getEmployee(i+1)->getPosition() << "|";
			cout.precision(20);
			cout << setw(9) << left << p->getEmployee(i+1)->getSalary() << "|";
			cout << setw(9) << left << p->getEmployee(i+1)->getBonus() << endl;
		}
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
		p->saveEmployee("Employee.csv");
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
			cout << "10. User Name: " << endl;
			cout << "11. Done" << endl;
			cin >> choice;
			switch (choice)
			{
			case 1:
			{
				string a;
				cout << "Input new Last name: ";
				cin.get();
				getline(cin, a);
				Employee*enew = new Employee(e->getNo(), a, e->getName(), e->getPhone(), e->getID(), e->getDOB(), e->getGender(), e->getPosition(), e->getSalary(), e->getBonus(), e->getUser());
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
				Employee*enew = new Employee(e->getNo(), e->getLName(), a, e->getPhone(), e->getID(), e->getDOB(), e->getGender(), e->getPosition(), e->getSalary(), e->getBonus(), e->getUser());
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
				Employee*enew = new Employee(e->getNo(), e->getLName(), e->getName(), a, e->getID(), e->getDOB(), e->getGender(), e->getPosition(), e->getSalary(), e->getBonus(), e->getUser());
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
				Employee*enew = new Employee(e->getNo(), e->getLName(), e->getName(), e->getPhone(), a, e->getDOB(), e->getGender(), e->getPosition(), e->getSalary(), e->getBonus(), e->getUser());
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
				Employee*enew = new Employee(e->getNo(), e->getLName(), e->getName(), e->getPhone(), e->getID(), dob, e->getGender(), e->getPosition(), e->getSalary(), e->getBonus(), e->getUser());
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
				Employee*enew = new Employee(e->getNo(), e->getLName(), e->getName(), e->getPhone(), e->getID(), e->getDOB(), a, e->getPosition(), e->getSalary(), e->getBonus(), e->getUser());
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
				Employee*enew = new Employee(e->getNo(), e->getLName(), e->getName(), e->getPhone() , e->getID(), e->getDOB(), e->getGender(), a, e->getSalary(), e->getBonus(), e->getUser());
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
				Employee*enew = new Employee(e->getNo(), e->getLName(), e->getName(), e->getPhone() , e->getID(), e->getDOB(), e->getGender(), e->getPosition(), sal, e->getBonus(), e->getUser());
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
				Employee*enew = new Employee(e->getNo(), e->getLName(), e->getName(), e->getPhone(), e->getID(), e->getDOB(), e->getGender(), e->getPosition(), e->getSalary(), bon, e->getUser());
				p->editEmployee(no, enew);
				cout << "DONE" << endl;
				break;
			}
			case 10:
			{
				string a;
				cout << "Input new User Name: ";
				cin.get();
				getline(cin, a);
				a = "NV" + a;
				Employee*enew = new Employee(e->getNo(), e->getLName(), e->getName(), e->getPhone(), a, e->getDOB(), e->getGender(), e->getPosition(), e->getSalary(), e->getBonus(), a);
				p->editEmployee(no, enew);
				cout << "DONE" << endl;
				break;
			}
			case 11: break;
			default: cout << "You only can input from 1 to 10" << endl;
			}
		} while (choice != 11);
		p->saveEmployee("Employee.csv");
	}

	bool loadSchedule(const char*path, string b)
	{
		ifstream fin;
		fin.open(path);
		if (!fin.is_open())
		{
			cout << "There is something wrong with the Schedule CSV File" << endl;
			return false;
		}
		getline(fin, b, '\n');
		int i = 0;
		while (i < schedule.size())
		{
			getline(fin, schedule[i][0], ',');
			for (int j = 1; j <= 6; j++)
			{
				getline(fin, schedule[i][j], ',');
			}
			getline(fin, schedule[i][7], '\n');
			i++;
		}

		fin.close();
		return true;
	}

	bool saveSchedule(const char*path)
	{
		ofstream fout;
		fout.open(path);

		if (!fout.is_open()) 
		{
			cout << "There is something wrong with the Schedule CSV File" << endl;
			return false;
		}
		fout << "User,Mon,Tue,Wed,Thu,Fri,Sat,Sun" << endl;
		for (int i = 0; i < schedule.size(); i++)
		{
			for (int j = 0; j < schedule[i].size(); j++)
			{
				if (j != schedule[i].size() - 1)
					fout << schedule[i][j] << ",";
				else fout << schedule[i][j] << endl;
			}
		}

		fout.close();
		return true;
	}

	void viewSchedule(Pharmacy*p)
	{
		string name;
		cout << setw(25) << left << "User" << "|";
		cout << setw(8) << left << "Mon" << "|";
		cout << setw(8) << left << "Tue" << "|";
		cout << setw(8) << left << "Wed" << "|";
		cout << setw(8) << left << "Thu" << "|";
		cout << setw(8) << left << "Fri" << "|";
		cout << setw(8) << left << "Sat" << "|";
		cout << setw(8) << left << "Sun" << endl;
		cout << setfill('-');
		cout << setw(95) << "-" << endl;
		cout << setfill(' ');
		for (int i = 0; i < schedule.size(); i++)
		{
			for (int j = 0; j < schedule[0].size(); j++)
			{
				if (j == 0)
				{
					for (int k = 0; k < p->getNumEm(); k++)
					{
						if (schedule[i][j] == p->getEmployee(k + 1)->getUser())
						{
							name = p->getEmployee(k + 1)->getLName() + p->getEmployee(k + 1)->getName();
							cout << setw(25) << left << name << "|";
							break;
						}
					}
				}
				else if (j== schedule[0].size()-1)
				{
					cout << setw(8) << left << schedule[i][j] << endl;
				}
				else
				{
					cout << setw(8) << left << schedule[i][j] << "|";
				}
			}
		}
	}

	void editSchedule(Pharmacy*p)

	{
		viewSchedule(p);
		int choice, day, status, x = 0, y = 0;
		string select;
		do
		{
			cout << "Choose an employee to edit(1-" << p->getNumEm() << "): ";
			cin >> choice;
		} while ((choice <= 0 || choice > p->getNumEm()) && cout << "You can only input from 1 to " << p->getNumEm() << endl);
		for (int k = 0; k < p->getNumEm(); k++)
		{
			if (schedule[choice - 1][0] == p->getEmployee(k + 1)->getUser())
			{
				cout << setw(25) << left << p->getEmployee(k + 1)->getLName() + p->getEmployee(k + 1)->getName() << "|";
				break;
			}
		}
		for (int j = 1; j < schedule[0].size(); j++)
		{
			if (j == schedule[0].size() - 1)
			{
				cout << setw(8) << left << schedule[choice - 1][j] << endl;
			}
			else
			{
				cout << setw(8) << left << schedule[choice - 1][j] << "|";
			}
		}
		do
		{
			do
			{
				cout << "Choose a day to edit" << endl;
				cout << "Mon: 2, Tue: 3, Wed: 4, Thu: 5, Fri: 6, Sat: 7, Sun: 8" << endl;
				cin >> day;
			} while ((day < 2 || day>8) && cout << "You can only input from 2 to 8!!" << endl);
			do
			{
				cout << "Choose the status you want to be (1: Present/ 2: Off): ";
				cin >> status;
			} while (status != 1 && status != 2 && cout << "You only have 2 choices 1/2" << endl);
			if (status == 1)
			{
				schedule[choice - 1][day - 1] = "Present";
			}
			else
			{
				schedule[choice - 1][day - 1] = "Off";
			}
			do
			{
				cout << "Do you want to continue(Yes/No): ";
				cin >> select;
				if (select == "Yes")
				{
					y = 0;
					x = 1;
				}
				else if (select == "No")
				{
					y = 0;
					x = 0;
				}
				else
				{
					cout << "Wrong input!! You only can input Yes/No!!" << endl;
					y = 1;
				}
			} while (y != 0);
		} while (x != 0);
		this->saveSchedule("Workingschedule.csv");
	}

	void viewPayroll(Pharmacy*p)
	{
		cout << setw(3) << left << "No" << "|";
		cout << setw(25) << left << "Last Name";
		cout << setw(10) << left << "Name" << "|";
		cout << setw(10) << left << "Salary" << "|";
		cout << setw(10) << left << "Bonus" << endl;
		cout << setfill('-');
		cout << setw(115) << "-" << endl;
		cout << setfill(' ');
		for (int i = 0; i < p->getNumEm(); i++)
		{
			cout << setw(3) << left << p->getEmployee(i + 1)->getNo() << "|";
			cout << setw(25) << left  << p->getEmployee(i + 1)->getLName();
			cout << setw(10) << left << p->getEmployee(i + 1)->getName() << "|";
			cout << setw(10) << left << p->getEmployee(i + 1)->getSalary() << "|";
			cout << setw(10) << left << p->getEmployee(i + 1)->getBonus() << endl;
		}
	}

	void editPayroll(Pharmacy*p)
	{
		this->viewPayroll(p);
		int choice, x = 0, y = 0, edit;
		double newthing;
		string select;
		do
		{
			cout << "Choose an employee to edit Salary information: ";
			cin >> choice;
		} while ((choice<1 || choice>p->getNumEm()) && cout << "You can only input from 1 to " << p->getNumEm() << endl);
		cout << setw(3) << left << p->getEmployee(choice)->getNo() << "|";
		cout << setw(25) << left << p->getEmployee(choice)->getLName();
		cout << setw(10) << left << p->getEmployee(choice)->getName() << "|";
		cout << setw(10) << left << p->getEmployee(choice)->getSalary() << "|";
		cout << setw(10) << left << p->getEmployee(choice)->getBonus() << endl;
		do
		{
			do
			{
				cout << "Choose a category to edit" << endl;
				cout << "1: Salary, 2: Bonus" << endl;
				cin >> edit;
			} while ((edit != 1 && edit != 2) && cout << "You only have 2 choices 1/2" << endl);
			do
			{
				cout << "Input the amount you want to be: ";
				cin >> newthing;
			} while (newthing <= 0 && cout << "The amount must be positive" << endl);
			Employee*e = p->getEmployee(choice);
			if (edit == 1)
			{
				Employee*enew = new Employee(e->getNo(), e->getLName(), e->getName(), e->getPhone(), e->getID(), e->getDOB(), e->getGender(), e->getPosition(), newthing, e->getBonus(), e->getUser());
				p->editEmployee(choice, enew);
			}
			else 
			{
				Employee*enew = new Employee(e->getNo(), e->getLName(), e->getName(), e->getPhone(), e->getID(), e->getDOB(), e->getGender(), e->getPosition(), e->getSalary(), newthing, e->getUser());
				p->editEmployee(choice, enew);
			}
			do
			{
				cout << "Do you want to continue(Yes/No): ";
				cin >> select;
				if (select == "Yes")
				{
					y = 0;
					x = 1;
				}
				else if (select == "No")
				{
					y = 0;
					x = 0;
				}
				else
				{
					cout << "Wrong input!! You only can input Yes/No!!" << endl;
					y = 1;
				}
			} while (y != 0);
		} while (x != 0);
		p->saveEmployee("Employee.csv");
	}

	void menu(Pharmacy*p)
	{
		string y;
		int choice, index;
		cout << "Admin Menu" << endl
			<< "1. Add new Employee" << endl
			<< "2. Delete an Employee" << endl
			<< "3. Edit an Employee" << endl
			<< "4. View the Employee's list" << endl
			<< "5. View the Work's Schedule" << endl
			<< "6. Edit the Work's Schedule" << endl
			<< "7. View the Payroll" << endl
			<< "8. Edit the Payroll" << endl;
		cout << "Choose a function you want to do: ";
		cin >> choice;
		switch (choice)
		{
		case 1: this->addEmployee(p); break;
		case 2: this->deleteEmployee(p); break;
		case 3: this->editEmployee(p); break;
		case 4: this->viewEmployee(p); break;
		case 5: this->viewSchedule(p); break;
		case 6: this->editSchedule(p); break;
		case 7: this->viewPayroll(p); break;
		case 8: this->editPayroll(p); break;
		default: 
		{
			cout << "Incorrect!! Please try again" << endl;
			this->menu(p);
			break;
		}
		}
		do
		{
			cout << "Do you want to continue ??? (yes/no): ";
			cin >> y;
			if (y== "yes")
			{
				system("cls");
				this->menu(p);
			}
			else if(y=="no")
			{
				cout << "Thanks, See you again !!! \n Click enter to exit !!!" << endl;
				system("pause");
				exit(0);
			}
			else
			{
				cout << "You only can input yes/no!! Please try again" << endl;
				index = 0;
			}
		} while (index==0);
	}

	//Save Employee

};
#endif 