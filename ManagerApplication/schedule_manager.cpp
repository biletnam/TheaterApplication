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
			"�� ���� ����\n"
			"Ȯ��(1), ���� �߰�(2), ���� ���(3), ���� ���(4), ���� ����(5), ����(0): ";
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
			cout << "\n�߸��� �Է��Դϴ�."
				"\n����Ϸ��� �ƹ� Ű�� �����ʽÿ�...";
			_getch();
			break;
		}
	}
}
