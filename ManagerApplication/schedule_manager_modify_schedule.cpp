#include "schedule_manager.h"

void ScheduleManager::modifySchedule(Schedule &schedule)
{
	enum
	{
		DELETE_SCHEDULE = 1,
		CHECK_N_DELETE_PRICE,
		REGISTER_PRICE,
	};

	for (;;)
	{
		system("cls");
		cout <<
			"극장 관리 시스템\n"
			" > 상영 일정 관리\n"
			"  > 상영 일정 확인/수정\n"
			"\n"
			"선택한 상영 일정\n";
		schedule.showInfo();

		cout << "\n"
			"1. 상영 일정 삭제\n"
			"2. 가격 정보 확인/삭제\n"
			"3. 가격 등록\n"
			"0. 종료\n"
			"\n"
			"선택: ";

		switch (inputInteger())
		{
		case DELETE_SCHEDULE:
			schedule.del();
		case CHECK_N_DELETE_PRICE:
			checkAndDeletePrice(schedule);
			break;
		case REGISTER_PRICE:
			registerPrice(schedule);
			break;
		case FUNCTION_CANCEL:
			return;
		default:
			cout << "\n잘못된 입력입니다.\n";
			system("pause");
		}
	}
}
