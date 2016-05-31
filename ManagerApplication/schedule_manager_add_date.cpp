#include "schedule_manager.h"

void ScheduleManager::addDate()
{
	Date date;
	for (;;)
	{
		system("cls");
		cout <<
			"극장 관리 시스템\n"
			" > 상영 일정 관리\n"
			"  > 상영일 추가\n";

		if (0 != date.getValue())
		{
			cout << "\n추가할 날짜 정보: \n";
			date.show();
		}

		if (0 != date.get(DATE_YEAR)
			&& 0 != date.get(DATE_MONTH)
			&& 0 != date.get(DATE_DAY))
		{
			switch (date.modify(MODIFY_INSERT))
			{
			case FUNCTION_SUCCESS:
			case FUNCTION_CANCEL:
				date.initialize();
			}
		}
		else if (FUNCTION_CANCEL == date.input())
		{
			return;
		}
	}
}