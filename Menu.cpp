	void Menu()
	{
		static int  flagflag = 0;
		if (flagflag == 0)
		{
			loadPassword();
			CreateFileAtten();
			flagflag++;
		}
		int x;
		int x1 = 0;
		cout << "        ______________________________________" << endl;
		cout << "       |--------------------------------------|" << endl;
		cout << "       |             (1) - OPEN               |" << endl;
		cout << "       |             (2) - EXIT               |" << endl;
		cout << "       |______________________________________|" << endl;
		cout << "\n <3_Please, Enter the request you want: ";
		cin >> x;
		cout << "_____________________________________________\n" << endl;
		if (x == 1)
		{
			string user;
			x1 = Login(user);
			Sleep(3000);
			if (x1 == 1)
			{
				system("cls");
				if (adm.Adminmenu() == 1)
				{
					system("cls");
					Menu();
				}
			}
			if (x1 == 2)
			{
				system("cls");
				if (emp.EmployeeMenu(user) == 1)
				{
					system("cls");
					Menu();
				}
			}
			if (x1 == 3)
			{
				system("cls");
				if (cus.CustomerMenu(user) == 1)
				{
					system("cls");
					Menu();
				}

			}
			if (x1 == 4)
			{
				cout << "Change the password successfully. HAVE A NICE DAY" << endl;
				string answer;
				cout << "Do you want to continue ??? (yes/no): ";
				cin >> answer;
				if (answer == "yes")
				{
					system("cls");
					Menu();
				}
				else
				{
					cout << "Thanks, See you again !!! \n Click enter to exit !!!" << endl;
					_getch();
					exit(0);
				}
				system("pause");
			}
			if (x1 == 5)
			{
				cout << " * Account successfully created *" << endl;
				string answer;
				cout << "Do you want to log in? (yes/no): ";
				cin >> answer;
				if (answer == "yes")
				{
					system("cls");
					Menu();
				}
				else
				{
					cout << "Thanks, See you again !!! \n Click enter to exit !!!" << endl;
					_getch();
					exit(0);
				}
				system("pause");
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
