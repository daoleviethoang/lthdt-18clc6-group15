bool ServiceEval()
	{
		EMP e;
		loadEMP(e);
		vector<vector<string>> calen;
		ifstream fin;
		fin.open("Workingschedule.csv");
		if (!fin.is_open())
			return false;
		string b, c;
		int i = 0;
		while (getline(fin, c, ','))
		{
			int j = 0;
			calen.push_back(vector<string>{c});
			calen[i][j] = c;
			for (j = 1; j < 9; j++)
			{
				if (j == 8)
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
		string temp;
		string temp2;
		int check = 0;
		getDateMyPC();
		for (int i = 1; i < calen[0].size(); i++)
		{
			temp = calen[0][i];
			for (int j = 0; j < 3; j++)
			{
				temp2 += temp[j];
			}
			if (getThu() == temp2)
			{
				check = i;
				break;
			}
			temp2 = "";
		}
		int point = 0;
		int name;
		int select;
		vector<int> current;
		while (1)
		{
			int index3 = 0;
			cout << "I. Staff assessment" << endl;
			cout << endl;
			cout << " [ List of employee ]" << endl;
			for (int i = 1; i < calen.size(); i++)
			{
				if (calen[i][check] == "Present")
				{
					index3++;
					cout << "   " << index3 << ": " << calen[i][1] << endl;
					current.push_back(i);
				}
			}
			do
			{
				cout << "Select: ";
				cin >> select;
			} while ((select < 1 || select > current.size()) && cout << "Please, reseclect" << endl);
			cout << endl;
			cout << " Your review: " << endl;
			cout << "   1: Unsatisfied" << endl;
			cout << "   2: Satisfied" << endl;
			cout << "   3: Very pleased" << endl;
			do
			{
				cout << " Select: ";
				cin >> point;
			} while ((point > 3 || point < 1) && cout << "Please Reselect" << endl);
			if (point == 1)
			{
				e.emp[current[select - 1] - 1].Bonus -= 2;
			}
			else if (point == 3)
			{
				e.emp[current[select - 1] - 1].Bonus += 2;
			}
			string answer;
			cout << "\nDo you want to rate other employees?? (yes/no): ";
			cin >> answer;
			cout << endl;
			if (answer == "yes")
			{
				system("cls");
			}
			else
			{
				break;
			}
		}
		cout << "II. Service evaluation" << endl;
		cout << " Your review: " << endl;
		cout << "   1: Unsatisfied" << endl;
		cout << "   2: Satisfied" << endl;
		cout << "   3: Very pleased" << endl;
		do
		{
			cout << " Select: ";
			cin >> point;
		} while ((point > 3 || point < 1) && cout << "Please Reselect" << endl);
		for (int i = 0; i < current.size(); i++)
		{
			if (point == 1)
			{
				e.emp[current[i] - 1].Bonus -= 2;
			}
			else if (point == 3)
			{
				e.emp[current[i] - 1].Bonus += 2;
			}
		}
		cout << "\nThanks for your review. Hope you get better soon !!!" << endl;
		saveEMP(e);
		fin.close();
		return true;
	}
