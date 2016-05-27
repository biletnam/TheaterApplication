#include "schedule_manager.h"

ScheduleManager::ScheduleManager(DBHelper &dbHelper) : dbHelper(dbHelper)
{
	enum ScheduleManagerFunction
	{
		CHECK_N_DELETE_DATE = 1,
		ADD_DATE,
		CHECK_N_MODIFY_SCHEDULE,
		REGISTER_SCHEDULE,
	};
	
	for (;;) 
	{
		system("cls");
		cout <<
			"극장 관리 시스템\n"
			" > 상영 일정 관리\n"
			"\n"
			"1. 상영일 확인/삭제\n"
			"2. 상영일 추가\n"
			"3. 상영 일정 확인/수정\n"
			"4. 상영 일정 등록\n"
			"0. 종료\n"
			"\n"
			"선택: ";


		switch (inputInteger())
		{
		case CHECK_N_DELETE_DATE:
			checkAndDeleteDate();
			break;
		case ADD_DATE:
			addDate();
			break;
		case CHECK_N_MODIFY_SCHEDULE:
			checkAndModifySchedule();
			break;
		case REGISTER_SCHEDULE:
			registerSchedule();
			break;
		case FUNCTION_CANCEL:
			return;
		default:
			cout << "\n잘못된 입력입니다.";
			system("pause");
		}
	}
}
