	void addEmployee()
	{
		int dd, mm, yyyy, day, status, x, y;
		string lname, name, gender, phoneNo, id, position, user, select;
		double salary, bonus;
		string dob;
		Date d;
		cout << "Input NEW EMPLOYEE!!" << endl;
		cout << "Input Last name: ";
		cin.get();
		getline(cin, lname);
		cout << "Input First name: ";
		cin >> name;
		do
		{
			cout << endl << "Input the PhoneNo: 0";
			cin >> phoneNo;
		} while (phoneNo.size() != 9 && cout << "Your Phone Number must have 10 characters only!! Please try again" << endl);
		do
		{
			cout << endl << "Input the ID: ";
			cin >> id;
		} while ((id.size() != 9 && id.size() != 12) && cout << "Your ID Number must have 9 or 12 characters only!! Please try again" << endl);

		do
		{
			cout << "Input Birth Day Information!!" << endl << "Input day: ";
			cin >> dd;
			cout << "Input month: ";
			cin >> mm;
			cout << "Input year: ";
			cin >> yyyy;
			dob += to_string(dd) + "/" + to_string(mm);
			dob += "/" + to_string(yyyy);
			d.AssignDate(dd, mm, yyyy);
		} while (!d.checkdate() && cout << "Wrong Information!! Please try again!!" << endl);
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
		EMPLOYEE e(getNumEm() + 1, lname, name, phoneNo, id, dob, gender, position, salary, bonus, user);
		pushEmployee(e);

		cout << "Now, we need to schedule the working time for new employee: " << endl;
		vector<string> newSchedule(9, "Present");
		newSchedule[0] = user;
		newSchedule[1] = lname + " " + name;
		cout << "The current schedule for the new employee is full Present, now you will choose a day-off" << endl;
		cout << setw(17) << left << "User" << "|"
			<< setw(17) << left << "Name" << "|"
			<< setw(8) << left << "Mon" << "|"
			<< setw(8) << left << "Tue" << "|"
			<< setw(8) << left << "Wed" << "|"
			<< setw(8) << left << "Thu" << "|"
			<< setw(8) << left << "Fri" << "|"
			<< setw(8) << left << "Sat" << "|"
			<< setw(8) << left << "Sun" << "|" << endl;
		cout << setw(17) << left << newSchedule[0] << "|";
		cout << setw(17) << left << newSchedule[1] << "|";
		for (int i = 2; i < 9; i++)
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
				newSchedule[day] = "Present";
			}
			else
			{
				newSchedule[day] = "Off";
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
		saveEMP();
	}
