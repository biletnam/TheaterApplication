#include "schedule_manager.h"

void ScheduleManager::setDate(Date &date)
{
	for (;;)
	{
		system("cls");
		cout <<
			"극장 관리 시스템\n"
			" > 상영 일정 관리\n"
			"  > 상영 일정 등록\n"
			"   > 날짜 설정\n"
			"\n";

		switch (date.choose())
		{
		case FUNCTION_ERROR:
			cout << "잘못된 입력입니다.";
			system("pause");
			break;
		case FUNCTION_NULL:
			cout << "등록 가능한 상영일이 없습니다\n";
			system("pause");
		case FUNCTION_SUCCESS:
		case FUNCTION_CANCEL:
			return;
		}
	}
}