void CheckCusBuy(string Username)
	{
		CUSTOMER cus;
		int z = 0;
		int flag = 0;
		for (int j = 0; j < CusBuy.size(); j++)
		{
			if (CusBuy[j].phone == Username && CusBuy[j].day == getDay() && CusBuy[j].month == getMonth() && CusBuy[j].year == getYear())
			{
				flag = 1;
				break;
			}
		}
		for (int i = 0; i < Customer.size(); i++)
		{
			if (Customer[i].phone == Username && flag == 0)
			{
				z = CusBuy.size();
				cus.no = ++z;
				cus.lastname = Customer[i].lastname;
				cus.firstname = Customer[i].firstname;
				cus.gender = Customer[i].gender;
				cus.phone = Customer[i].phone;
				cus.dob = Customer[i].dob;
				cus.address = Customer[i].address;
				cus.job = Customer[i].job;
				cus.status = Customer[i].status;
				cus.day = getDay();
				cus.month = getMonth();
				cus.year = getYear();
				CusBuy.push_back(cus);
			}
		}
		saveCutomerBuy();
	}
