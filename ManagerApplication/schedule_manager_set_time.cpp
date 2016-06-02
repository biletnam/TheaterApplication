#include "schedule_manager.h"

void ScheduleManager::setTime(Schedule &schedule)
{
	for (;;)
	{
		system("cls");
		cout <<
			"극장 관리 시스템\n"
			" > 상영 일정 관리\n"
			"  > 상영 일정 등록\n"
			"   > 시간 설정\n"
			"\n";

		if (0 != schedule.time.getStartTime()
			&& 0 != schedule.time.getEndTime())
		{
			return;
		}
		else if (FUNCTION_CANCEL == schedule.inputTime())
		{
			return;
		}
	}
}