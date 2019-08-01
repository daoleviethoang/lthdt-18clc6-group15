void ScheduleConsult(string Username)
	{
		CUSTOMER cus;
		long int S = 0;
		for (int i = 0; i < Customer.size(); i++)
		{
			if (Username == Customer[i].phone)
			{
				cus.no = Schedule.size() + 1;
				cus.lastname = Customer[i].lastname;
				cus.firstname = Customer[i].firstname;
				cus.gender = Customer[i].gender;
				cus.phone = Customer[i].phone;
				cus.dob = Customer[i].dob;
				cout << "Medical examination day" << endl;
				do
				{
					cout << "Day: ";
					cin >> cus.day;
					cout << "Month: ";
					cin >> cus.month;
					cout << "Year: ";
					cin >> cus.year;
					getDateMyPC();
					S = calDate(cus.year, cus.month, cus.day) - calDate(getYear(), getMonth(), getDay());
					AssignDate(cus.day, cus.month, cus.year);
				} while ((checkdate() == false || S < 0) && cout << "Invalid registration date, please re-enter" << endl);
				if (checkdate() == true)
				{
					cout << "Schedule successful, thanks. See you !!!" << endl;
					Schedule.push_back(cus);
					saveSchedule();
					return;
				}
			}
		}
	}
