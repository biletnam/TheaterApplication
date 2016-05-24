#include "schedule_manager.h"

enum
{
	DELETE_SCHEDULE = 1,
	DELETE_PRICE = 2,
	REGISTER_PRICE = 3,
};

FNRETURN ScheduleManager::modifySchedule(Schedule &schedule)
{
	system("cls");
	cout <<
		"극장 관리 시스템\n"
		" > 상영 일정 관리\n"
		"  > 상영 일정 확인/수정\n\n"
		
		"선택한 상영 일정\n";
	schedule.showInfo();
	
	cout << "\n"
		"1. 상영 일정 삭제\n"
		"2. 가격 정보 확인/수정\n"
		"3. 가격 등록\n"
		"0. 종료\n\n"

		"선택: ";

	int16_t choice;
	cin >> choice;

	switch (choice)
	{
	case FUNCTION_CANCEL:
		return FUNCTION_CANCEL;
	case DELETE_SCHEDULE:
		return schedule.del();
	case DELETE_PRICE:
		deletePrice(schedule);
		break;
	case REGISTER_PRICE:
		registerPrice(schedule);
		break;
	default:
		cin.clear();
		cin.ignore(100, '\n');
		cout << "\n잘못된 입력입니다.\n";
		system("pause");
	}

	return FUNCTION_ERROR;
}
