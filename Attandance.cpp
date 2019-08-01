	void Attendance(string user)
	{
		for (int i = 0; i < employee.size(); i++)
		{
			if (employee[i].User == user)
			{
				employee[i].Bonus++;
				break;
			}
		}
		for (int i = 0; i < att.size(); i++)
		{
			if (att[i][0] == user)
			{
				att[i][D.getDay()] = "P";
				for (int j = 0; j < D.getDay(); j++)
				{
					if (att[i][j] == " ")
					{
						att[i][j] = "A";
					}
				}
				break;
			}
		}
		saveAttendance();
		saveEMP();
	}
