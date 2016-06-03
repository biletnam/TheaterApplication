#include "schedule_manager.h"

void ScheduleManager::setScreen(Screen &screen)
{
	system("cls");
	cout <<
		"극장 관리 시스템\n"
		" > 상영 일정 관리\n"
		"  > 상영 일정 등록\n"
		"   > 상영관 설정\n";

	if (SQL_SUCCESS != screen.prepare(MDF_THEATER, L"SELECT number, row, col FROM screen;")
		|| SQL_SUCCESS != screen.bindCol())
	{
		cout << "\n오류가 발생했습니다(setScreen).\n";
		system("pause");
	}
	else if (FUNCTION_NULL == screen.choose(MDF_THEATER))
	{
		cout << "\n등록 가능한 상영관이 없습니다\n";
		system("pause");
	}
}