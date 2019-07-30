#ifndef _MAIN_H_
#define _MAIN_H_

#include "Pharmacy.h"
#include "Admin.h"

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

int Login(PHARMACY*p)
{
	if (p->loadPassword())
	{
		string user;
		char pass[50];
		int check = 0;
		int check1 = 0;
		int temp = 0;
		int index = 0;
		do
		{
			cout << "1: Login" << endl;
			cout << "2: Change Password" << endl;
			cout << "Enter: ";
			cin >> temp;
			cout << "--------------------------------------" << endl;
		} while (temp > 2);
		do
		{
			cout << "Username: ";
			cin >> user;
			cout << "Password: ";
			inputpassword(pass);
			for (int i = 0; i < p->getNumPass(); i++)
			{
				if (user == p->getPass(i).getUser() && pass == p->getPass(i).getPass())
				{
					check = 1;
					check1 = i;
					break;
				}
			}
			if (check == 1)
			{
				if (temp == 1)
				{
					if (user[0] == 'N' && user[1] == 'V')
						return 2;
					else if (user == "admin")
						return 1;
					else return 3;
				}
				else if (temp == 2)
				{
					p->changePassword(check1);
					return 4;
				}
			}
			else index = 1;
		} while (index == 1 && cout << "Password account is incorrect" << endl);
	}
}
void Menu(PHARMACY*p)
{
	int x;
	int x1 = 0;
	cout << "--------------------------------------" << endl;
	cout << "1: OPEN" << endl;
	cout << "2. CREATE NEW USER" << endl;
	cout << "3: EXIT" << endl;
	cout << "--------------------------------------" << endl;
	cout << "Please, Enter the request you want: ";
	cin >> x;
	cout << "--------------------------------------" << endl;
	if (x == 1)
	{
		x1 = Login(p);
		if (x1 == 1)
		{
			system("cls");
			Admin*ad = new Admin(p);
			ad->menu(p);
		}
		if (x1 == 2)
		{
			system("cls");
			//EmployeeMenu();

		}
		if (x1 == 3)
		{
			system("cls");
			//CustomerMenu();
		}
		if (x1 == 4)
		{
			cout << "Change the password successfully. HAVE A NICE DAY" << endl;
			system("pause");
			exit(0);
		}
	}
	else if(x==2)
	{
		p->createNewUser();
	}
	else if (x == 3)
	{
		cout << "Have a nice day!!" << endl;
		system("pause");
		exit(0);

	}
	else
	{
		system("cls");
		cout << "Invalid,please enter again!!" << endl;
		Menu(p);
	}
}




#endif