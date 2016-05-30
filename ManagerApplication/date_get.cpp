#include "date.h"

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