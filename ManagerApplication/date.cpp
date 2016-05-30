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

Date Date::getToday()
{
	struct tm t;
	time_t timer = time(NULL);

	localtime_s(&t, &timer);

	Date date;
	/*date.setYear(t.tm_year - 100);	// year
	date.setMonth(t.tm_mon + 1);	// month
	date.setDay(t.tm_mday + 1);		// day*/

	date.setValue(1);

	return date;
}
