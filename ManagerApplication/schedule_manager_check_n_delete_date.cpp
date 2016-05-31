#include "schedule_manager.h"

void ScheduleManager::checkAndDeleteDate()
{
	Date date;

	for (;;)
	{
		system("cls");
		cout <<
			"���� ���� �ý���\n"
			" > �� ���� ����\n"
			"  > ���� Ȯ��/����\n";

		if (0 != date.getValue())
		{
			date.modify(MODIFY_DELETE);
		}
		else
		{
			Date::getToday().bindParameter();
			if (SQL_SUCCESS != date.prepare(MDF_THEATER, L"SELECT date FROM schedule WHERE date>?;"))
			{
				cout << "\n������ �߻��߽��ϴ�(checkSchedule).\n";
				system("pause");
				return;
			}

			date.bindCol();
			switch (date.choose(MDF_THEATER))
			{
			case FUNCTION_NULL:
				cout << "��ϵ� �� �������� �����ϴ�\n";
				system("pause");
			case FUNCTION_CANCEL:
				return;
			case FUNCTION_ERROR:
				date.setValue(0);
			}
		}
	}
}