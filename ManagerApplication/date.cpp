#include "Date.h"

int32_t Date::getToday() const
{
	struct tm t;
	time_t timer = time(NULL);

	localtime_s(&t, &timer);

	return (t.tm_year - 100) * 10000	// year
		+ (t.tm_mon + 1) * 100			// month
		+ t.tm_mday;					// day
}

int16_t Date::getYear() const
{
	return value / 10000;
}

int16_t Date::getMonth() const
{
	return (value % 10000) / 100;
}

int16_t Date::getDay() const
{
	return (value % 100);
}

void Date::setYear(const int16_t year)
{
	value = (year * 10000)	// year
		+ (value % 10000);	// month, day
}

void Date::setMonth(const int16_t month)
{
	value = (value / 10000 * 10000)	// year
		+ (month * 100) 			// month
		+ (value % 100);			// day
}

void Date::setDay(const int16_t day)
{
	value = (value / 100 * 100)	// year, month
		+ day;					// day
}

void Date::show() const
{
	cout << getYear() << "³â "
		<< getMonth() << "¿ù "
		<< getDay() << "ÀÏ";
}