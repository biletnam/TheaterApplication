#include "date.h"

Date Date::today(DBHelper &dbHelper)
{
	struct tm t;
	time_t timer = time(NULL);

	localtime_s(&t, &timer);

	Date date(dbHelper);
	date.setYear(t.tm_year - 100);	// year
	date.setMonth(t.tm_mon + 1);	// month
	date.setDay(t.tm_mon + 1);		// day

	return date;					
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

int32_t Date::getValue() const
{
	return value;
}