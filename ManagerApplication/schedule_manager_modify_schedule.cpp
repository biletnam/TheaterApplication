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
		"���� ���� �ý���\n"
		" > �� ���� ����\n"
		"  > �� ���� Ȯ��/����\n\n"
		
		"������ �� ����\n";
	schedule.showInfo();
	
	cout << "\n"
		"1. �� ���� ����\n"
		"2. ���� ���� Ȯ��/����\n"
		"3. ���� ���\n"
		"0. ����\n\n"

		"����: ";

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
		cout << "\n�߸��� �Է��Դϴ�.\n";
		system("pause");
	}

	return FUNCTION_ERROR;
}
