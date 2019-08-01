void Buy()
	{
		string name;
		string y_n;
		int amount;
		do
		{
			cout << "Name of medicine: ";
			getline(cin, name);
			for (int i = 0; i < mdc.size(); i++)
			{
				if (mdc[i].Name == name)
				{
					cout << "Found the item" << endl;
					cout << "The number of items left in stock is " << mdc[i].Status << "" << endl;
					do
					{
						cout << "\nNumber of medicines you want to buy: ";
						cin >> amount;
					} while (amount > mdc[i].Status && cout << "Exceeded the quantity" << endl);
					mdc[i].Status -= amount;
					mdc[i].Sold = amount;
					saveMedicine();
					cout << "We are shipping, Thank you!!!" << endl;
					y_n = "";
					break;
				}
				else
				{
					cout << "No drugs found" << endl;
					cout << "Do you want to re-enter? (yes/no): ";
					getline(cin, y_n);
					break;
				}
			}
		} while (y_n == "yes");

	}
