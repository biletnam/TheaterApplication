#include "Date.h"

FNRETURN Date::inputYear()
{
	cout << "연도를 입력하세요(0을 입력하면 종료):";
	const FNRETURN year = inputInteger();

	if (true == setYear(inputInteger()))
	{
	}

	switch (year)
	{
	case FUNCTION_ERROR:
		cout << "\n잘못된 입력입니다.(0보다 크거나 같은 정수를 입력하세요)\n";
		system("pause");
		return FUNCTION_ERROR;
	case FUNCTION_CANCEL:
		return FUNCTION_CANCEL;
	default:
		setYear(year);
		return FUNCTION_SUCCESS;
	}
}

FNRETURN Date::inputMonth()
{
	cout << "월을 입력하세요(0을 입력하면 종료):";
	const FNRETURN month = inputInteger();

	switch (month)
	{
	case FUNCTION_ERROR:
		break;
	case FUNCTION_CANCEL:
		return FUNCTION_CANCEL;
	default:
		if (12 >= month)
		{
			setMonth(month);
			return FUNCTION_SUCCESS;
		}
	}

	cout << "\n잘못된 입력입니다.(0~12 사이의 정수를 입력하세요)\n";
	system("pause");
	return FUNCTION_ERROR;
}

FNRETURN Date::inputDay()
{
	cout << "월을 입력하세요(0을 입력하면 종료):";
	const FNRETURN day = inputInteger();
	
	int8_t lastDay = 31;
	switch (getMonth())
	{
	case 4:case 6:case 9:case 11:
		lastDay = 30;
	case 2:
		(isLeapYear(getYear()) == true) ? lastDay = 29 : lastDay = 28;
	}

	switch (day)
	{
	case FUNCTION_ERROR:
		break;
	case FUNCTION_CANCEL:
		return FUNCTION_CANCEL;
	default:
		if (lastDay >= day)
		{
			setDay(day);
			return FUNCTION_SUCCESS;
		}
	}

	cout << "\n잘못된 입력입니다.(0~"<< lastDay <<" 사이의 정수를 입력하세요)\n";
	system("pause");
	return FUNCTION_ERROR;
}
