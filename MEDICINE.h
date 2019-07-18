#pragma once
#include "DATE.h"
class MEDICINE
{
private:
	int No;
	string Name;
	string Form;
	float Price;
	int Status;
public:
	MEDICINE()
	{
		No = 0;
		Name = "";
		Form = "";
		Price = 0;
		Status = 0;
	}
	MEDICINE(int no, string name, string form, float price, int status)
	{
		No = no;
		Name = name;
		Form = form;
		Price = price;
		Status = status;
	}
	int getNo()
	{
		return No;
	}
	string getName()
	{
		return Name;
	}
	string getForm()
	{
		return Form;
	}
	float getPrice()
	{
		return Price;
	}
	int getStatus()
	{
		return Status;
	}
	bool editName(string name)
	{
		Name = name;
		return true;
	}
	bool editForm(string form)
	{
		Form = form;
		return true;
	}
	bool editPrice(float price)
	{
		Price = price;
	}
	bool editStatus(int status)
	{
		Status = status;
	}
};