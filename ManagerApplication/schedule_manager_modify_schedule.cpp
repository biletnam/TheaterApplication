#include "schedule_manager.h"

void ScheduleManager::modifySchedule(Schedule &schedule)
{
	enum
	{
		DELETE_SCHEDULE = 1,
		DELETE_PRICE = 2,
		REGISTER_PRICE = 3,
	};

	for (;;)
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

		switch (inputInteger())
		{
		case DELETE_SCHEDULE:
			schedule.del();
		case FUNCTION_CANCEL:
			return;
		case DELETE_PRICE:
			deletePrice(schedule);
			break;
		case REGISTER_PRICE:
			registerPrice(schedule);
			break;
		default:
			cout << "\n�߸��� �Է��Դϴ�.\n";
			system("pause");
		}
	}
}
