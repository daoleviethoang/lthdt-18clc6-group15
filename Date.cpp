#include "Date.h"

Date::Date()
{
	dd = 0;
	mm = 0;
	yyyy = 0;
}

Date::Date(int day, int month, int year)
{
	dd = day;
	mm = month;
	yyyy = year;
}

void Date::input(unsigned int day, unsigned int month, unsigned int year)
{
	dd = day;
	mm = month;
	yyyy = year;
}

void Date::output()
{
	cout << dd << "." << mm << "." << yyyy << endl;
}

bool Date::checkDate()
{
	if (dd <= 0 || mm <= 0 || yyyy <= 0)
		return false;
	switch (mm)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
	{
		if (dd > 31)
			return false;
		else return true;
	}
	case 4:
	case 6:
	case 9:
	case 11:
	{
		if (dd > 30)
			return false;
		else return true;
	}
	case 2:
	{
		if ((yyyy % 4 == 0 && yyyy % 100 != 0) || (yyyy % 100 == 0 && yyyy % 400 == 0))
		{
			if (dd > 29)
				return false;
			else return true;
		}
		else
		{
			if (dd > 28)
				return false;
			else return true;
		}
	}
	default: return false;
	}
}

Date Date::increase1()
{
	Date d;
	d.dd = dd;
	d.mm = mm;
	d.yyyy = yyyy;
	switch (mm)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
	{
		if (dd < 31)
		{
			d.dd = dd + 1;
			return d;
		}
		else
		{
			d.dd = 1;
			if (mm == 12)
			{
				d.mm = 1;
				d.yyyy = yyyy + 1;
				return d;
			}
			else
			{
				d.mm = mm + 1;
				return d;
			}
		}
	}
	case 4:
	case 6:
	case 9:
	case 11:
	{
		if (dd < 30)
		{
			d.dd = dd + 1;
			return d;
		}
		else
		{
			d.dd = 1;
			d.mm = mm + 1;
			return d;
		}
	}
	case 2:
	{
		if ((yyyy % 4 == 0 && yyyy % 100 != 0) || (yyyy % 100 == 0 && yyyy % 400 == 0))
		{
			if (dd < 29)
			{
				d.dd = dd + 1;
				return d;
			}
			else
			{
				d.dd = 1;
				d.mm = mm + 1;
				return d;
			}
		}
		else
		{
			if (dd < 28)
			{
				d.dd = dd+ 1;
				return d;
			}
			else
			{
				d.dd = 1;
				d.mm = mm + 1;
				return d;
			}
		}
	}
	}
}

Date Date::decrease1()
{
	Date d;
	d.dd = dd;
	d.mm = mm;
	d.yyyy = yyyy;
	switch (mm)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
	{
		if (dd > 1)
		{
			d.dd = dd - 1;
			return d;
		}
		else
		{
			if (d.mm != 8 && d.mm != 1 && d.mm != 3)
			{
				d.dd = 30;
				d.mm = mm - 1;
				return d;
			}
			else if (d.mm == 8)
			{
				d.dd = 31;
				d.mm = 7;
				return d;
			}
			else if (d.mm == 1)
			{
				d.dd = 31;
				d.mm = 12;
				d.yyyy = yyyy - 1;
				return d;
			}
			else if (d.mm == 3)
			{
				if ((yyyy % 4 == 0 && yyyy % 100 != 0) || (yyyy % 100 == 0 && yyyy % 400 == 0))
				{
					d.dd = 29;
					d.mm = 2;
					return d;
				}
				else
				{
					d.dd = 28;
					d.mm = 2;
					return d;
				}
			}
		}

	}
	case 4:
	case 6:
	case 9:
	case 11:
	{
		if (dd > 1)
		{
			d.dd = dd - 1;
			return d;
		}
		else
		{
			d.dd = 31;
			d.mm = mm - 1;
			return d;
		}
	}
	case 2:
	{
		if (dd > 1)
		{
			d.dd = dd - 1;
			return d;
		}
		else
		{
			d.dd = 31;
			d.mm = 1;
			return d;
		}
	}
	}
}

Date Date::increase(int n)
{
	Date d;
	d.dd = dd + n;
	d.mm = mm;
	d.yyyy = yyyy;
	switch (mm)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
	{
		if (d.dd <= 31)
		{
			return d;
		}
		else
		{
			d.dd = d.dd - 31;
			if (d.dd <= 31)
			{
				if (mm == 12)
				{
					d.mm = 1;
					d.yyyy = yyyy + 1;
					return d;
				}
				else
				{
					d.mm = mm + 1;
					return d;
				}
			}
			else
			{
				d.mm = mm + 1;
				while (d.dd > 31)
				{
					d.dd -= 31;
					if (d.mm == 12)
					{
						d.mm = 1;
						d.yyyy = yyyy + 1;
					}
					else d.mm = mm + 1;
				}
				return d;
			}

		}
	}
	case 4:
	case 6:
	case 9:
	case 11:
	{
		if (d.dd <= 30)
		{
			return d;
		}
		else
		{
			d.dd = d.dd - 30;
			if (d.dd <= 30)
			{
				d.mm = mm + 1;
				return d;
			}
			else
			{
				d.mm = mm + 1;
				while (d.dd >= 31)
				{
					d.dd -= 31;
					if (d.mm == 12)
					{
						d.mm = 1;
						d.yyyy = yyyy + 1;
					}
					else d.mm = mm + 1;
				}
				return d;
			}
		}
	}
	case 2:
	{
		if ((yyyy % 4 == 0 && yyyy % 100 != 0) || (yyyy % 100 == 0 && yyyy % 400 == 0))
		{
			if (d.dd <= 29)
			{
				return d;
			}
			else
			{
				d.dd = d.dd - 29;	
				if (d.dd <= 29)
				{
					d.mm = mm + 1;
					return d;
				}
				else
				{
					d.mm = mm + 1;
					while (d.dd >= 31)
					{
						d.dd -= 31;
						if (d.mm == 12)
						{
							d.mm = 1;
							d.yyyy = yyyy + 1;
						}
						else d.mm = mm + 1;
					}
					return d;
				}
			}
		}
		else
		{
			if (dd <= 28)
			{
				return d;
			}
			else
			{
				d.dd = d.dd - 28;	
				if (d.dd <= 28)
				{
					d.mm = mm + 1;
					return d;
				}
				else
				{
					d.mm = mm + 1;
					while (d.dd >= 31)
					{
						d.dd -= 31;
						if (d.mm == 12)
						{
							d.mm = 1;
							d.yyyy = yyyy + 1;
						}
						else d.mm = mm + 1;
					}
					return d;
				}
			}
		}
	}
	}
}

Date Date::decrease(int n)
{
	Date d;
	d.dd = dd - n;
	d.mm = mm;
	d.yyyy = yyyy;
	switch (mm)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
	{
		if (d.dd >= 1)
		{
			return d;
		}
		else
		{
			if (dd > 0)
			{
				if (d.mm != 8 && d.mm != 1 && d.mm != 3)
				{
					d.dd = 30 + d.dd;
					d.mm = mm - 1;
					return d;
				}
				else if (d.mm == 8)
				{
					d.dd = 31 + d.dd;
					d.mm = 7;
					return d;
				}
				else if (d.mm == 1)
				{
					d.dd = 31 + d.dd;
					d.mm = 12;
					d.yyyy = yyyy - 1;
					return d;
				}
				else if (d.mm == 3)
				{
					if ((yyyy % 4 == 0 && yyyy % 100 != 0) || (yyyy % 100 == 0 && yyyy % 400 == 0))
					{
						d.dd = 29 + d.dd;
						d.mm = 2;
						return d;
					}
					else
					{
						d.dd = 28 + d.dd;
						d.mm = 2;
						return d;
					}
				}
			}
			else
			{
				d.mm -= 1;
				while (d.dd < 0)
				{
					d.dd += 30;
					if (d.mm == 1)
					{
						d.mm = 12;
						d.yyyy -= 1;
					}
					else d.mm -= 1;
				}
			}
		}

	}
	case 4:
	case 6:
	case 9:
	case 11:
	{
		if (d.dd > 0)
		{
			if (d.dd >= 1)
			{
				return d;
			}
			else
			{
				d.dd = 31 + d.dd;
				d.mm = mm - 1;
				return d;
			}
		}
		else
		{
			d.mm -= 1;
			while (d.dd < 0)
			{
				d.dd += 30;
				if (d.mm == 1)
				{
					d.mm = 12;
					d.yyyy -= 1;
				}
				else d.mm -= 1;
			}
		}
	}
	case 2:
	{
		if (d.dd > 0)
		{
			if (d.dd >= 1)
			{
				return d;
			}
			else
			{
				d.dd = 31 + d.dd;
				d.mm = 1;
				return d;
			}
		}
		else
		{
			d.mm -= 1;
			while (d.dd < 0)
			{
				d.dd += 30;
				if (d.mm == 1)
				{
					d.mm = 12;
					d.yyyy -= 1;
				}
				else d.mm -= 1;
			}
		}
	}
	}
}

int Date::compare(Date a)
{
	if (yyyy > a.yyyy)
		return 1;
	else if (yyyy < a.yyyy)
		return -1;
	if (mm > a.mm)
		return 1;
	else if (mm < a.mm)
		return -1;
	if (dd > a.dd)
		return 1;
	else if (dd < a.dd)
		return -1;
	else return 0;
}

long Date::distance()
{
	long result = dd;
	for (int i = mm - 1; i >= 1; i--)
	{
		switch (i)
		{

		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
		{
			result += 31; break;
		}
		case 4:
		case 6:
		case 9:
		case 11:
		{
			result += 30; break;
		}
		case 2:
		{
			if ((yyyy % 4 == 0 && yyyy % 100 != 0) || (yyyy % 100 == 0 && yyyy % 400 == 0))
			{
				result += 29; break;
			}
			else
			{
				result += 28; break;
			}
		}
		}
	}
	for (int j = yyyy - 1; j >= 1; j--)
	{
		if ((yyyy % 4 == 0 && yyyy % 100 != 0) || (yyyy % 100 == 0 && yyyy % 400 == 0))
			result += 366;
		else result += 365;
	}
	return result;
}

long Date::distanceGY()
{
	int result = dd;
	for (int i = mm - 1; i >= 1; i--)
	{
		switch (i)
		{

		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
		{
			result += 31; break;
		}
		case 4:
		case 6:
		case 9:
		case 11:
		{
			result += 30; break;
		}
		case 2:
		{
			if ((yyyy % 4 == 0 && yyyy % 100 != 0) || (yyyy % 100 == 0 && yyyy % 400 == 0))
			{
				result += 29; break;
			}
			else
			{
				result += 28; break;
			}
		}
		}
	}
	return result;
}