#include "date.h"

FNRETURN Date::set(DateType type, const int16_t value)
{
	switch (type)
	{
	case Date::DATE_YEAR:
		if (0 <= value)
		{
			this->value = 
				(value * 10000)				// year
				+ (this->value % 10000);	// month, day
			return FUNCTION_SUCCESS;
		}
		break;
	case Date::DATE_MONTH:
		if (0 <= value && 12 >= value)
		{
			this->value = 
				(this->value / 10000 * 10000)	// year
				+ (value * 100) 				// month
				+ (this->value % 100);			// day
			return FUNCTION_SUCCESS;
		}
		break;
	case Date::DATE_DAY:
		if (0 <= value && getLastDay() >= value)
		{
			this->value = 
				(this->value / 100 * 100)	// year, month
				+ value;					// day
			return FUNCTION_SUCCESS;
		}
	}

	return FUNCTION_ERROR;
}

FNRETURN Date::setYear(const int16_t year)
{
	if (0 <= year)
	{
		value = (year * 10000)	// year
			+ (value % 10000);	// month, day
		return FUNCTION_SUCCESS;
	}
	else
	{
		return FUNCTION_ERROR;
	}

}

FNRETURN Date::setMonth(const int16_t month)
{
	if (0 <= month && 12 >= month)
	{
		value = (value / 10000 * 10000)	// year
			+ (month * 100) 			// month
			+ (value % 100);			// day
		return FUNCTION_SUCCESS;
	}
	else
	{
		return FUNCTION_ERROR;
	}
}

FNRETURN Date::setDay(const int16_t day)
{
	if (0 <= day && getLastDay() >= day)
	{
		value = (value / 100 * 100)	// year, month
			+ day;					// day
		return FUNCTION_SUCCESS;
	}
	else
	{
		return FUNCTION_ERROR;
	}
}

FNRETURN Date::setValue(const int32_t value)
{
	this->value = value;

	return FNRETURN();
}