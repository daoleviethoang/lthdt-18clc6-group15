	void editSchedule()
	{
		viewSchedule();
		int choice, day, status, x = 0, y = 0;
		string select;
		do
		{
			cout << "Choose an employee to edit(1-" << getNumEm() << "): ";
			cin >> choice;
		} while ((choice <= 0 || choice > getNumEm()) && cout << "You can only input from 1 to " << getNumEm() << endl);
		for (int j = 0; j < schedule[0].size(); j++)
		{
			if (j == 0 || j == 1)
			{
				cout << setw(25) << left << schedule[choice - 1][j] << "|";
			}
			else if (j == schedule[0].size() - 1)
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
				schedule[choice - 1][day] = "Present";
			}
			else
			{
				schedule[choice - 1][day] = "Off";
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
