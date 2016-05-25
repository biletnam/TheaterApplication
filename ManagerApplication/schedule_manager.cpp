#include "schedule_manager.h"

ScheduleManager::ScheduleManager(DBHelper &dbHelper) : dbHelper(dbHelper)
{
	enum ScheduleManagerFunction
	{
		CHECK_SCHEDULE = 1,
		ADD_DATE,
		REGISTER_SCHEDULE,
		REGISTER_PRICE,
	};
	
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


		switch (inputInteger())
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
			cout << "\n�߸��� �Է��Դϴ�.";
			system("pause");
		}
	}
}
