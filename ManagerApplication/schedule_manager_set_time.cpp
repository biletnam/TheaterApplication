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

		if (0 != schedule.getStartTime()
			&& 0 != schedule.getEndTime())
		{
			return;
		}
		else if (FUNCTION_CANCEL == schedule.inputTime())
		{
			return;
		}
	}
}