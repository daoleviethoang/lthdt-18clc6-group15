bool loadCalendar()
	{
		ifstream fin;
		fin.open("Workingschedule.csv");
		if (!fin.is_open())
			return false;
		string b, c;
		int i = 0;
		getline(fin, b, '\n');
		while (getline(fin, c, ','))
		{
			int j = 0;
			calen.push_back(vector<string>{c});
			calen[i][j] = c;
			for (j = 1; j < 8; j++)
			{
				if (j == 7)
				{
					getline(fin, b, '\n');
					calen[i].push_back(b);
				}
				else
				{
					getline(fin, b, ',');
					calen[i].push_back(b);
				}
			}
			i++;
		}
		fin.close();
		return true;
	}
  bool saveCalendar()
	{
		ofstream fout;
		fout.open("Workingschedule.csv");
		if (!fout.is_open())
			return false;
		fout << "User,Name,Monday,Tuesday,Wednesday,Thursday,Friday,Saturday,Sunday" << endl;
		for (int i = 0; i < calen.size(); i++)
		{
			for (int j = 0; j < calen[0].size(); j++)
			{
				if (j == calen[0].size() - 1)
				{
					fout << calen[i][j] << endl;
				}
				else
				{
					fout << calen[i][j] << ",";
				}
			}
		}

	}
