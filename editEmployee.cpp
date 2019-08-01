	void editEmployee()
	{
		cout << "EDIT EMPLOYEE" << endl;
		viewEmployee();
		int no;
		do
		{
			cout << "Choose an employee you want to edit: ";
			cin >> no;
		} while ((no <= 0 || no >= getNumEm()) && cout << "The pharmacy only have " << getNumEm() << " please try again!!" << endl);
		EMPLOYEE e = getEmployee(no);
		editEmployee1(e, no);
		saveEMP();
	}
  
  	void editEmployee1(EMPLOYEE e, int no)
	{
		int choice;
		do
		{
			system("cls");
			cout << "Information of the Employee you choose!!" << endl;
			cout << setfill(' ');
			cout << setw(3) << left << e.No << "|";
			cout << setw(24) << left << e.LastName;
			cout << setw(9) << left << e.FirstName << "|";
			cout << setw(9) << left << e.Phone << "|";
			cout << setw(9) << left << e.ID << "|";
			cout << setw(8) << right << e.DOB << "|";
			cout << setw(9) << left << e.Gender << "|";
			cout << setw(14) << left << e.Position << "|";
			cout.precision(20);
			cout << setw(9) << left << e.Salary << "|";
			cout << setw(9) << left << e.Bonus << endl;	
			cout << "Choose 1 category to edit: " << endl;
			cout << "1. Last Name" << endl;
			cout << "2. First Name: " << endl;
			cout << "3. Phone No: " << endl;
			cout << "4. ID: " << endl;
			cout << "5. DOB: " << endl;
			cout << "6. Gender: " << endl;
			cout << "7. Position: " << endl;
			cout << "8. Salary: " << endl;
			cout << "9. Bonus: " << endl;
			cout << "10. User Name: " << endl;
			cout << "11. Done" << endl;
			cin >> choice;
			switch (choice)
			{
			case 1:
			{
				string a;
				cout << "Input new Last name: ";
				cin.get();
				getline(cin, a);
				EMPLOYEE enew(e.No, a, e.FirstName, e.Phone, e.ID, e.DOB, e.Gender, e.Position, e.Salary, e.Bonus, e.User);
				editEmployee2(no, enew);
				cout << "DONE" << endl;
				break;
			}
			case 2:
			{
				string a;
				cout << "Input new First Name: ";
				cin.get();
				getline(cin, a);
				EMPLOYEE enew(e.No, e.LastName, a, e.Phone, e.ID, e.DOB, e.Gender, e.Position, e.Salary, e.Bonus, e.User);
				editEmployee2(no, enew);
				cout << "DONE" << endl;
				break;
			}
			case 3:
			{
				string a;
				do
				{
					cout << "Input new Phone Number: ";
					cin.get();
					getline(cin, a);
				} while (a.size() != 9 && cout << "Your Phone Number must have 10 characters only!! Please try again" << endl);
				EMPLOYEE enew(e.No, e.LastName, e.FirstName, a, e.ID, e.DOB, e.Gender, e.Position, e.Salary, e.Bonus, e.User);
				editEmployee2(no, enew);
				cout << "DONE" << endl;
				break;
			}
			case 4:
			{
				string a;
				do {
					cout << "Input new ID No: ";
					cin.get();
					getline(cin, a);
				} while ((a.size() != 9 && a.size() != 12) && cout << "Your ID Number must have 9 or 12 characters only!! Please try again" << endl);

				EMPLOYEE enew(e.No, e.FirstName, e.FirstName, e.Phone, a, e.DOB, e.Gender, e.Position, e.Salary, e.Bonus, e.User);
				editEmployee2(no, enew);
				cout << "DONE" << endl;
				break;
			}

			case 5:
			{
				int dd, mm, yyyy;
				Date dob;
				string d;
				cout << "Input new Birthday information!!" << endl;
				do
				{
					cout << "Input day: ";
					cin >> dd;
					cout << "Input month: ";
					cin >> mm;
					cout << "Input year: ";
					cin >> yyyy;
					dob.AssignDate(dd, mm, yyyy);
					string d = to_string(dd) + "/" + to_string(mm);
					d += "/" + to_string(yyyy);
				} while (!dob.checkdate() && cout << "Wrong Information!! Please try again!!" << endl);
				EMPLOYEE enew(e.No, e.FirstName, e.FirstName, e.Phone, e.ID, d, e.Gender, e.Position, e.Salary, e.Bonus, e.User);
				editEmployee2(no, enew);
				cout << "DONE" << endl;
				break;
			}
			case 6:
			{
				string a;
				do
				{
					cout << "Input new Gender(Male/Female): ";
					cin >> a;
				} while ((a != "Male" && a != "Female") && cout << "You have to input Male/Female! Please try again!!" << endl);
				EMPLOYEE enew(e.No, e.FirstName, e.FirstName, e.Phone, e.ID, e.DOB, a, e.Position, e.Salary, e.Bonus, e.User);
				editEmployee2(no, enew);
				cout << "DONE" << endl;
				break;
			}
			case 7:
			{
				string a;
				cout << "Input new Position: ";
				cin.get();
				getline(cin, a);
				EMPLOYEE enew(e.No, e.FirstName, e.FirstName, e.Phone, e.ID, e.DOB, e.Gender, a, e.Salary, e.Bonus, e.User);
				editEmployee2(no, enew);
				cout << "DONE" << endl;
				break;
			}
			case 8:
			{
				double sal;
				do
				{
					cout << "Input the new salary: ";
					cin >> sal;
				} while (sal <= 0 && cout << "Salary must be positive!!" << endl);
				EMPLOYEE enew(e.No, e.FirstName, e.FirstName, e.Phone, e.ID, e.DOB, e.Gender, e.Position, sal, e.Bonus, e.User);
				editEmployee2(no, enew);
				cout << "DONE" << endl;
				break;
			}
			case 9:
			{
				int bon;
				do
				{
					cout << "Input the new bonus: ";
					cin >> bon;
				} while (bon <= 0 && cout << "Salary must be positive!!" << endl);
				EMPLOYEE enew(e.No, e.FirstName, e.FirstName, e.Phone, e.ID, e.DOB, e.Gender, e.Position, e.Salary, bon, e.User);
				editEmployee2(no, enew);
				cout << "DONE" << endl;
				break;
			}
			case 10:
			{
				string a;
				cout << "Input new User Name: ";
				cin.get();
				getline(cin, a);
				a = "NV" + a;
				EMPLOYEE enew(e.No, e.FirstName, e.FirstName, e.Phone, e.ID, e.DOB, e.Gender, e.Position, e.Salary, e.Bonus, a);
				editEmployee2(no, enew);
				cout << "DONE" << endl;
				break;
			}
			case 11: break;
			default: cout << "You only can input from 1 to 10" << endl;
			}
		} while (choice != 11);
	}
