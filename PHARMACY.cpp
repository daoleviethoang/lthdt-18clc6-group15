#include "ClassPassword.h"
class PHARMACY
{
private:
	string m_Name;
	vector<PASSWORD> PS;
	vector<string> vt;
public:
	PHARMACY()
	{
		m_Name = "";
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
			PS.push_back(ps);
			PS[i].createUser(user);
			PS[i].createPass(pass);
			i++;
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
	void changePassword(int i)
	{
		char check[30];
		char a[50], b[50];
		do
		{
			cout << "Enter your old password: ";
			inputpassword(check);
			if (check == PS[i].getPass())
			{
				do
				{
					cout << "Enter new password: ";
					inputpassword(a);
					cout << "Enter new password again: ";
					inputpassword(b);
					if (a == b)
					{
						PS[i].createPass(a);
					}
				} while (a != b);
			}
		} while (check != PS[i].getPass() && cout << "Wrong!! Please do it again!" << endl);
	}
	int Login()
	{
		if (loadPassword())
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
				for (int i = 0; i < PS.size(); i++)
				{
					if (user == PS[i].getUser() && pass == PS[i].getPass())
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
						changePassword(check1);
						return 4;
					}
				}
				else index = 1;
			} while (index == 1 && cout << "Password account is incorrect" << endl);
		}
	}
	void Menu()
	{
		int x;
		int x1 = 0;
		cout << "--------------------------------------" << endl;
		cout << "1: OPEN" << endl;
		cout << "2: EXIT" << endl;
		cout << "--------------------------------------" << endl;
		cout << "Please, Enter the request you want: ";
		cin >> x;
		cout << "--------------------------------------" << endl;
		if (x == 1)
		{
			x1 = Login();
			if (x1 == 1)
			{
				system("cls");
				//AdminMenu();

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
		else if (x == 2)
		{
			cout << "Have a nice day!!" << endl;
			system("pause");
			exit(0);

		}
		else
		{
			system("cls");
			cout << "Invalid,please enter again!!" << endl;
			Menu();
		}
	}
	void ViewProInfo(){}
	void ChangePass(){}
	void ForgetPass(){}
	void Logout(){}
	~PHARMACY()
	{
	}
};
void main()
{
	PHARMACY ph;
	ph.Menu();
	_getch();
}