#include "schedule_manager.h"

void ScheduleManager::checkAndDeleteDate()
{
	for (;;)
	{
		system("cls");
		cout <<
			"���� ���� �ý���\n"
			" > �� ���� ����\n"
			"  > ���� Ȯ��/����\n"
			"\n";

		Date date;
		dbHelper.bindCol(MDF_THEATER, BIND_INTEGER, &date.value);

		SQLWCHAR sql[BUFSIZ];
		swprintf_s(sql, L"SELECT date FROM schedule WHERE date>%d;", Date::getToday().value);

		if (SQL_SUCCESS != dbHelper.execute(MDF_THEATER, sql))
		{
			cout << "\n������ �߻��߽��ϴ�(checkSchedule).\n";
			system("pause");
			return;
		}

		for (size_t i = 1;; i++)
		{
			switch (dbHelper.fetch(MDF_THEATER))
			{
			case SQL_SUCCESS:
				cout << i << ". ";
				date.show();
				continue;
			case SQL_NO_DATA:
				if (i == 1)
				{
					cout << "��ϵ� ������ �����ϴ�\n";
				}
				else
				{
					cout << "0. ����\n";
					switch (dbHelper.moveCursor(MDF_THEATER, "\n������ ������ �����ϼ���: "))
					{
					case FUNCTION_ERROR:
						cout << "\n������ �߻��߽��ϴ�(checkSchedule).\n";
						system("pause");
					case FUNCTION_CANCEL:
						return;
					case FUNCTION_SUCCESS:
						cout << "\n�����Ǿ����ϴ�.\n";
						system("pause");
					}
				}
			}
			break;
		}
	}
}