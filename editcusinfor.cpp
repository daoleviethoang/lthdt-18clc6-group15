	void editInfor(string Username)
	{
		int select = 0;
		int flagtemp = 0;
		for (int i = 0; i < Customer.size(); i++)
		{
			for (int j = 0; j < Schedule.size(); j++)
			{
				if (Schedule[j].phone == Username)
				{
					flagtemp = j;
					break;
				}
			}
			if (Username == Customer[i].phone)
			{
				cout << "              [ My current information ]" << endl;
				cout << "  (1) Lastname: " << Customer[i].lastname << endl;
				cout << "  (2) Firstname: " << Customer[i].firstname << endl;
				cout << "  (3) Gender: " << Customer[i].gender << endl;
				cout << "  (4) Phone: " << Customer[i].phone << endl;
				cout << "  (5) Date Of Birthday: " << Customer[i].dob << endl;
				cout << "  (6) Address: " << Customer[i].address << endl;
				cout << "  (7) Job: " << Customer[i].job << endl;
				cout << "  (8) Status: " << Customer[i].status << endl;
				cout << "  (9) LastCheck: " << Customer[i].lastcheck << endl;
				cout << "  (10) Note: " << Customer[i].note << endl;
				while (1)
				{
					int flag = 0;
					do
					{
						cout << endl;
						cout << " Select: ";
						cin >> select;
						cin.get();
					} while (select < 1 || select > 10);
					cout << endl;
					switch (select)
					{
					case 1:
					{
						string New;
						cout << "New Lastname: ";
						getline(cin, New);
						Customer[i].lastname = New;
						Schedule[flagtemp].lastname = New;
						if (saveCustomer() && saveSchedule())
							cout << "|*| Success |*|" << endl;
						string answer;
						cout << endl;
						cout << "Do you want to edit another ??? (yes/no): ";
						cin >> answer;
						if (answer == "yes")
							flag = 1;
						break;
					}
					case 2:
					{
						string New;
						cout << "New Firstname: ";
						getline(cin, New);
						Customer[i].firstname = New;
						Schedule[flagtemp].firstname = New;
						if (saveCustomer() && saveSchedule())
							cout << "|*| Success |*|" << endl;
						string answer;
						cout << endl;
						cout << "Do you want to edit another ??? (yes/no): ";
						cin >> answer;
						if (answer == "yes")
							flag = 1;
						break;
					}
					case 3:
					{
						string New;
						cout << "New Gender: ";
						getline(cin, New);
						Customer[i].gender = New;
						Schedule[flagtemp].gender = New;
						if (saveCustomer() && saveSchedule())
							cout << "|*| Success |*|" << endl;
						string answer;
						cout << endl;
						cout << "Do you want to edit another ??? (yes/no): ";
						cin >> answer;
						if (answer == "yes")
							flag = 1;
						break;
					}
					case 4:
					{
						string New;
						cout << "New Phone: ";
						getline(cin, New);
						Customer[i].phone = New;
						Schedule[flagtemp].phone = New;
						if (saveCustomer() && saveSchedule())
							cout << "|*| Success |*|" << endl;
						string answer;
						cout << endl;
						cout << "Do you want to edit another ??? (yes/no): ";
						cin >> answer;
						if (answer == "yes")
							flag = 1;
						break;
					}
					case 5:
					{
						string New;
						cout << "New Date Of Birthday: ";
						getline(cin, New);
						Customer[i].dob = New;
						Schedule[flagtemp].dob = New;
						if (saveCustomer() && saveSchedule())
							cout << "|*| Success |*|" << endl;
						string answer;
						cout << endl;
						cout << "Do you want to edit another ??? (yes/no): ";
						cin >> answer;
						if (answer == "yes")
							flag = 1;
						break;
					}
					case 6:
					{
						string New;
						cout << "New Address: ";
						getline(cin, New);
						Customer[i].address = New;
						if (saveCustomer())
							cout << "|*| Success |*|" << endl;
						string answer;
						cout << endl;
						cout << "Do you want to edit another ??? (yes/no): ";
						cin >> answer;
						if (answer == "yes")
							flag = 1;
						break;
					}
					case 7:
					{
						string New;
						cout << "New Job: ";
						getline(cin, New);
						Customer[i].job = New;
						if (saveCustomer())
							cout << "|*| Success |*|" << endl;
						string answer;
						cout << endl;
						cout << "Do you want to edit another ??? (yes/no): ";
						cin >> answer;
						if (answer == "yes")
							flag = 1;
						break;
					}
					case 8:
					{
						string New;
						cout << "New Status: ";
						getline(cin, New);
						Customer[i].status = New;
						if (saveCustomer())
							cout << "|*| Success |*|" << endl;
						string answer;
						cout << endl;
						cout << "Do you want to edit another ??? (yes/no): ";
						cin >> answer;
						if (answer == "yes")
							flag = 1;
						break;
					}
					case 9:
					{
						string New;
						cout << "New LastCheck: ";
						getline(cin, New);
						Customer[i].lastcheck = New;
						if (saveCustomer())
							cout << "|*| Success |*|" << endl;
						string answer;
						cout << endl;
						cout << "Do you want to edit another ??? (yes/no): ";
						cin >> answer;
						if (answer == "yes")
							flag = 1;
						break;
					}
					case 10:
					{
						string New;
						cout << "New Note: ";
						getline(cin, New);
						Customer[i].note = New;
						if (saveCustomer())
							cout << "|*| Success |*|" << endl;
						string answer;
						cout << endl;
						cout << "Do you want to edit another ??? (yes/no): ";
						cin >> answer;
						if (answer == "yes")
							flag = 1;
						break;
					}
					default:
					{
						break;
					}
					}
					if (flag == 0)
					{
						cout << "\n *.* Edit successfull *.*" << endl;
						break;
					}
				}
			}
		}
	}
