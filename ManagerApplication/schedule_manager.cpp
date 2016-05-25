#include "schedule_manager.h"

ScheduleManager::ScheduleManager(DBHelper &dbHelper) : dbHelper(dbHelper)
{
	enum ScheduleManagerFunction
	{
		CHECK_SCHEDULE = 1,
		ADD_DATE,
		REGISTER_SCHEDULE,
		REGISTER_PRICE,
	};
	
	for (;;) 
	{
		system("cls");
		cout <<
			"극장 관리 시스템\n"
			" > 상영 일정 관리\n\n"

			"1. 상영 일정 확인 / 수정\n"
			"2. 상영일 추가\n"
			"3. 일정 등록\n"
			"4. 가격 등록\n"
			"0. 종료\n\n"

			"선택: ";


		switch (inputInteger())
		{
		case FUNCTION_CANCEL:
			return;
		case CHECK_SCHEDULE:
			checkSchedule();
			break;
		case ADD_DATE:
			addDate();
			break;
		case REGISTER_SCHEDULE:
			registerSchedule();
			break;
		case REGISTER_PRICE:
			break;
		default:
			cout << "\n잘못된 입력입니다.";
			system("pause");
		}
	}
}
