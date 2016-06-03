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
			cout << "\n잘못된 입력입니다.\n";
			system("pause");
		}
	}
}