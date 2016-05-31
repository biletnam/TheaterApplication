#include "schedule_manager.h"

void ScheduleManager::checkAndDeleteDate()
{
	Date date;
	for (;;)
	{
		system("cls");
		cout <<
			"극장 관리 시스템\n"
			" > 상영 일정 관리\n"
			"  > 상영일 확인/삭제\n";

		if (0 < date.getValue())
		{
			cout << "\n선택한 날짜 정보:\n";
			date.show();
			switch (date.modify(MODIFY_DELETE))
			{
			case FUNCTION_SUCCESS:
			case FUNCTION_CANCEL:
				date.initialize();
			}
		}
		else
		{
			Date::getToday().bindParameter();
			if (SQL_SUCCESS != date.prepare(L"SELECT date FROM schedule WHERE date>?;"))
			{
				cout << "\n오류가 발생했습니다(checkSchedule).\n";
				system("pause");
				return;
			}

			date.bindCol();
			switch (date.choose())
			{
			case FUNCTION_CANCEL:
				return;
			case FUNCTION_NULL:
				cout << "등록된 상영 예정일이 없습니다\n";
				system("pause");
			}
		}
	}
}