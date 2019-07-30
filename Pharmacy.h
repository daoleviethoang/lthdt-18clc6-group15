#pragma once
#include "ClassPassword.h"
#include "EMPLOYEE.h"
class PHARMACY:public PASSWORD
{
private:
	string m_Name;
	vector<PASSWORD> PS;
	vector<string> vt;
	vector<Employee*>m_Emp;
	Date D;
protected:
	int checkdate;
public:
	PHARMACY()
	{
		m_Name = "";
		checkdate = 0;
	}
	bool loadPassword()
	{
		ifstream fin;
		fin.open("Password.csv");
		if (!fin.is_open())
			return false;
		string user, pass;
		PASSWORD ps;
		string a;
		int i = 0;
		getline(fin, a, '\n');
		while (!fin.eof())
		{
			getline(fin, user, ',');
			getline(fin, pass, '\n');
			ps = PASSWORD::PASSWORD(user, pass);
			PS.push_back(ps);
		}
		fin.close();
		return true;
	}
	bool savePassword()
	{
		ofstream fout;
		fout.open("Password.csv");
		if (!fout.is_open())
			return false;
		fout << "User,Pass" << endl;
		for (int i = 0; i < PS.size(); i++)
		{
			fout << PS[i].getUser() << "," << PS[i].getPass() << endl;
		}
		fout.close();
		return true;
	}

	void inputpassword(char password[])
	{
		int i = 0;
		for (char c; (c = _getch());)
		{
			if (c == '\n' || c == '\r')
			{
				cout << "\n";
				break;
			}
			else if (c == '\b')
			{
				cout << "\b \b";
				if (i != 0)
					password[i - 1] = NULL;
				i++;
			}
			else if (c == -32)
			{
				_getch();
			}
			else if (isprint(c))
			{
				cout << '*';
				password[i++] = c;
			}
		}
		password[i] = NULL;
	}


	bool loadEmployee(const char *path, string b)
	{
		ifstream fin;
		fin.open(path);
		if (fin.fail())
			return false;

		int No, dd, mm, yyyy;
		string lname, name, gender, phoneNo, id, position, user;
		double salary, bonus;

		getline(fin, b, '\n');
		while (fin >> No)
		{
			fin.get();
			getline(fin, user, ',');
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
			getline(fin, b, '\n');
			Date d;
			d.input(dd, mm, yyyy);
			Employee*e = new Employee(No, lname, name, phoneNo, id, d, gender, position, salary, bonus, user);
			m_Emp.push_back(e);
		}
		fin.close();
		return true;
	}

	bool saveEmployee(const char*path)
	{
		ofstream fout;
		fout.open(path);

		if (!fout.is_open())
		{
			cout << "There is something wrong with the Employee's File!!" << endl;
			return false;
		}

		fout << "No,User,Last Name,First Name,Phone,ID,DOB,Gender,Position,Salary,Bonus" << endl;
		for (int i = 0; i < m_Emp.size(); i++)
		{
			fout << m_Emp[i]->getNo() << ","
				<< m_Emp[i]->getUser() << ","
				<< m_Emp[i]->getLName() << ","
				<< m_Emp[i]->getName() << ","
				<< m_Emp[i]->getPhone() << ","
				<< m_Emp[i]->getID() << ","
				<< m_Emp[i]->getDOB() << ","
				<< m_Emp[i]->getGender() << ","
				<< m_Emp[i]->getPosition() << ","
				<< m_Emp[i]->getSalary() << ","
				<< m_Emp[i]->getBonus() << endl;
		}

		fout.close();
		return true;
	}

	void ViewProInfo() {}
	void Logout() {}
	bool CheckDate()
	{
		ifstream fin;
		fin.open("Attendance.csv");
		if (!fin.is_open())
			return false;
		string a;
		getline(fin, a, ' ');
		fin >> checkdate;
		fin.get();
		fin.close();
		return true;
	}
	/*bool CreateFileAtten()
	{
		D.getDateMyPC();
		if (CheckDate() == false || checkdate != D.getMonth())
		{
			char g_m[4];
			string g_month;
			_itoa(D.getMonth(), g_m, 10);
			g_month = g_m;
			ofstream fout;
			fout.open("Attendance.csv");
			if (!fout.is_open())
				return false;
			vector<string> vt;
			char buff[20];
			string S;
			for (int i = 0; i < 33; i++)
			{
				if (i == 0)
				{
					vt.push_back("Month " + g_month + " attendance sheet\n");
				}
				else if (i == 1) vt.push_back("User");
				else
				{
					_itoa(i - 1, buff, 10);
					S = buff;
					vt.push_back("Day" + S);
				}
			}
			if (D.checkdate())
			{
				int  i = 0;
				while (i < D.getMaxDay() + 2)
				{
					fout << vt[i];
					if (i != 0 && i < D.getMaxDay() + 1)
						fout << ",";
					i++;
				}
			}
			if (loadPassword())
			{
				fout << endl;
				for (int i = 1; i < PS.size(); i++)
				{
					fout << PS[i].getUser() << ",";
					for (int j = 0; j < D.getMaxDay(); j++)
					{
						if (j == D.getMaxDay() - 1)
							fout << " " << endl;
						else
						{
							fout << " ,";
						}
					}
				}
			}
			fout.close();
			return true;
		}
	}*/

	void createNewUser()
	{
		if (loadPassword())
		{
			string user;
			int dd, mm, yyyy;
			Date dob;
			string lname, name, gender, phoneNo, id;
			char pass[50];
			char pass2[50];
			int choice;
			int check = 0;
			do
			{
				cout << "You have 2 choices" << endl << "Employee (1) | (2) Customer:   ";
				cin >> choice;
			} while ((choice != 1 && choice != 2) && cout << "Wrong input!! Please input again");

			do
			{
				check = 0;
				cout << endl << "Username ";
				if (choice == 1)
				{
					cout << "(Enter your full name without space with normal character here please): ";
				}
				else
				{
					cout << "(Enter your phone number here please): ";
				}
				cin >> user;
				for (int i = 0; i < PS.size(); i++)
				{
					if (user == PS[i].getUser())
						check = 1;
				}
				if (check != 1 && choice == 1)
				{
					for (int i = 0; i < user.size(); i++)
					{
						if (user[i] < 'a' || user[i] > 'z')
							check = 2; break;
					}
				}
				if (check != 1 && choice == 2)
				{
					for (int i = 0; i < user.size(); i++)
					{
						if (user[i] < '0' || user[i]>'9')
							check = 3; break;
					}
				}
			} while ((check == 1) && cout << "It seems that this username already exists, please enter again!!" || (check == 2) && cout << "There is a capitalize letter in your username, please enter again" || (check == 3) && cout << "Please input your phone number!!");

			if (choice == 1)
				user = "NV" + user;

			do
			{
				cout << "Password: ";
				inputpassword(pass);
				cout << "Enter your password again: ";
				inputpassword(pass2);
			} while (strcmp(pass, pass2) != 0 && cout << "Please input again!!" << endl);


			cout << "Now, Enter the information: " << endl;
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

			if (choice == 1)
			{
				Employee*e = new Employee(lname, name, phoneNo, id, dob, gender, user, m_Emp.size() + 1);
				m_Emp.push_back(e);
				this->saveEmployee("Employee.csv");
			}
			else
			{
				//Them Khach vo danh sach cho nay nha
			}

			PASSWORD pa;
			pa.createPass(pass);
			pa.createUser(user);
			PS.push_back(pa);
			this->savePassword();

			cout << "Successfull" << endl;
		}
	}

	int getNumEm()
	{
		return m_Emp.size();
	}

	int getNumPass()
	{
		return PS.size();
	}

	PASSWORD getPass(int i)
	{
		return PS[i];
	}

	void changePassword(int i)
	{
		int flag = 0;
		char check[30];
		char a[50], b[50];
		do
		{
			cout << "Enter your old password: ";
			inputpassword(check);
			if (check == PS[i].getPass())
			{
				flag = 1;
				do
				{
					cout << "Enter new password: ";
					inputpassword(a);
					cout << "Enter new password again: ";
					inputpassword(b);
					if (strcmp(a, b) == 0)
					{
						PS[i].createPass(a);
					}
				} while ((strcmp(a, b) != 0) && cout << "It dosen't match!! Please try again" << endl);
			}
		} while (check != PS[i].getPass() && flag == 0 && cout << "Wrong!! Please do it again!" << endl);
	}
	void addEmployee(Employee*e)
	{
		m_Emp.push_back(e);
	}

	void deleteEmployee(int n)
	{
		m_Emp.erase(m_Emp.begin() + n - 1);
		for (int i = n - 1; i < m_Emp.size(); i++)
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
		cout << setw(3) << left << m_Emp[n - 1]->getNo() << "|";
		cout << setw(24) << left << m_Emp[n - 1]->getLName();
		cout << setw(9) << left << m_Emp[n - 1]->getName() << "|";
		cout << setw(9) << left << m_Emp[n - 1]->getPhone() << "|";
		cout << setw(9) << left << m_Emp[n - 1]->getID() << "|";
		cout << setfill('0');
		cout << setw(2) << right << m_Emp[n - 1]->getDOB() << "|";
		cout << setfill(' ');
		cout << setw(9) << left << m_Emp[n - 1]->getGender() << "|";
		cout << setw(14) << left << m_Emp[n - 1]->getPosition() << "|";
		cout.precision(20);
		cout << setw(9) << left << m_Emp[n - 1]->getSalary() << "|";
		cout << setw(9) << left << m_Emp[n - 1]->getBonus() << endl;
	}

};