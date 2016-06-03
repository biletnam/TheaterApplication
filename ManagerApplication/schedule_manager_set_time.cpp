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

		schedule.showTime();
		if (0 < schedule.getStartTime())
		{
			cout << endl;
		}
		
		if (0 != schedule.getStartTime()
			&& 0 != schedule.getEndTime())
		{
			return;
		}

		switch (schedule.inputTime())
		{
		case FUNCTION_CANCEL:
			return;
		case FUNCTION_ERROR:
			cout << "\n�߸��� �Է��Դϴ�.\n";
			system("pause");
		}
	}
}