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