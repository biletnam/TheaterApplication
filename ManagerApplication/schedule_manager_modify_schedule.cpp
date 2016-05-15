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
		"���� ���� �ý���\n"
		" > �� ���� ����\n"
		"  > �� ���� Ȯ�� / ����\n\n"
		
		"������ �� ����\n";
	schedule.showInfo();
	
	cout << "\n"
		"1. �� ���� ����\n"
		"2. ���� ���� ����\n"
		"0. ����\n";

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
		cout << "\n�߸��� �Է��Դϴ�."
			"\n����Ϸ��� �ƹ� Ű�� �����ʽÿ�...";
		_getch();
		break;
	}

	return FNRETURN();
}
