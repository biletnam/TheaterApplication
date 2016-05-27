#include "schedule_manager.h"

ScheduleManager::ScheduleManager(DBHelper &dbHelper) : dbHelper(dbHelper)
{
	enum ScheduleManagerFunction
	{
		CHECK_N_DELETE_DATE = 1,
		ADD_DATE,
		CHECK_N_MODIFY_SCHEDULE,
		REGISTER_SCHEDULE,
	};
	
	for (;;) 
	{
		system("cls");
		cout <<
			"���� ���� �ý���\n"
			" > �� ���� ����\n"
			"\n"
			"1. ���� Ȯ��/����\n"
			"2. ���� �߰�\n"
			"3. �� ���� Ȯ��/����\n"
			"4. �� ���� ���\n"
			"0. ����\n"
			"\n"
			"����: ";


		switch (inputInteger())
		{
		case CHECK_N_DELETE_DATE:
			checkAndDeleteDate();
			break;
		case ADD_DATE:
			addDate();
			break;
		case CHECK_N_MODIFY_SCHEDULE:
			checkAndModifySchedule();
			break;
		case REGISTER_SCHEDULE:
			registerSchedule();
			break;
		case FUNCTION_CANCEL:
			return;
		default:
			cout << "\n�߸��� �Է��Դϴ�.";
			system("pause");
		}
	}
}
