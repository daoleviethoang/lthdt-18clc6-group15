	void editPayroll()
	{
		viewPayroll();
		int choice, x = 0, y = 0, edit;
		do
		{
			cout << "Choose an employee to edit Salary information: ";
			cin >> choice;
		} while ((choice<1 || choice>getNumEm()) && cout << "You can only input from 1 to " << getNumEm() << endl);
		editPayRoll1(choice);
		saveEMP();
	}
  
  	void editPayRoll1(int choice)
	{
		int edit, x = 0, y = 0;
		double newthing;
		string select;
		cout << setw(3) << left << getEmployee(choice).No << "|";
		cout << setw(25) << left << getEmployee(choice).LastName;
		cout << setw(10) << left << getEmployee(choice).FirstName<< "|";
		cout << setw(10) << left << getEmployee(choice).Salary << "|";
		cout << setw(10) << left << getEmployee(choice).Bonus << endl;
		do
		{
			do
			{
				cout << "Choose a category to edit" << endl;
				cout << "1: Salary, 2: Bonus" << endl;
				cin >> edit;
			} while ((edit != 1 && edit != 2) && cout << "You only have 2 choices 1/2" << endl);
			do
			{
				cout << "Input the amount you want to be: ";
				cin >> newthing;
			} while (newthing <= 0 && cout << "The amount must be positive" << endl);
			EMPLOYEE e = getEmployee(choice);
			if (edit == 1)
			{
				EMPLOYEE enew(e.No, e.FirstName, e.FirstName, e.Phone, e.ID, e.DOB, e.Gender, e.Position, newthing, e.Bonus, e.User);
				editEmployee2(choice, enew);
			}
			else
			{
				EMPLOYEE enew(e.No, e.FirstName, e.FirstName, e.Phone, e.ID, e.DOB, e.Gender, e.Position, e.Salary, newthing, e.User);
				editEmployee2(choice, enew);
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
	}
