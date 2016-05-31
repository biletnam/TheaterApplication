#include "schedule_manager.h"

void ScheduleManager::addDate()
{
	Date date;
	for (;;)
	{
		system("cls");
		cout <<
			"���� ���� �ý���\n"
			" > �� ���� ����\n"
			"  > ���� �߰�\n";

		if (0 != date.getValue())
		{
			cout << "\n�߰��� ��¥ ����: \n";
			date.show();
		}

		if (0 != date.get(DATE_YEAR)
			&& 0 != date.get(DATE_MONTH)
			&& 0 != date.get(DATE_DAY))
		{
			switch (date.modify(MODIFY_INSERT))
			{
			case FUNCTION_SUCCESS:
			case FUNCTION_CANCEL:
				date.initialize();
			}
		}
		else if (FUNCTION_CANCEL == date.input())
		{
			return;
		}
	}
}