bool CreateFileAtten()
	{
		D.getDateMyPC();
		if (CheckDate() == false || check_date != D.getMonth())
		{
			char g_m[4];
			string g_month;
			_itoa(D.getMonth(), g_m, 10);
			g_month = g_m;
			ofstream fout;
			fout.open("Attendance.csv");
			if (!fout.is_open())
				return false;
			vector<string> vt;
			char buff[20];
			string S;
			for (int i = 0; i < 33; i++)
			{
				if (i == 0)
				{
					vt.push_back("Month " + g_month + " attendance sheet\n");
				}
				else if (i == 1) vt.push_back("User");
				else
				{
					_itoa(i - 1, buff, 10);
					S = buff;
					vt.push_back("Day" + S);
				}
			}
			if (D.checkdate())
			{
				int  i = 0;
				while (i < D.getMaxDay() + 2)
				{
					fout << vt[i];
					if (i != 0 && i < D.getMaxDay() + 1)
						fout << ",";
					i++;
				}
			}
				fout << endl;
				for (int i = 1; i < PS.size(); i++)
				{
					string a = PS[i].getUser();
					if (a[0] == 'N' && a[1] == 'V')
					{
						fout << PS[i].getUser() << ",";
						for (int j = 0; j < D.getMaxDay(); j++)
						{
							if (j == D.getMaxDay() - 1)
								fout << " " << endl;
							else
							{
								fout << " ,";
							}
						}
					}
				}
			fout.close();
			return true;
		}
	}
