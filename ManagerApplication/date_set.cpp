#include "date.h"

bool Date::setYear(const int16_t year)
{
	if (0 <= year)
	{
		value = (year * 10000)	// year
			+ (value % 10000);	// month, day
		return true;
	}
	else
	{
		return false;
	}
	
}

bool Date::setMonth(const int16_t month)
{
	if (0 <= month && 12 >= month)
	{
		value = (value / 10000 * 10000)	// year
			+ (month * 100) 			// month
			+ (value % 100);			// day
		return true;
	}
	else
	{
		return false;
	}
}

bool Date::setDay(const int16_t day)
{
	if (0 <= day && getLastDay() >= day)
	{
		value = (value / 100 * 100)	// year, month
			+ day;					// day
		return true;
	}
	else
	{
		return false;
	}
}

bool Date::setValue(const int32_t value)
{
	this->value = value;
}