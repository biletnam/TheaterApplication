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
			"���� ���� �ý���\n"
			" > �� ���� ����\n\n"

			"1. �� ���� Ȯ�� / ����\n"
			"2. ���� �߰�\n"
			"3. ���� ���\n"
			"4. ���� ���\n"
			"0. ����\n\n"

			"����: ";

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
			cout << "\n�߸��� �Է��Դϴ�.";
			system("pause");
			break;
		}
	}
}
