	void BuyPre()
	{
		int a = 0;
		int b = 0;
		loadMedicine();
		srand(time(NULL));
		cout << "Prescription" << endl;
		for (int i = 0; i < 5; i++)
		{
			a = rand() % mdc.size() + 1;
			if (mdc[a].Status <= 0)
			{
				cout << "  " << i + 1 << ": " << mdc[a].Name << ", Out of stock" << endl;
			}
			else
			{
				b = rand() % mdc[a].Status + 1;
				cout << "  " << i + 1 << ": " << mdc[a].Name << ", " << b << "-" << mdc[a].Form << endl;
			}
		}
		mdc[a].Status -= b;
		mdc[a].Sold += b;
		saveMedicine();
		cout << "Preparing the order" << endl;
		Sleep(3000);
		cout << "We are shipping, Thank you!!!" << endl;
	}
