	void InformationTemp(string username)
	{
		for (int i = 0; i < Customer.size(); i++)
		{
			if (Customer[i].phone == username)
			{
				cout << "   ______________________________________" << endl;
				cout << "  |Name: " << Customer[i].lastname << " " << Customer[i].firstname << endl;
				cout << "  |Gender: " << Customer[i].gender << endl;
				cout << "  |Phone: " << Customer[i].phone << endl;
				cout << "  |Date of Birthday: " << Customer[i].dob << endl;
				cout << "  |Address: " << Customer[i].address << endl;
				cout << "  |Job: " << Customer[i].job << endl;
				cout << endl;
				break;
			}
		}
	}
  
  	void InformationOut(string user)
	{
		for (int i = 0; i < employee.size(); i++)
		{
			if (employee[i].User == user)
			{
				cout << "   ______________________________________" << endl;
				cout << "  |Name: " << employee[i].LastName << " " << employee[i].FirstName << endl;
				cout << "  |Gender: " << employee[i].Gender << endl;
				cout << "  |Phone: " << employee[i].Phone << endl;
				cout << "  |ID: " << employee[i].ID << endl;
				cout << "  |Date of Birthday: " << employee[i].DOB << endl;
				cout << "  |Position: " << employee[i].Position << endl;
				cout << "  |Rank: " << Ranking(user) << endl;
				cout << endl;
				break;
			}
		}
	}
