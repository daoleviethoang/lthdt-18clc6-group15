int Login(string &user)
	{
		char pass[50];
		int check = 0;
		int check1 = 0;
		int temp = 0;
		int index = 0;
		do
		{
			cout << "  |=========================|" << endl;
			cout << "  |  (1) - LOGIN            |" << endl;
			cout << "  |  (2) - CHANGE PASSWORD  |" << endl;
			cout << "  |  (3) - CREATE ACOUNT    |" << endl;
			cout << "  |=========================|" << endl;
			cout << "\n ENTER: ";
			cin >> temp;
			cout << "__________________________\n" << endl;
		} while (temp < 1 || temp > 3);
		if (temp == 3)
		{
			createNewUser();
			return 5;
		}
		else
		{
			do
			{

				cout << "USERNAME: ";
				cin >> user;
				cout << "PASSWORD: ";
				inputpassword(pass);
				cout << "__________________________\n" << endl;
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
						savePassword();
						return 4;
					}
				}
				else index = 1;
			} while (index == 1 && cout << "Password account is incorrect" << endl);
		}
	}
