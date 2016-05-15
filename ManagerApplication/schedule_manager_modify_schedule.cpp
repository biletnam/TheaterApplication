#include "schedule_manager.h"

enum
{
	DELETE_SCHEDULE = 1,
	MODIFY_PRICE = 2,
};

FNRETURN ScheduleManager::modifySchedule(Schedule &schedule)
{
	system("cls");
	cout <<
		"극장 관리 시스템\n"
		" > 상영 일정 관리\n"
		"  > 상영 일정 확인 / 수정\n\n"
		
		"선택한 상영 일정\n";
	schedule.showInfo();
	
	cout << "\n"
		"1. 상영 일정 삭제\n"
		"2. 가격 정보 수정\n"
		"0. 종료\n";

	int16_t choice;
	cin >> choice;

	switch (choice)
	{
	case FUNCTION_CANCEL:
		return;
	case DELETE_SCHEDULE:
		schedule.del();
		break;
	case MODIFY_PRICE:
		break;
	default:
		cin.clear();
		cin.ignore(100, '\n');
		cout << "\n잘못된 입력입니다."
			"\n계속하려면 아무 키나 누르십시오...";
		_getch();
		break;
	}

	return FNRETURN();
}
