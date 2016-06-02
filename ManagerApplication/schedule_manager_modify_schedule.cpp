#include "schedule_manager.h"

void ScheduleManager::modifySchedule(Schedule &schedule)
{
	enum
	{
		DELETE_SCHEDULE = 1,
		CHECK_N_DELETE_PRICE,
		REGISTER_PRICE,
	};

	for (;;)
	{
		system("cls");
		cout <<
			"���� ���� �ý���\n"
			" > �� ���� ����\n"
			"  > �� ���� Ȯ��/����\n"
			"\n"
			"������ �� ����\n";
		schedule.show();

		cout << "\n"
			"1. �� ���� ����\n"
			"2. ���� ���� Ȯ��/����\n"
			"3. ���� ���\n"
			"0. ����\n"
			"\n"
			"����: ";

		int32_t function = 0;
		switch (inputPositiveInteger(function))
		{
		case FUNCTION_CANCEL:
			return;
		case FUNCTION_SUCCESS:
			switch (function)
			{
			case DELETE_SCHEDULE:
				deleteSchedule(schedule);
				return;
			case CHECK_N_DELETE_PRICE:
				checkAndDeletePrice(schedule);
				continue;
			case REGISTER_PRICE:
				registerPrice(schedule);
				continue;
			}
		case FUNCTION_ERROR:
			cout << "\n�߸��� �Է��Դϴ�.\n";
			system("pause");
		}
	}
}
