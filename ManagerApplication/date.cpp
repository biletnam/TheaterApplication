#include "Date.h"

bool Date::isLeapYear(const int16_t year)
{
	if ((0 == year % 4 && 0 != year % 100) || 0 == year % 400)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Date::show() const
{
	if (0 != getYear())
	{
		cout << getYear() << "�� ";
	}

	if (0 != getMonth())
	{
		cout << getMonth() << "�� ";
	}

	if (0 != getDay())
	{
		cout << getDay() << "��";
	}
}