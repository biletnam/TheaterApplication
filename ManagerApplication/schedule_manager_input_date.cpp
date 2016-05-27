#include "schedule_manager.h"

FNRETURN ScheduleManager::inputDate(Date &date)
{
	system("cls");
	cout <<
		"극장 관리 시스템\n"
		" > 상영 일정 관리\n"
		"  > 상영일 추가\n"
		"\n"
		"추가할 날짜: ";
	date.show();
	cout << endl;

	if (0 != date.getDay())
	{
		return FUNCTION_SUCCESS;
	}
	else if (0 == date.getYear())
	{
		cout << "연도를 입력하세요(0을 입력하면 종료):";

		if (false == date.setYear(inputInteger()))
		{
			cout << "\n잘못된 입력입니다.(0보다 크거나 같은 정수를 입력하세요)\n";
			system("pause");
		}
		else if (0 == date.getYear())
		{
			return FUNCTION_CANCEL;
		}
	}
	else if (0 == date.getMonth())
	{
		cout << "월을 입력하세요(0을 입력하면 종료):";

		if (false == date.setMonth(inputInteger()))
		{
			cout << "\n잘못된 입력입니다.(0~12 사이의 정수를 입력하세요)\n";
			system("pause");
		}
		else if (0 == date.getMonth())
		{
			date.setYear(0);
		}
	}
	else
	{
		cout << "일을 입력하세요(0을 입력하면 종료):";

		if (false == date.setMonth(inputInteger()))
		{
			cout << "\n잘못된 입력입니다.(0~" << date.getLastDay() << " 사이의 정수를 입력하세요)\n";
			system("pause");
		}
		else if (0 == date.getDay())
		{
			date.setMonth(0);
		}
	}

	return inputDate(date);
}