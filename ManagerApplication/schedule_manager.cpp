#include "schedule_manager.h"

enum {
	CHECK_SCHEDULE = 1,
	ADD_DATE = 2,
	REGISTER_SCHEDULE = 3,
	REGISTER_PRICE = 4,
};

ScheduleManager::ScheduleManager(DBHelper &dbHelper) : dbHelper(dbHelper)
{
	this->dbHelper = dbHelper;
	
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

		int16_t choice = CHECK_SCHEDULE;
		//cin >> choice;

		switch (choice)
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
			cin.clear();
			cin.ignore(100, '\n');
			cout << "\n잘못된 입력입니다.";
			system("pause");
			break;
		}
	}
}
