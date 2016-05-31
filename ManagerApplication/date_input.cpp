#include "date.h"

FNRETURN Date::input()
{
	if (0 == getYear())
	{
		return input(DATE_YEAR);
	}
	else if (0 == getMonth())
	{
		switch (input(DATE_MONTH))
		{
		case FUNCTION_CANCEL:
			setYear(0);
		case FUNCTION_SUCCESS:
			return FUNCTION_SUCCESS;
		case FUNCTION_ERROR:
			return FUNCTION_ERROR;
		}
	}
	else if (0 == getDay())
	{
		switch (input(DATE_DAY))
		{
		case FUNCTION_CANCEL:
			setMonth(0);
		case FUNCTION_SUCCESS:
			return FUNCTION_SUCCESS;
		case FUNCTION_ERROR:
			return FUNCTION_ERROR;
		}
	}
}

FNRETURN Date::input(DateType type)
{
	switch (type)
	{
	case DATE_YEAR:
		cout << "\n연도를 입력하세요(0을 입력하면 종료): ";
		break;
	case DATE_MONTH:
		cout << "\n월을 입력하세요(0을 입력하면 종료): ";
		break;
	case DATE_DAY:
		cout << "\n일을 입력하세요(0을 입력하면 종료): ";
	}
	
	int32_t value = 0;
	switch (inputPositiveInteger(value))
	{
	case FUNCTION_SUCCESS:
		if (FUNCTION_SUCCESS == set(type, value))
		{
			return FUNCTION_SUCCESS;
		}
	case FUNCTION_ERROR:
		cout << "\n잘못된 입력입니다."; 
		switch (type)
		{
		case DATE_YEAR:
			cout << "(0보다 크거나 같은 정수를 입력하세요)\n";
			break;
		case DATE_MONTH:
			cout << "(0~12 사이의 정수를 입력하세요)\n";
			break;
		case DATE_DAY:
			cout << "(0~" << getLastDay() << " 사이의 정수를 입력하세요)\n";
		}
		system("pause");
		return FUNCTION_ERROR;
	case FUNCTION_CANCEL:
		return FUNCTION_CANCEL;
	}
}