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
			"상영 일정 관리\n"
			"확인(1), 상영일 추가(2), 일정 등록(3), 가격 등록(4), 일정 삭제(5), 종료(0): ";
		uint16_t choice;
		cin >> choice;

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
		case DELETE_SCHEDULE:
			deleteSchedule();
			break;
		
		default:
			cout << "\n잘못된 입력입니다."
				"\n계속하려면 아무 키나 누르십시오...";
			_getch();
			break;
		}
	}
}
