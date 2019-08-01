	void viewCalendar(string user)
	{
		string a;
		for (int i = 0; i < calen.size(); i++)
		{
			if (calen[i][0] == user)
			{
				cout << "	                     Working Schedule" << endl;
				cout << "   Monday  |  Tuesday  | Wednesday |  Thursday |  Friday   | Saturday  | Sunday " << endl;
				cout << "----------------------------------------------------------------------" << endl;
				for (int j = 2; j < calen[0].size(); j++)
				{
					if (j == calen[0].size() - 1)
					{
						cout << setw(11) << calen[i][j] << endl;
					}
					else
					{
						cout << setw(11)<<left << calen[i][j] << "|";
					}
				}
				break;
			}
		}
	}
