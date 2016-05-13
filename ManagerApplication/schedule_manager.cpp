#include "schedule_manager.h"

enum {
	CHECK_SCHEDULE = 1,
	ADD_DATE = 2,
	REGISTER_SCHEDULE = 3,
	REGISTER_PRICE = 4,
	DELETE_SCHEDULE = 5,
};

ScheduleManager::ScheduleManager(DBHelper& dbHelper)
{
	this->dbHelper = dbHelper;
	
	for (;;) 
	{
		system("cls");
		cout <<
			"극장 관리 시스템\n"
			" > 상영 일정 관리\n\n"

			"1. 일정 확인 / 삭제\n"
			"2. 상영일 추가\n"
			"3. 일정 등록\n"
			"4. 가격 등록\n"
			"0. 종료\n\n"

			"선택: ";

		uint16_t choice=1;
		//cin >> choice;

		switch (choice)
		{
		case FUNCTION_CANCEL:
			return;
		case CHECK_SCHEDULE:
			deleteSchedule();
		//	checkSchedule();
			break;
		case ADD_DATE:
			addDate();
			break;
		case REGISTER_SCHEDULE:
			registerSchedule();
			break;
		case REGISTER_PRICE:
			break;
		//case DELETE_SCHEDULE:
		//	deleteSchedule();
		//	break;
		default:
			cout << "\n잘못된 입력입니다."
				"\n계속하려면 아무 키나 누르십시오...";
			_getch();
			break;
		}
	}
}
