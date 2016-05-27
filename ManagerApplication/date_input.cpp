#include "Date.h"

FNRETURN Date::inputYear()
{
	cout << "������ �Է��ϼ���(0�� �Է��ϸ� ����):";
	const FNRETURN year = inputInteger();

	if (true == setYear(inputInteger()))
	{
	}

	switch (year)
	{
	case FUNCTION_ERROR:
		cout << "\n�߸��� �Է��Դϴ�.(0���� ũ�ų� ���� ������ �Է��ϼ���)\n";
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
	cout << "���� �Է��ϼ���(0�� �Է��ϸ� ����):";
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

	cout << "\n�߸��� �Է��Դϴ�.(0~12 ������ ������ �Է��ϼ���)\n";
	system("pause");
	return FUNCTION_ERROR;
}

FNRETURN Date::inputDay()
{
	cout << "���� �Է��ϼ���(0�� �Է��ϸ� ����):";
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

	cout << "\n�߸��� �Է��Դϴ�.(0~"<< lastDay <<" ������ ������ �Է��ϼ���)\n";
	system("pause");
	return FUNCTION_ERROR;
}
