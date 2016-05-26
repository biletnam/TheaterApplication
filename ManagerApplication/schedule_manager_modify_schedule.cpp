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
		schedule.showInfo();

		cout << "\n"
			"1. �� ���� ����\n"
			"2. ���� ���� Ȯ��/����\n"
			"3. ���� ���\n"
			"0. ����\n"
			"\n"
			"����: ";

		switch (inputInteger())
		{
		case DELETE_SCHEDULE:
			schedule.del();
		case CHECK_N_DELETE_PRICE:
			checkAndDeletePrice(schedule);
			break;
		case REGISTER_PRICE:
			registerPrice(schedule);
			break;
		case FUNCTION_CANCEL:
			return;
		default:
			cout << "\n�߸��� �Է��Դϴ�.\n";
			system("pause");
		}
	}
}
