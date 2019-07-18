#pragma once
#include "PERSON.h"
#include "MEDICINE.h"
class EMPLOYEE:public PERSON
{
private:
	vector<MEDICINE> MDC;
	double m_Salary;
	double m_Bonus;
public:
	EMPLOYEE()
	{
		m_Salary = 0;
		m_Bonus = 0;
	}
	void addMedicine(string &name, string &form, float &price, int &status)
	{
		if (loadMedicine())
		{
			int a = 0;
			MEDICINE md;
			cin.get();
			cout << "Enter Name: ";
			getline(cin, name);
			cout << "Enter Form: ";
			getline(cin, form);
			cout << "Enter Price: ";
			cin >> price;
			cout << "Enter Status: ";
			cin >> status;
			a = MDC.size();
			md = MEDICINE::MEDICINE(++a,name, form, price, status);
			MDC.push_back(md);
			saveMedicine();
		}
	}
	bool loadMedicine()
	{
		ifstream fin;
		fin.open("MedicineInformation.csv");
		if (!fin.is_open())
			return false;
		int no, status;
		string name, form, a;
		float price;
		MEDICINE md;
		int i = 0;
		getline(fin, a, '\n');
		while (!fin.eof())
		{
			fin >> no;
			fin.get();
			getline(fin, name, ',');
			getline(fin, form, ',');
			fin >> price;
			fin.get();
			fin >> status;
			fin.get();
			md = MEDICINE::MEDICINE(no, name, form, price, status);
			MDC.push_back(md);
		}
		fin.close();
		return true;
	}
	bool saveMedicine()
	{
		ofstream fout;
		fout.open("test.csv");
		if (!fout.is_open())
			return false;
		fout << "No,Name,Form,Price,Status" << endl;
		for (int i = 0; i < MDC.size(); i++)
		{
			fout << MDC[i].getNo() << "," << MDC[i].getName() << "," << MDC[i].getForm() << "," << MDC[i].getPrice() << "," << MDC[i].getStatus() << endl;
		}
		fout.close();
		return true;
	}
	void viewInforGoods()
	{
		if (loadMedicine())
		{
			cout << "No,Name,Form,Price,Status" << endl;
			for (int i = 0; i < MDC.size(); i++)
			{
				cout << MDC[i].getNo() << "," << MDC[i].getName() << "," << MDC[i].getForm() << "," << MDC[i].getPrice() << "," << MDC[i].getStatus() << endl;

			}
		}
		else
		{
			cout << "Sorry, No information found!!!" << endl;
		}
	}
	void editInforGoods()
	{
		if (loadMedicine())
		{
			string a;
			int b = 0;
			int c = 0;
			cout << "Enter the name of the medicine you want to edit: ";
			getline(cin, a);
			for (int i = 0; i < MDC.size(); i++)
			{
				if (a == MDC[i].getName())
				{
					do
					{
						cout << "1: Edit Name" << endl;
						cout << "2: Edit Form" << endl;
						cout << "3: Edit Price" << endl;
						cout << "4: Edit Status" << endl;
						cout << "Select: ";
						cin >> b;
						switch (b)
						{
						case 1:
						{
							string name;
							string temp;
							cout << "New Name: ";
							cin >> name;
							cin.get();
							if (MDC[i].editName(name))
							{
								cout << "Edit a Name successfull!!!" << endl;
								cout << "Would you like to continue editing?(yes/no)" << endl;
								getline(cin, temp);
								if (temp == "yes")
								{
									c = 1;
									break;
								}
								else
								{
									break;
								}
							}
						}
						case 2:
						{
							string form;
							string temp;
							cout << "New Form: ";
							cin >> form;
							if (MDC[i].editForm(form))
							{
								cout << "Edit a Form successfull!!!" << endl;
								if (temp == "yes")
								{
									c = 1;
									break;
								}
								else
								{
									break;
								}
							}
						}
						case 3:
						{
							float price;
							string temp;
							cout << "New Price: ";
							cin >> price;
							if (MDC[i].editPrice(price))
							{
								cout << "Edit a Price successfull!!!" << endl;
								if (temp == "yes")
								{
									c = 1;
									break;
								}
								else
								{
									break;
								}
							}
							
						}
						case 4:
						{
							int status;
							string temp;
							cout << "New Status: ";
							cin >> status;
							if (MDC[i].editStatus(status))
							{
								cout << "Edit a Status successfull!!!" << endl;
								if (temp == "yes")
								{
									c = 1;
									break;
								}
								else
								{
									break;
								}
							}
							
						}
						default:
							break;
						}
					} while (c == 1);
				}
			}
		}
	}

	void Attendance()
	{
		//
	}
	void viewCalendar()
	{

	}
	void addCustomer()
	{

	}
	void viewCustomer()
	{

	}
	void editCustomer()
	{

	}
	void seachHistory()
	{

	}
	void Listed()
	{

	}
	void Ranking()
	{

	}
};
