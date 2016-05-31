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

		if (0 != date.getValue())
		{
			date.modify(MODIFY_DELETE);
		}
		else
		{
			Date::getToday().bindParameter();
			if (SQL_SUCCESS != date.prepare(MDF_THEATER, L"SELECT date FROM schedule WHERE date>?;"))
			{
				cout << "\n오류가 발생했습니다(checkSchedule).\n";
				system("pause");
				return;
			}

			date.bindCol();
			switch (date.choose(MDF_THEATER))
			{
			case FUNCTION_NULL:
				cout << "등록된 상영 예정일이 없습니다\n";
				system("pause");
			case FUNCTION_CANCEL:
				return;
			case FUNCTION_ERROR:
				date.setValue(0);
			}
		}
	}
}