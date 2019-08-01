	void changePassword(int i)
	{
		int flag = 0;
		char check[30];
		char a[50], b[50];
		do
		{
			cout << "Enter your old password: ";
			inputpassword(check);
			if (check == PS[i].getPass())
			{
				flag = 1;
				do
				{
					cout << "Enter new password: ";
					inputpassword(a);
					cout << "Enter new password again: ";
					inputpassword(b);
					if (strcmp(a, b) == 0)
					{
						PS[i].createPass(a);
					}
				} while ((strcmp(a, b) != 0) && cout << "It dosen't match!! Please try again" << endl);
			}
		} while (check != PS[i].getPass() && flag == 0 && cout << "Wrong!! Please do it again!" << endl);
	}
