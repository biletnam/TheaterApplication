#include "date.h"

FNRETURN Date::set(DateType type, const int16_t value)
{
	switch (type)
	{
	case DATE_YEAR:
		if (0 <= value)
		{
			this->value = 
				(value * 10000)				// year
				+ (this->value % 10000);	// month, day
			return FUNCTION_SUCCESS;
		}
		break;
	case DATE_MONTH:
		if (0 <= value && 12 >= value)
		{
			this->value = 
				(this->value / 10000 * 10000)	// year
				+ (value * 100) 				// month
				+ (this->value % 100);			// day
			return FUNCTION_SUCCESS;
		}
		break;
	case DATE_DAY:
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