#include "schedule_manager.h"

void ScheduleManager::setTime(Schedule &schedule)
{
	for (;;)
	{
		system("cls");
		cout <<
			"���� ���� �ý���\n"
			" > �� ���� ����\n"
			"  > �� ���� ���\n"
			"   > �ð� ����\n"
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