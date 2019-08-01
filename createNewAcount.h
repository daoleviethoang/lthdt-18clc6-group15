void createNewUser()
	{
		string buffer;
		string user;
		int dd, mm, yyyy;
		string lname, name, gender, phoneNo, id, job, status, address;
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
			if (choice == 1)
				user = "NV" + user;
			for (int i = 0; i < PS.size(); i++)
			{
				if (user == PS[i].getUser())
				{
					check = 1;
					break;
				}
			}
			if (check != 1 && choice == 1)
			{
				for (int i = 2; i < user.size(); i++)
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
		if (choice == 1)
		{
			cout << "Input the PhoneNo: ";
			cin >> phoneNo;
			cout << "Input the ID: ";
			cin >> id;
		}
		else
		{
			phoneNo = user;
			cout << "Input Address: ";
			cin >> address;
			cout << "Input Job: ";
			cin >> job;
			cout << "Input Status: ";
			cin >> status;
		}
		do
		{
			cout << "Input Birth Day Information!!" << endl << "Input day: ";
			cin >> dd;
			cout << "Input month: ";
			cin >> mm;
			cout << "Input year: ";
			cin >> yyyy;
			D.AssignDate(dd, mm, yyyy);
			buffer = to_string(dd) + "/" + to_string(mm) + "/" + to_string(yyyy);
		} while (!D.checkdate() && cout << "Wrong Information!! Please try again!!" << endl);
		do
		{
			cout << "Input the gender(Male/Female): ";
			cin >> gender;
		} while ((gender != "Male" && gender != "Female") && cout << "You have to input Male/Female! Please try again!!" << endl);

		if (choice == 1)
		{
			emp.contructorEmployee(user, lname, name, phoneNo, id, buffer, gender, " ", 0, 0);
			string s_name = lname + " " + name;
			emp.contructorCalendar(user, s_name);
			emp.contructorAttendane(user);
		}
		else
		{
			//, string Address,string Job, string Status, string Lastcheck, string Note)
			cus.contructorCustomer(lname, name, gender, phoneNo, buffer, address, job, status, "", "");
		}
		PASSWORD pa;
		pa.createPass(pass);
		pa.createUser(user);
		PS.push_back(pa);
		this->savePassword();
	}
