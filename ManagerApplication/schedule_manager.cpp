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

		int8_t function = 0;
		switch (inputPositiveInteger(function))
		{
		case FUNCTION_CANCEL:
			return;
		case FUNCTION_SUCCESS:
			switch (function)
			{
			case CHECK_N_DELETE_DATE:
				checkAndDeleteDate();
				continue;
			case ADD_DATE:
				addDate();
				continue;
			case CHECK_N_MODIFY_SCHEDULE:
				checkAndModifySchedule();
				continue;
			case REGISTER_SCHEDULE:
				registerSchedule();
				continue;
			}
		case FUNCTION_ERROR:
			cout << "\n�߸��� �Է��Դϴ�.";
			system("pause");
		}
	}
}
