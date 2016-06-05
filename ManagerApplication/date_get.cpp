#include "date.h"

int16_t Date::get(DateType type) const
{
	switch (type)
	{
	case DATE_YEAR:
		return value / 10000;
	case DATE_MONTH:
		return (value % 10000) / 100;
	case DATE_DAY:
	default:
		return (value % 100);
	}
}

int16_t Date::getLastDay() const
{
	switch (get(DATE_MONTH))
	{
	case 4:case 6:case 9:case 11:
		return 30;
	case 2:
		return (isLeapYear(get(DATE_YEAR)) == true) ? 29 : 28;
	default:
		return 31;
	}

}

Date Date::getToday()
{
	struct tm t;
	time_t timer = time(NULL);

	localtime_s(&t, &timer);

	Date date;
	date.set(DATE_YEAR, t.tm_year + 1900);	// year
	date.set(DATE_MONTH, t.tm_mon + 1);		// month
	date.set(DATE_DAY, t.tm_mday + 1);		// day

	return date;
}

bool Date::isLeapYear(const int16_t year) const
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