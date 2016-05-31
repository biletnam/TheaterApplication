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

		if (0 < date.getValue())
		{
			cout << "\n������ ��¥ ����:\n";
			date.show();
			switch (date.modify(MODIFY_DELETE))
			{
			case FUNCTION_SUCCESS:
			case FUNCTION_CANCEL:
				date.initialize();
			}
		}
		else
		{
			Date::getToday().bindParameter();
			if (SQL_SUCCESS != date.prepare(L"SELECT date FROM schedule WHERE date>?;"))
			{
				cout << "\n������ �߻��߽��ϴ�(checkSchedule).\n";
				system("pause");
				return;
			}

			date.bindCol();
			switch (date.choose())
			{
			case FUNCTION_CANCEL:
				return;
			case FUNCTION_NULL:
				cout << "��ϵ� �� �������� �����ϴ�\n";
				system("pause");
			}
		}
	}
}