#include "schedule_manager.h"

void ScheduleManager::setDate(Date &date)
{
	system("cls");
	cout <<
		"극장 관리 시스템\n"
		" > 상영 일정 관리\n"
		"  > 상영 일정 등록\n"
		"   > 날짜 설정\n";

	if (SQL_SUCCESS != date.prepare(MDF_THEATER, L"SELECT date_value FROM date;")
		|| SQL_SUCCESS != date.bindCol())
	{
		cout << "\n오류가 발생했습니다(setDate).\n";
		system("pause");
	}
	else if (FUNCTION_NULL == date.choose(MDF_THEATER))
	{
		cout << "\n등록 가능한 상영일이 없습니다\n";
		system("pause");
	}
}