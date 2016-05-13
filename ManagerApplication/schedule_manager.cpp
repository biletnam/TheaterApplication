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
			"���� ���� �ý���\n"
			" > �� ���� ����\n\n"

			"1. ���� Ȯ�� / ����\n"
			"2. ���� �߰�\n"
			"3. ���� ���\n"
			"4. ���� ���\n"
			"0. ����\n\n"

			"����: ";

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
			cout << "\n�߸��� �Է��Դϴ�."
				"\n����Ϸ��� �ƹ� Ű�� �����ʽÿ�...";
			_getch();
			break;
		}
	}
}
