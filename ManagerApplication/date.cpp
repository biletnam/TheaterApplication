#include "Date.h"

Date Date::getToday()
{
	struct tm t;
	time_t timer = time(NULL);

	localtime_s(&t, &timer);

	return Date(
		(t.tm_year - 100) * 10000	// year
		+ (t.tm_mon + 1) * 100		// month
		+ t.tm_mday);				// day
}

int16_t Date::getYear() const
{
	return value / 10000;
}

int16_t Date::getMonth() const
{
	return (value % 10000) / 100;
}

int16_t Date::getLastDay()
{
	switch (getMonth())
	{
	case 4:case 6:case 9:case 11:
		return 30;
	case 2:
		return (isLeapYear(getYear()) == true) ? 29 : 28;
	default:
		return 31;
	}
	
}

int16_t Date::getDay() const
{
	return (value % 100);
}

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

int32_t Date::getValue() const
{
	return value;
}

void Date::show() const
{
	if (0 != getYear())
	{
		cout << getYear() << "³â ";
	}

	if (0 != getMonth())
	{
		cout << getMonth() << "¿ù ";
	}

	if (0 != getDay())
	{
		cout << getDay() << "ÀÏ";
	}
}